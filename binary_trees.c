#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newnode(int item)
{
	struct tree *temp = (struct tree*)malloc(sizeof(struct tree));
	temp->left=temp->right=NULL;
	temp->data = item;
	return temp;
}

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\n%d", root->data);
		inorder(root->right);
	}
}

struct tree *insert(struct tree* root, int data)
{
	if(root==NULL)
	{
		return newnode(data);
	}
	if(data<root->data)
	{
		root->left = insert(root->left,data);
	}
	else if(data>root->data)
	{
		root->right = insert(root->right,data);
	}
	return root;
}

void main()
{
	struct tree *root = NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	inorder(root);
}
