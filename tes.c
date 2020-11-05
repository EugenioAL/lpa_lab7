#include <stdio.h>
#include <WinSock2.h>
#include <winsock.h>
#include <windows.h>

int main(){
    u_long a = 218103808;
    printf("NUMERO : %d", ntohl(a));
}