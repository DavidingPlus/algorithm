#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<signal.h>
#include<string.h>
#include"StdTcp.h"
#include"StdThread.h"
// static int sock=0;

// void func(int signal)
// {
//     close(sock);
//     raise(SIGINT);
// }
struct Message
{
    int flag;
    char fromName[20];
    char toName[20];
    char content[1024];
    
};
typedef struct Message Msg;
void *thread_handle(void* arg)
{
   TcpC* c=(TcpC*)arg;
   while(1)
   {
    Msg m;
    TcpClientRecv(c,&m,sizeof(m));
    printf("recv message from [%s],message: %s\n",m.fromName,m.content);
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
    TcpC *c=InitTcpClient(argv[1],atoi(argv[2]));
    Msg m;
    scanf("%s",m.fromName);getchar();
    m.flag=1;
    TcpClientSend(c,&m,sizeof(m)); 

    
    m.flag=2;
    thread* t=InitThread(thread_handle,c);
    DetachThread(t);
    while(1)
    {
        printf("plaese input send name:");
        scanf("%s",m.toName);
        while(getchar()!='\n');
        printf("plaese input send content:");
        scanf("%[^\n]",m.content);
        while(getchar()!='\n');
        TcpClientSend(c,&m,sizeof(m));
    }
    ClearTcpClient(c);
    return 0;
}