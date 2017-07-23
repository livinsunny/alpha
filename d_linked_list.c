


/*
 * d_linked_list.c
 *
 * Copyright (C) 2014 - SuperUser
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */


/*
 *	For Doubly linked list 
 *
 */


#include <stdio.h>
#include<stdlib.h>

typedef struct node
 {
 	int data;
 	struct node* next;
 	struct node* prev;
 	
 }node_t;

void push(node_t **head, int newdata)
{
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data=newdata;
	
	newnode->next=*head;
	newnode->prev=NULL;

	if(*head != NULL)
	{
		(*head)->prev=newnode;
	}
	
	*head=newnode;
}

void insert_end(node_t **head, int newdata)
{
	node_t *temp=*head;
	node_t *newnode = (node_t*)malloc(sizeof(node_t));
	newnode->data=newdata;
	
	newnode->next=NULL;

	if(temp == NULL)
	{
		newnode->prev=NULL;
		*head=newnode;
		return;
	}
	
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}

void print(node_t **head)
{
	node_t *temp=*head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}
}

int main()
{
	node_t *head=NULL;
	//Create a the DLL
	push(&head,31);
	push(&head,4);
	push(&head,22);
	push(&head,24);
	push(&head,90);
	push(&head,50);
	push(&head,20);
	print(&head);
	insert_end(&head,99);
	print(&head);	
	//Release the memory at the end.
	return 0;
}

