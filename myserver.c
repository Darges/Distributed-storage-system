#include<stdio.h>
#include<arpa/inet.h>/*internetsocket*/
#include<string.h>
#define NDEBUG
#include<assert.h>
#define PORT 5001
#define IP_ADDR "127.0.0.1"
#define MAX_CONNECT_QUEUE 1024
#define MAX_BUF_LEN 1024
int main()
{
    int sockfd=-1;
    char buf[MAX_BUF_LEN];
    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len=sizeof(struct sockaddr_in);
    struct sockaddr_in addr;
    addr.sin_family=AF_INET;
    addr.sin_port=htons(PORT);
    addr.sin_addr.s_addr=inet_addr(IP_ADDR);
    memset(&addr.sin_zero,0,8);
    sockfd=socket(PF_INET,SOCK_STREAM,0);
    assert((sockfd!=-1));
    int ret=bind(sockfd,(struct sockaddr*)&addr,sizeof(struct sockaddr));
    if(ret==-1)
    {
        fprintf(stderr,"BindError,%s:%d,",__FILE__,__LINE__);
		fprintf(stderr,"%s:%d\n",(char*)inet_ntoa(addr.sin_addr),ntohs(addr.sin_port));
		close(sockfd);
		return-1;
    }	
	ret=listen(sockfd,MAX_CONNECT_QUEUE);
	assert((ret==0));
	while(1)
	{
		int newfd=accept(sockfd,(struct sockaddr*)&clientaddr,&clientaddr_len);
		if(newfd==-1)
		{
			fprintf(stderr,"AcceptError,%s:%d\n",__FILE__,__LINE__);
		}
		else
		{
			ret=recv(newfd,buf,MAX_BUF_LEN,0);
			if(ret>0)
			{
				printf("recv \"%s\" from%s:%d\n",buf,(char*)inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
			}	
			ret=send(newfd,"hi",sizeof("hi"),0);
			if(ret>0)
			{
				printf("rely \"hi\" to%s:%d\n",(char*)inet_ntoa(clientaddr.sin_addr),ntohs(clientaddr.sin_port));
			}
			close(newfd);
		}
	}
	close(sockfd);
	return 0;
}
