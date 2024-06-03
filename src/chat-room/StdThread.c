#include"StdThread.h"

#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
struct StdThread
{
  pthread_t threadID;

};

thread *InitThread(void *(*func)(void *), void *arg)
{
    thread *t =(thread*)malloc(sizeof(thread));
    if(t==NULL)
    {
        printf("InitThread malloc error!\n");
        return NULL;
    }
   if (pthread_create(&t->threadID,NULL,func,arg)==0)
   {
    return t;
   }
   else
   {
    printf("create pthread error!\n");
    return NULL;
   }

}

unsigned long int GetThreadId(thread *t)
{
   return t->threadID;
}

void ClodeThread(thread *t)
{
    if(pthread_cancel(t->threadID)==0)
    {
        free(t);
    }
    else
    {
        printf("close thread error!\n");
    }
}

void* JoinThread(thread *t)
{
    void *value;
    pthread_join(t->threadID,&value);
    return value;
}

void DetachThread(thread *t)
{
    if(pthread_detach(t->threadID)!=0)
    {
        printf("DetachTread error!\n");
    }

}
