

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



