

/*
 *	 Linked list problems 
 *	Authour : Livin Sunny
 */




#include <stdio.h>
#include <stdlib.h>

//#define debug 


typedef struct node{
	
	int data;
    struct node *next;

}node_t;

static i;

node_t* push(node_t **head,int new_data);
node_t* mergesort(node_t **head );
void print(node_t **head);
void reverse(node_t **head);
void FrontBackSplitt(node_t *,node_t ** ,node_t**);

/**
 * Reverse the Linked list
 *
 */


void reverse(node_t **head){

	node_t *current=*head;
	node_t *prev = NULL;
	node_t *next;

	while (current != NULL)
	{
		next=current->next;
		current->next=prev;
		prev = current;
		current = next;
	}

	*head=prev;
} 

/**
 * Recursive Reverse the Linked list
 *
 */

void rec_reverse(node_t **head){

	node_t *first= *head;
	node_t *rest = first-> next;

	//Check if the node has only 1 node 

	if(rest == NULL)
		return ;
	
#ifdef debug
	printf("Recursive call : %d \n",i++);
#endif

	//Recursive call 
	rec_reverse(&rest);

	//Put the element at th end

	first->next->next= first;

	//tricky step
	first->next = NULL;

	*head = rest; 

}

//TODO
//Divide and conquer method
node_t* 
mergesort(node_t **head )
{
	node_t *tmp_head=*head;
	node_t *a;
	node_t *b;

	//Check for 1 element or empty list
	if (tmp_head==NULL || tmp_head->next)
		{
			return;
		}	
	FrontBackSplitt(tmp_head,&a,&b);

}

void FrontBackSplitt(node_t *source , node_t **front,node_t **back){
	return;
}




node_t* 
push(node_t **head,int new_data)
{
	node_t *new_node = (node_t*)malloc(sizeof(node_t));
	new_node->data=new_data;
	new_node->next=*head;
	*head=new_node;

#ifdef debug	
	printf("Data created : %d\n",new_node->data);
#endif	

}

void 
print(node_t **head){

	node_t *temp=*head;

#ifdef debug
	if(temp==NULL)
		printf("No head\n");
	else
		printf("Head present\n");
#endif	

	while(temp!=NULL)
	{

		printf("%d\t -> ",temp->data);
		temp=temp->next;

	}

}



int main(){

	node_t *h=NULL;

	push(&h,21);
	push(&h,23);
	push(&h,25);
	push(&h,27);
	push(&h,30);
	
	print(&h);
	printf("After Reversal : \n");
	reverse(&h);
	print(&h);

	printf("After Recursive reverse :\n");
	rec_reverse(&h);
	print(&h);


}

