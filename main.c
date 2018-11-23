#include "connectsock.c"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void TCPdaytime(const char *host,const char *service);
#define LINELEN 128

int main(int argc,char *argv[])
{
    char *host="time-a.nist.gov";
    char *service="daytime";

    switch(argc){
        case 1:
            host="time-a.nist.gov";
            break;
        case 3:
            service=argv[2];
        case 2:
            host=argv[1];
            break;
        default:
            fprintf(stderr,"usage: TCPdaytime [host [port]]\n");
            exit(1);
    }
    TCPdaytime(host,service);
    return 0;
}


void TCPdaytime(const char *host,const char *service)
{
    char buf[LINELEN+1];
    int s,n;

    s=connectTCP(host,service);

    while((n=read(s,buf,LINELEN))>0){
        buf[n]='\0';
        (void)fputs(buf,stdout);
    }
}