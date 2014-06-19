
#include<stdio.h>

#define CHAR_BIT 8

int main(){
	unsigned int v=0x55; //	0101 0101
	unsigned int r=v;

	int s=sizeof(v)*CHAR_BIT-1;
	for(v=v>>1;v;v=v>>1)
	{
		r<<=1;
		r|=v&1;
		s--;
	}
	r<<=s;
	printf("%x",r);
	return 0;
}


