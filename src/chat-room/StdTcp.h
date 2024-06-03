#ifndef _STDTCP_H_
#define _STDTCP_H_
#include<stddef.h>
struct TcpServe;
typedef struct TcpServe TcpS;

TcpS *InitTcpServer(const char *ip,short int port);
int TcpServerAccept(TcpS *s);
void TcpServerSend(int Clientsock,void *ptr,size_t size);
void TcpServerRecv(int Clientsock,void *ptr,size_t size);
void ClearTcpServer(TcpS *s);


struct TcpClient;
typedef struct TcpClient TcpC;
TcpC *InitTcpClient(const char *iServerp,short int Serverport);
void TcpClientSend(TcpC* c,void *ptr,size_t size);
void TcpClientRecv(TcpC* c,void *ptr,size_t size);
void ClearTcpClient(TcpC *c);
#endif