/*
 * Copyright (C) 2016  Livin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

//#define debug 

typedef struct node{
	
    int data;
    struct node *next;

}node_t;

node_t* push(node_t **head,int new_data);
node_t* mergesort(node_t **head );
void print(node_t **head);
void reverse(node_t **head);
void FrontBackSplitt(node_t *,node_t ** ,node_t**);
void delete_end(node_t **head);
void dup_del(node_t **head);
void del_n_i_node(node_t **head);

/*
 * Reverse the Linked list
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

/*
 * Recursive Reverse the Linked list
 */

void rec_reverse(node_t **head){

    node_t *first= *head;
    node_t *rest = first-> next;

    //Check if the node has only 1 node 

    if(rest == NULL){
	return ;
    }
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

node_t*
push_end(node_t **head , int new_data) {
    node_t *temp = *head;
	
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = new_data;
    if(temp==NULL){
	new_node->data=new_data;
	new_node->next=*head;
	*head=new_node;
	return *head;
    }	
    while(temp->next!=NULL){
	temp=temp->next;
    }

    temp->next= new_node;
    new_node->next = NULL;
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

void
dup_delete(node_t **head){

    node_t *ptr1,*ptr2,*dup;

    ptr1=*head;

    while(ptr1!=NULL && ptr1->next!=NULL)
    {
	ptr2=ptr1;

	while(ptr2->next != NULL){
	    if(ptr1->data == ptr2->next->data)
	    {
		dup = ptr2->next;
		ptr2->next = ptr2->next->next;
		free(dup);
	    }
	    else{
		ptr2=ptr2->next;
	    }
	}
		
	ptr1=ptr1->next;		
    }
}

void
dup_del(node_t **head){

    node_t *p,*q,*prev,*temp;

    p=prev=*head;
    q=p->next;

    while(p!=NULL)
    {
	while(q!=NULL && q->data != p->data){
	    prev=q;
	    q=q->next;
	}
	if (q==NULL)
	{
	    p=p->next;
	    if (p!=NULL)
	    {
		q=p->next;
	    }
	}
	else if (q->data == p->data)
	{
	    prev->next = q->next;
	    temp = q;
	    q=q->next;
	    free(temp);		
	}
    }
}

void
del_n_i_node(node_t **head)
{
    node_t *temp=NULL;
    node_t *slow =*head;
    node_t *fast = *head;
    short i=0;
    
    //Here 4 is the ith value
    while(i<4)
    {
	fast=fast->next;
	i++;
    }
    while (fast!=NULL){
		
	fast=fast->next;
	temp=slow;
	slow=slow->next;
    }

    temp->next=slow->next;
    printf("Deleting node  : %d\n",slow->data);
    free(slow);

}

int main(){
    
    node_t *h=NULL;
    uint ch=0;
    push_end(&h,21);
    push_end(&h,22);
    push_end(&h,23);
    push_end(&h,20);
    push_end(&h,7);
    push_end(&h,19);
    push_end(&h,24);
    push_end(&h,11);
    printf("1.Delete ith node\n 2.Reverse \n 3.Recursive Rev \n 4.Delete 5.Print \n 6.Dupe Delete \n");
    do
    {
	printf("Enter your choice\n");
	scanf("%d",&ch);
	if(!ch){
	    break;
	}    
	__fpurge(stdin);
		
	switch(ch) {
	    case 1 : {
		printf("Delete ith node \n");
		del_n_i_node(&h);
		break;
	    }
	    case 2 : {
		printf("Reverse\n");
		reverse(&h);
		break;
	    }
	    case 3: {
		printf("recursuve reverse \n");
		rec_reverse(&h);
		break;
	    }
	    case 4 : {
		printf("Delete node \n");
		delete_end(&h);
		break;
	    }
	    case 5:{
		print(&h);
		break;
	    }
		
	    
	    case 6: {
		printf("Dup Del\n");
		
		break;
	    }
	    default :
		printf("Error !! \n");
	}
				
    } while (ch!=0);
}

