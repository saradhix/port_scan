/* tcpclient.c */
/*Skeleton for tcpclient*/
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[])
{

	int sock;
	struct hostent *host;
	struct sockaddr_in server_addr;  
	int i;
	int start, end;
	if(argc!=4)
	{
		printf("Usage: %s <ipaddress> <port_start> <port_end>\n", argv[0]);
		exit(1);
	}
	start=atoi(argv[2]);
	end=atoi(argv[3]);
	printf("start=%d end=%d\n",start, end);



	host = gethostbyname(argv[1]);

	server_addr.sin_family = AF_INET;     
	server_addr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(server_addr.sin_zero),8); 
	for(i=start;i<=end;i++)
	{
		if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
			perror("Socket");
			exit(1);
		}

		//printf("Trying port %d\n", i);
		server_addr.sin_port = htons(i);   

		if (connect(sock, (struct sockaddr *)&server_addr,
					sizeof(struct sockaddr)) == -1) 
		{
		}
		else
		{
			printf("TCP port %d open\n",i);
		}
		close(sock);
		//sleep(2);

	}
	return 0;
}
