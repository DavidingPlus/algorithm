#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#include"StdThread.h"
#include"DoubleLinkList.h"
#include"ThreadPool.h"
#include"LinkQueue.h"

#define Sleep_Time 10
#define true 1
#define false 0
typedef  void* (*function)(void*);
struct ThreadTask
{
   function func;
   void *arg;

};
typedef struct ThreadTask task;
task* CreateTask(function func,void *arg)
{
    task *t=(task*)malloc(sizeof(task));
    if(t==NULL)
    {
        printf("CreateTask malloc error!\n");
        return NULL;
    }
    t->func=func;
    t->arg=arg;
}
void FreeTask(task *t)
{
    free(t);
}
struct ThreadPool
{
    DLlist threads;  
    LQueue tack_queue;

    int max_thrd_num;
    int min_thrd_num;
    int max_queue_size;
    int busy_thrd_num;
    int waitKillthread;
    
    pthread_mutex_t busy_num_mutex;
    pthread_mutex_t pool_mutex;
    pthread_cond_t queue_not_empty;
    pthread_cond_t queue_not_full;

    int shutdown;    //关掉线程池的开关

    thread* admin_thread; //管理员线程
};
void* thread_work(void *arg)
{    
    ThreadP *p=(ThreadP*)arg;
    while(1)
    {    
        
        pthread_mutex_lock(&p->pool_mutex);
        while(IsQEmpty(&p->tack_queue)==true&&p->shutdown!=true)
        {
           pthread_cond_wait(&p->queue_not_empty,&p->pool_mutex);
           if(p->waitKillthread>0)
           //kill itself
           if(p->busy_thrd_num*2<GetListLen(&p->threads)&&GetListLen(&p->threads)>p->min_thrd_num)
           {
            struct Node* TravelPoint=p->threads.head;
            while(TravelPoint!=NULL)
            {
                thread* t=(thread*)TravelPoint->data;
                if(GetThreadId(t)==pthread_self())
                    {
                    RemoveByElement(&p->threads,t);
                    break;
                    }
                TravelPoint=TravelPoint->next;
            }
            pthread_exit(NULL);
           }
        }
        if(p->shutdown==true)
        {
            pthread_mutex_unlock(&p->pool_mutex);
            pthread_exit(NULL);
        }
        task* mission=(task*)(*(QPop(&p->tack_queue)));
        pthread_cond_broadcast(&p->queue_not_full);        
        pthread_mutex_unlock(&p->pool_mutex);

        pthread_mutex_lock(&p->busy_num_mutex);
        p->busy_thrd_num++;
        pthread_mutex_unlock(&p->busy_num_mutex);

        mission->func(mission->arg);
        
        pthread_mutex_lock(&p->busy_num_mutex);
        p->busy_thrd_num--;
        pthread_mutex_unlock(&p->busy_num_mutex);
    }
}

void* thread_manmager(void *arg)
{
   ThreadP *p=(ThreadP*)arg;
   while(p->shutdown!=true)
   {
      sleep(Sleep_Time);
      pthread_mutex_lock(&p->pool_mutex);
      if(GetQueueLen(&p->tack_queue)>p->busy_thrd_num
         &&GetListLen(&p->threads)<p->max_thrd_num)
         {
            int addnum=(GetQueueLen(&p->tack_queue)-p->busy_thrd_num)/2;
            for(int i=0;i<addnum;i++)
            {
                thread* t=InitThread(thread_work,p);
                InsertTail(&p->threads,t);
            }
         }
         int busythrd=p->busy_thrd_num;
         int threadLen=GetListLen(&p->threads);
         p->waitKillthread=((threadLen-busythrd)/2)>(threadLen-p->min_thrd_num)?(threadLen-p->min_thrd_num):((threadLen-busythrd)/2);
         int minusNum=p->waitKillthread;
         pthread_mutex_unlock(&p->pool_mutex);
         if(busythrd*2<threadLen
            &&threadLen>p->min_thrd_num)
            {

               for(int i=0;i<minusNum;i++)
               {
                pthread_cond_broadcast(&p->queue_not_empty);
               }
            }
            
   }
   pthread_mutex_unlock(&p->pool_mutex);
   pthread_exit(NULL);
}
ThreadP *InitThreadPool(int max_thrd_num, int min_thrd_num, int max_queue_size)
{
    ThreadP *p=(ThreadP*)malloc(sizeof(ThreadP));
    if(p==NULL)
    {
        printf("InitThreadPool malloc error!\n");
        return NULL;
    }
    InitDLinkList(&p->threads);
    InitLQueue(&p->tack_queue);

    p->max_thrd_num=max_thrd_num;
    p->min_thrd_num=min_thrd_num;
    p->max_queue_size=max_queue_size;
    p->waitKillthread=0;
    p->busy_thrd_num=0;

    pthread_mutex_init(&p->pool_mutex,NULL);
    pthread_mutex_init(&p->busy_num_mutex,NULL);
    pthread_cond_init(&p->queue_not_empty,NULL);
    pthread_cond_init(&p->queue_not_full,NULL);
    for(int i=0;i<max_thrd_num;i++)
    {
       thread* t=InitThread(thread_work,p);
       InsertTail(&p->threads,t);
       
    }
    p->admin_thread=InitThread(thread_manmager,p);
    return p;
}

void ThreadP_AddTask(ThreadP *p, void *(*func)(void *), void *arg)
{
    pthread_mutex_lock(&p->pool_mutex);
    while(GetQueueLen(&p->tack_queue)==p->max_queue_size&&p->shutdown!=true)
    {
        pthread_cond_wait(&p->queue_not_full,&p->pool_mutex);
    }
    if(p->shutdown==true)
    {
        pthread_mutex_unlock(&p->pool_mutex);
        return ;
    }
    QPush(&p->tack_queue,CreateTask(func,arg));
    pthread_cond_broadcast(&p->queue_not_empty);
    pthread_mutex_unlock(&p->pool_mutex);
}

void DestoryThreadPool(ThreadP *p)
{
    if(p==NULL)
    {
        return;
    }
    p->shutdown=true;

    JoinThread(p->admin_thread);
    int len=GetListLen(&p->threads);
    for(int i=0;i<len;i++)
    {
        pthread_cond_broadcast(&p->queue_not_empty);
    }
    struct Node* TravelPoint=p->threads.head;
    while(TravelPoint!=NULL)
    {
        thread *t=(thread*)TravelPoint->data;
        JoinThread(t);
        free(t);
        TravelPoint=TravelPoint->next;
    }
    FreeDLinkList(&p->threads);
    while(IsQEmpty(&p->tack_queue)!=true)
    {
      void* task=QPop(&p->tack_queue);
      free(task);

    }
    FreeLQueue(&p->tack_queue);
    pthread_mutex_destroy(&p->pool_mutex);
    pthread_mutex_destroy(&p->busy_num_mutex);

    pthread_cond_destroy(&p->queue_not_full);
    pthread_cond_destroy(&p->queue_not_empty);

    free(p);
    
}
