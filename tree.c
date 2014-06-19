

#include <stdio.h>
#include <stdlib.h>


typedef struct treenode
{	
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode_t;


treenode_t* insert(treenode_t *node , int element){
	
	if (node == NULL)
	{
		treenode_t *newnode;
		newnode=(treenode_t*)malloc(sizeof(treenode_t));
		newnode->data=element;
		newnode->left=newnode->right = NULL;
		return newnode;
	}

	//If the node is not NULL
	if(element > (node->data)){
		node->right = insert(node->right,element);
	}
	else if (element < (node->data))
	{	
		node->left = insert(node->left,element);	
	}

	//else return 

	return node;


}

	//deleting an element from the tree

treenode_t *delete(treenode_t node,int data){

	treenode_t *temp;
	if (node == NULL)
	{
		return;
	}
	else if (data < node->data)
	{
		node->left =delete(node->left,data);
	}
	else if (data > node->data)
	{
		node->right =delete(node->right,data);
	}
	else
	{
		//Now we replace with minimum element in the right 
		//sub tree or maximum element in the sub tree
		if (node->right && node->left)
		{
			//here we will replace with minimum element in 
			//the right sub tree
		}





		//If there is only one/ zero child then we can directly
		//remove it from the tree and connect itd parents to 
		//its child
		temp = node;
		if (node->left == NULL )
		{	
			
		}
	}
}


