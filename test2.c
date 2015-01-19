


#include <stdio.h>

int main(int argc, char const *argv[])
{
	/*
	 *for finding the endianess of the system
	 */
	//---------------------------------------------------------------
	#if 0
	int i=1;
	char *c= (char*)&i;
	if(*c)
	{
		printf("Little Endian \n");
	}
	else 
		printf("Big Endian\n");
	#endif
	//--------------------------End of endianess---------------------
	
	//printf("a %x b %x \n",a,b );

	unsigned int n[]={30,40,50,60,70,80};

	int *p=n;
	//*p = 13 ;
	printf("*p++ %d\n",*p++);	//If you comment out it throws error  when [ int *const p =&n ] ; Here ++ is on the RHS so increament happens after PF 
	printf("*p %d\n",*p);

}