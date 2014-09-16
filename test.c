


#include <stdio.h>


#define N (sizeof(int)/sizeof(s[0]))
//#define MIN(a,b) ((a) <= (b) ? a : b )
 

int afun(char s[]);

int afun(char s[]){
	printf("Here in afun\n");
	printf("%s\n",s);
	return 0;
}
int fun(char s[]){

	int i=1;
	char *c=&i;
	if (*c)
	{
		printf("Little\n");
	}
	else
		printf("Big End\n");
	printf("Im in Fun\n");
	printf("%s\n",s);
	return 0;
}

struct tree
{
	char *name;
	int (*funcptr)(char *);
}node[2]={
	{"fun",fun},
	{"afun",afun},
};


int main ()
{
	char s[]={"abcd"};
	//struct tree *p =NULL;
	(node)->funcptr(s);

	/*
	char s[]={"abcd"};
	//int b[]={10,34};
	char *const p= s;
	fun(p);
	*/
	//printf("%d = \n",MIN(*p++,*b));
	//printf("%c\n",*p++);
//	*(p+1)='t';
	//printf("%c\n",p);
	//printf("%s\n",p);
	//printf("%d\n",N );
	//*p++='c';
		//printf("b=%d  \n",*b);
		//printf("p= %d \n",*p++);
		//printf("%d = \n",*p++);
		return 0;
	
}


	//char a[]={"livin Sunny"};

	//fun(a+3); 
	/*	
	int a[3] = {1,2,3};
	int *p = a;
//p= a+1;
	if(++p == (a+1))

	   printf("p =%x\n",p);
	else
	   printf("a =%x\n",a);
	   */




/*
int main()
{


	int a = 5;
	void* p = &a;
	int *p2= (int *)p;
	printf("%d", *p2 );

	return 0;


}

*/
