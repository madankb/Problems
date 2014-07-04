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
void Add_greater_node(struct node* root,int &sum)
{
  if (root == NULL)
     return;

  Add_greater_node(root->right,sum);
  root->key=root->key + sum;
  sum=root->key;
  Add_greater_node(root->left,sum);
}
void print_inorder(struct node* root)
{
  if (root == NULL)
     return;

  print_inorder(root->left);
  printf("%d ",root->key);
  print_inorder(root->right);
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

  int sum=0;
  Add_greater_node(root,sum);
  print_inorder(root);
}
