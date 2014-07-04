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
  if (*root==NULL)
  {
     *root=new node;
     (*root)->key=key;
     (*root)->left=NULL;
     (*root)->right=NULL;
  }
  else if(key < (*root)->key)
       insert(&(*root)->left,key);
  else
       insert(&(*root)->right,key);
}
void print_inorder(struct node* root)
{
  if (root == NULL)
     return;

  print_inorder(root->left);
  printf("%d ",root->key);
  print_inorder(root->right);
}
int print_node_k_leaves(struct node* root,int k)
{
  if (root == NULL)
     return 0;

  if (root->left == NULL && root->right == NULL)
     return 1;

  int l=print_node_k_leaves(root->left,k);
  int r=print_node_k_leaves(root->right,k);

  if (l+r == k)
     printf("Roor [%d] has [%d] leaves.\n",root->key,k);

  
  return l+r;
} 
int main()
{
  struct node* root=NULL;
    
  insert(&root,15);
  insert(&root,8);
  insert(&root,21);
  insert(&root,19);
  insert(&root,24);
  insert(&root,25);
  insert(&root,23);
  insert(&root,14);
  insert(&root,7);

  int k=3;
  
  print_node_k_leaves(root,k);
  
}
