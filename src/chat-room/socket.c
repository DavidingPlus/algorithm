#include<sys/socket.h>
#include<netinet/ether.h>
#include<arpa/inet.h>
#include<stdio.h>
int main()
{

    int sock=socket(AF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
    unsigned char msg[1600]={0};
    while(1)
    {
        if(recv(sock,msg,1600,0)<0)
        {
            printf("recv error!\n");
            return -1;
        }
      
        unsigned char dest_mac[18]={0};
        sprintf(dest_mac,"%x:%x:%x:%x:%x:%x",msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
        unsigned char src_mac[18]={0};
        sprintf(dest_mac,"%x:%x:%x:%x:%x:%x",msg[6],msg[7],msg[8],msg[9],msg[10],msg[11]);
        printf("src:%s-->dest:%s\n",src_mac,dest_mac);
        
        
        unsigned char dest_ip[18]={0};
        sprintf(dest_ip,"%u.%u.%u.%u",msg[28],msg[29],msg[30],msg[31]);

        unsigned char src_ip[18]={0};
        sprintf(src_ip,"%u.%u.%u.%u",msg[38],msg[39],msg[40],msg[41]);
        printf("src ip:%s-->dest ip:%s\n",src_ip,dest_ip);
    }
    return 0;
}