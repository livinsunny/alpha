




#include<stdio.h>
char ip[30]="000.000.000.000";
void main()
{
	int x=0x0a030004,i,j;
	unsigned char *p=(char *)&x;
	for(j=3,i=0;i<4;i++,j--)
	{
		convert(p[j],i);
	}

	printf("ip-%s\n",ip);
}

convert(int x,int i)
{
	i=i*4;
	ip[i+0]=(x/100)+'0';
	ip[i+1]=((x%100)/10)+'0';
	ip[i+2]=(x%10)+'0';
}

