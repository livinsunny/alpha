

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
void delete_end(node_t **head);


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

	//Put the element at the end

	first->next->next= first;

	//tricky step
	first->next = NULL;

	*head = rest; 

}
/*
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

	//Recursive merge the 2 lists;
	mergesort(&a);
	mergesort(&a);

	//Merge the 2 list into single 

	*head = sortedMerge(a,b);


}
*/
/*
 * Splitting the node 
 *
 */
void FrontBackSplitt(node_t *source , node_t **front,node_t **back){
	
	//take to pointers slow and fast 

	node_t *slow;
	node_t *fast;

	if (source == NULL && source ->next == NULL){
		//length <2 cases
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source -> next;
		//Advance the fast node 2 times & slow node to 1 time 

		while(fast != NULL){
			fast=fast->next;
			if(fast != NULL){
				slow = slow -> next;
				fast=fast->next;
			}
		}

		//Now slow pointer is just before the mid point of the list 
		*front =source;
		*back = slow -> next;
		slow->next =NULL;

	}

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
	printf("\n");

}
void 
delete_end(node_t **head){

	node_t *temp=*head;
	node_t *prev;


	while(temp->next != NULL){

		prev=temp;
		temp=temp->next;
	}
	printf("Deleting element is %d \n", temp->data);
	free(temp);
	prev->next=NULL;
}


int main(){

	node_t *h=NULL;

	push(&h,21);
	push(&h,23);
	push(&h,25);
	push(&h,7);
	push(&h,30);
	push(&h,11);
	push(&h,26);
	push(&h,3);
	push(&h,50);
	push(&h,30);


	print(&h);
	printf("After Reversal : \n");
	reverse(&h);
	print(&h);

	printf("After Recursive reverse :\n");
	rec_reverse(&h);
	print(&h);
	delete_end(&h);
	delete_end(&h);
	print(&h);


}

