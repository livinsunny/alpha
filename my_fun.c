


#include<stdio.h>

int fun(int a ,int b){

	a=a+b;
	b=a-b;
	a=a+b;
}

int main(){
	fun(3,5);
}
