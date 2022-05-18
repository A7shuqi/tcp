#include"NetTcp.h"
#include <sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<string.h>

NetTcp::NetTcp(/* args */) 
{
    m_hSocket = -1 ;
     m_nLocalAddress = 0;
     m_nLocalPort = 0;
  
}
 
NetTcp::~NetTcp()
{
    
}

/**
 * @brief 
 * 
 * @param ipStr 
 * @param localport 
 */
void NetTcp::Create(char * ipStr,unsigned short localport)
{   
    m_hSocket = socket(AF_INET,SOCK_STREAM,0); //Create TPC mode IPv4 flow

   struct sockaddr_in local;
   local.sin_family = AF_INET;
   local.sin_port = htons(9600);
   local.sin_addr.s_addr = inet_addr("172.17.0.1");
   
    if(bind(m_hSocket,(struct sockaddr*)&local,sizeof(local)) == -1)
    {
        perror("bind error");
    }

    if(listen(m_hSocket,10) == -1)
    {
        perror("listen error");
    }

}


 void  NetTcp::Recv()
 {
        struct sockaddr_in peer;
        socklen_t len =sizeof(peer);
        while (1)
        {
            m_hPeer = accept(m_hSocket,(struct sockaddr*)&peer,&len);
            printf("get connect,ip is : %s port is : %d\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port));
            pthread_t tid ;
            pthread_create(&tid,NULL,Send,this);
            pthread_detach(tid);
        }
        close(m_hPeer);
        close(m_hSocket);
 }

void* NetTcp::Send(void * argv)
{
    NetTcp* temp =(NetTcp*)argv;
    
    printf("creat a new thread\n");
    char buf[1024];

    while(1){
        memset(buf,'\0',sizeof(buf));
        ssize_t _s = read(temp->m_hPeer,buf,sizeof(buf) - 1);
        if(_s > 0){
            buf[_s] = '\0';
            printf("client say : %s\n",buf);
        }    
        memset(buf,'\0',sizeof(buf));
        printf("please Enter: ");
        fflush(stdout);
        ssize_t _s2 = read(0,buf,sizeof(buf) - 1);
        if(_s2 > 0){
            write(temp->m_hPeer,buf,strlen(buf));
        }
    }



}