#include <iostream>
#include"include/NetTcp.h"


int main(int, char**) 
{

    NetTcp tc;
    char ip[] = "192.168.29.123";
    tc.Create(ip,9600);
    tc.Recv();

    return 0;
}
