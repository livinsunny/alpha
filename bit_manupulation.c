
#include<stdio.h>
#define MASK(x) 1<<(x-1)


int set_bit(int n,unsigned char pos){

	int mask=MASK(pos);
	return n|mask;

}
int clear_bit(int n,unsigned char pos){
	int mask=MASK(pos);
	return n&~mask;
}
int modify_bit(int n,unsigned char pos,_Bool new_state){
	int mask=MASK(pos);
	return (n&~mask)|(-new_state&mask);
}

int isBitset(int n,unsigned int pos)
{
    int mask=MASK(pos);
	return (mask & n)!=0;
}

int main()
{
	int number,pos;
	char ops;	
	int state;
	printf("Enter the Number : ");
	scanf("%d",&number);
	
	printf("\nEnter your choice :" );
    printf("1.set bit\n2.Modify a bit\n3.Is bit set\n4.Clear bit");
	scanf(" %c",&ops);

	printf("\nEnter the position :" );
	scanf(" %d",&pos);

	switch(ops){

		case '1' :
				printf("Inside 1\n");
			    printf("After Modification : %d \n",set_bit(number,pos));
			break;
		case '2' : 	printf("Inside 2\n");
				printf("\nEnter the new state :" );
				scanf("%d",&state);
				printf("After Modification : %d\n",modify_bit(number,pos,state));

			break;
		case '3' :
				printf("inside 3\n");	
				printf("number %x \n",number);
				printf((isBitset(number,pos))?"SET\n":"NOT SET\n");
			break;

		case '4' :	return clear_bit(number,pos);
			break;

		default:
			printf("Invalid\n");
	}
	return 0;
}
