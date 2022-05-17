/**
 * @file tcp.h
 * @author zk (zk@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-05-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef  __TCP__
#define __TCP__

class NetTcp
{


public:
    NetTcp(/* args */);
    ~NetTcp();
    void Create(char * ipStr,unsigned short localport);
   static  void *Send(void *argv);
    void Recv();
   
public:
 int m_hPeer  ;//peer socket fd
private:
    int m_hSocket; //socket fd
    
    unsigned int m_nLocalAddress;
    unsigned short m_nLocalPort;    
};






#endif 