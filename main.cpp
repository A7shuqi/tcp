#include <iostream>
#include"include/NetTcp.h"
//一个小的tcpDome

int main(int, char**) 
{

    NetTcp tc;
    char ip[] = "192.168.29.123";
    tc.Create(ip,9600);
    tc.Recv();

    return 0;
}
