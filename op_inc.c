


#include<stdio.h>


int main()
{
    int a[10]={20,30,40,50,60,70,80,90};
    int *ptr=a;
    int i;

    for(i=0;i<11;i++)
        printf("%d \n",a[i]);
      printf("%d\n ",*ptr++);
      printf("%d\n ",*++ptr);
      printf("%d\n ",++*ptr);
      printf("%d\n ",(*ptr)++);
      printf("%d\n ",*ptr);
}

