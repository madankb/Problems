#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
	int key;
	struct node* left;
	struct node* right;
};
void insert(struct node** root,int key)
{
	if (*root == NULL)
	{
		*root=new node;
		(*root)->key=key;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else if (key < (*root)->key) 
	{
		insert(&(*root)->left,key);
	}
	else
	{
		insert(&(*root)->right,key);
	}
}
void morris_traversal(struct node* root)
{
	if (root == NULL)
	return;
	
	while (root != NULL)
	{
		if (root->left == NULL)
		{
			printf("%d ",root->key);
			root=root->right;
		}
		else
		{
			struct node* pre=root->left;
			
			while (pre->right != NULL && pre->right != root)
			pre=pre->right;
			
			if (pre->right == NULL)
			{
				pre->right=root;
				root=root->left;
			}
			else
			{
				pre->right=NULL;
				printf("%d ",root->key);
				root=root->right;
			}				
		}
	}
	cout<<endl;
}
void inorder(struct node* root)
{
	if (root == NULL)
	return;
	else
	{
		inorder(root->left);
		printf("%d ",root->key);
		inorder(root->right);
	}
}						
int main()
{
	struct node* root=NULL;
	insert(&root,12);
	insert(&root,10);
	insert(&root,11);
	insert(&root,9);
	insert(&root,15);	
	insert(&root,14);
	insert(&root,18);
	
	morris_traversal(root);
	inorder(root);
	cout<<endl;
}				
		
				