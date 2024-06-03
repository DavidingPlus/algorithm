#include"StdTcp.h"
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include"DoubleLinkList.h"
#include<arpa/inet.h>
#include"StdThread.h"
#include<signal.h>
#include<string.h>
#include"ThreadPool.h"
// static int sock=0;
// static int acceptSock=0;
// void func(int signal)
// {
//     close(sock);
//     close(acceptSock);
//     raise(SIGINT);
// }

struct Client
{
    char name[20];
    int sock;

};
typedef struct Client C;
C* createC(const char *name,int sock)
{
    C *c =(C*)malloc(sizeof(C));
    if(c==NULL)
    {
        perror("malloc:");
        return NULL;
    }
    strcpy(c->name,name);
    c->sock=sock;
    return c;
}
void FreeC(C *c)
{
    free(c);
}
DLlist ClientList;

struct Message
{
    int flag;
    char fromName[20];
    char toName[20];
    char content[1024];
    
};
typedef struct Message Msg;


void *thread_handle(void *arg)
{
    int sock=*((int *)arg);
    while(1)
    {
        Msg m;
        TcpServerRecv(sock,&m,sizeof(m));
        printf("flag:  %d \n",m.flag);
        switch(m.flag)
        {
            case 1:
                printf("here\n");
                InsertTail(&ClientList,createC(m.fromName,sock));
                break;
            case 2:
                struct Node* TravelPoint =ClientList.head;
                while(TravelPoint!=NULL)
                {
                    C* c=(C*)TravelPoint->data;
                    if(strcmp(c->name,m.toName)==0)
                    {
                        TcpServerSend(c->sock,&m,sizeof(m));
                        break;
                    }
                    TravelPoint=TravelPoint->next;
                }
            
        default:
            break;
        }
        printf("from socket :%d,message :%s\n",sock,m.content);
    }
}
int main(int argc,char *argv[])
{
    // signal(SIGTSTP,func);
    if(argc!=3)
    {
        printf("invalid numbers!\n");
        return -1;
    }
    ThreadP *p= InitThreadPool(100,10,50);
    if(p==NULL)
    {
        printf("threadpool is error!\n");
        return -1;
    }
    InitDLinkList(&ClientList);
    TcpS* s=InitTcpServer(argv[1],atoi(argv[2]));
    int acceptSock;
    while((acceptSock=TcpServerAccept(s))>0)
    {
        ThreadP_AddTask(p,thread_handle,&acceptSock);
    }

    return 0;
}