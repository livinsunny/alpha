


#include <stdio.h>

char **fun1(void);
char **fun2(void);
/*
 *This shows an example of static variable and Why it is required
 * Imapct on Life time
 *
 */



int main(){

 	char **ptr1 = NULL;
    char **ptr2 = NULL;

    ptr1 = fun1();
    printf("\n [%s] \n",*ptr1);

    ptr2 = fun2();
    printf("\n [%s] \n",*ptr2);

    printf("\n [%s] \n",*ptr1);	//Here it prints windows again as the same space is used by the local [pointer]

    return 0;

}


char ** fun1(){

	static char *p = "Linux";
	return &p;
}

char ** fun2(){

	static char *p = "Windows";
	return &p;
}