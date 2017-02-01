



#include<stdio.h>
#include<string.h>

void rev(char str[]);
void rev_ver1(char str[]);
int main(){

	char str[20]={"abcde"};

	//printf("enter the string \n ");
	//scanf("%s",str);


	rev(str);
   
	printf("in main %s \n",str);
	rev_ver1(str);
    printf("in main %s \n",str);

	return 0;

}

void rev_ver1(char str[])
{
    int slen=strlen(str)-1;
    int i=0;
    int tslen=slen;
    for (i=0;i<slen/2;i++)
    {
        str[i]= str[i]+str[tslen];
        str[tslen]=str[i]-str[tslen];
        str[i]=str[i]-str[tslen--];
    }
}


void rev(char str[]){
	
	int i=0;
	for(i=0;str[i]!='\0';i++);	
	int count=0;
	i--;
	printf("%d",i);
	while(count< i)
	{
		str[count]^=str[i];
		str[i]^=str[count];
		str[count]^=str[i];

		count++;
		i--;
	}

/*
 int end= strlen(str)-1;
 int start = 0;
printf("%d",end);
while( start<end )
{
str[start] ^= str[end];
str[end] ^= str[start];
str[start]^= str[end];

++start;
--end;
}
*/
	printf("in fun %s \n",str);
}
