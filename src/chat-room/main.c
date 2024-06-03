#include<unistd.h>
#include<stdio.h>

#include"ThreadPool.h"
void *task(void* arg)
{
    int num=*(int *)arg;
    printf("this is pthread %d\n",num);
    sleep(1);
}

int main()
{
   ThreadP *p=InitThreadPool(30,10,30);

   int a[50]={0};
   for(int i=0;i<50;i++)
   {
    a[i]=i;
    ThreadP_AddTask(p,task,(void*)&a[i]);

   }
   sleep(1);
   DestoryThreadPool(p);

}