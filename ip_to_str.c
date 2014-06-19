


#include <arpa/inet.h>
#include<stdio.h>

struct in_addr addr;

int main(){

	addr.s_addr = htonl(0x0a010203); 

	char *s = inet_ntoa(addr); // --> "10.1.2.3"


	printf("%s \n",s);

}
