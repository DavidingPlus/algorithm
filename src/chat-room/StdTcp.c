#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<signal.h>

#include"StdTcp.h"

struct TcpServe
{
   int sock;
};
struct TcpClient
{
  int sock;
};

TcpS *InitTcpServer(const char *ip, short int port)
{    
    TcpS *s=(TcpS*)malloc(sizeof(TcpS));
    s->sock=socket(AF_INET,SOCK_STREAM,0);
    if(s->sock<0)
    {
        perror("socket:");
    }
    int isUse=1;
    if(setsockopt(s->sock,SOL_SOCKET,SO_REUSEADDR,&isUse,4)!=0)
    {
        perror("setsockopt:");
        free(s);
        return NULL;
    }
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr=inet_addr(ip);
    if(bind(s->sock,(struct sockaddr*)&addr,sizeof(addr))!=0)
    {
        perror("bind :");
        free(s);
        return NULL;
    }
    if(listen(s->sock,10)!=0)
    {
        perror("listen:");
        free(s);
        return NULL;
    }
   return s;
}

int TcpServerAccept(TcpS *s)
{
    struct sockaddr_in ClientAddr;
    socklen_t len;
    int acceptSock=accept(s->sock,(struct sockaddr*)&ClientAddr,&len);
    if(acceptSock<0)
    {
        perror("accept:");
        return -1;
    }
   return acceptSock;
}

void TcpServerSend(int Clientsock,void *ptr,size_t size)
{
    if(send(Clientsock,ptr,size,0)<0)
    {
        perror("TcpServerSend:");
        return ;
    }
}

void TcpServerRecv( int Clientsock, void *ptr, size_t size)
{
        if(recv(Clientsock,ptr,size,0)<0)
        {
            perror("TcpServerRecv:");
        }
}

void ClearTcpServer(TcpS *s)
{
    close(s->sock);
    free(s);
}

TcpC *InitTcpClient(const char *Serverip, short int Serverport)
{
    
    TcpC *c=(TcpC*)malloc(sizeof(TcpC));
    if(c==NULL)
    {
        printf("InitTcpClient malloc error\n");
        return NULL;
    }
    c->sock=socket(AF_INET,SOCK_STREAM,0);
    if(c->sock<0)
    {
        perror("socket:");
    }
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(Serverport);
    addr.sin_addr.s_addr=inet_addr(Serverip);
    if(connect(c->sock,(struct sockaddr*)&addr,sizeof(addr))!=0)
    {
        perror("connect");
    }
    return c;
}

void TcpClientSend(TcpC *c, void *ptr, size_t size)
{
    if(send(c->sock,ptr,size,0)<0)
    {
        perror("TcpClientSend:");
        return;
    }
}

void TcpClientRecv(TcpC *c, void *ptr, size_t size)
{
    if(recv(c->sock,ptr,size,0)<0)
    {
    perror("TcpClientRecv");
    }
}

void ClearTcpClient(TcpC *c)
{
    close(c->sock);
    free(c);

}
