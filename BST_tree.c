/*==============Binary Tree Program Desing=========================
Demonstrate the binary search tree insert and 
traversals.
written by:shuzjd
date:2013/2/24
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
	int data;
	struct node* left;
	struct node* right;
}NODE;

typedef struct {
	node* root;
	int count;
}tree;

void preOrder(NODE* root){

	if(root){
		printf("%4d",root->data);
		preOrder(root->left);
		preOrder(root->right);

	}
	return ;
}

void inOrder(NODE* root){

	if (root)
	{
		inOrder(root->left);
		printf("%4d",root->data);
		inOrder(root->right);
	}

	return ;
}

/*==============BST(binary search tree)================
   BST_INSERT
   Return pointer to new root
*/
NODE* BST_Insert(tree* tree,NODE* root, int dataIn){

	if(!root){
		NODE* pNew;
		pNew =(NODE*)malloc(sizeof(node));
		if(!pNew){
			printf("Error:memory overflow");
		}

		pNew->data = dataIn;
		pNew->left = pNew->right =NULL;
		tree->root = pNew;
		return pNew;

	}

	if(dataIn< (root->data) ){

		root->left = BST_Insert(tree,root->left,dataIn);
	}
	else{
		root->right = BST_Insert(tree,root->right,dataIn);
	}
	return root;

}

int main(){
	int numIn;
	tree tree;

	tree.count = 0;
	tree.root =NULL;

	do 
	{
		printf("Enter a number: ");
		scanf("%d",&numIn);
		if (numIn>0)
		{
			tree.root = BST_Insert(&tree,tree.root,numIn);
			tree.count ++;
		}
	} while (numIn>0);

	printf("\nData in preOrder: ");
	preOrder(tree.root);

	printf("\nData in inOrder: ");
	inOrder(tree.root);

	printf("\n\nEnd of BST demonstration\n");

	return 0;
}

