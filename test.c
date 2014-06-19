


#include<stdio.h>

int fun(char s[]){
	printf("%s\n",s);

}

int main ()
{
	char a[]={"livin Sunny"};

	fun(a+3); 
	/*	
	int a[3] = {1,2,3};
	int *p = a;
//p= a+1;
	if(++p == (a+1))

	   printf("p =%x\n",p);
	else
	   printf("a =%x\n",a);
	   */
}



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
