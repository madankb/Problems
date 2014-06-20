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
void find_kth_largest(struct node* root,int &k)
{
   if (root == NULL)
       return;

   find_kth_largest(root->right,k);
   k=k-1;
  
  if (k == 0)
  {
      printf("%d \n",root->key);
      return;
  }
  else
     find_kth_largest(root->left,k); 
  
}
void find_kth_smallest(struct node* root,int &k)
{
   if (root == NULL)
       return;

   find_kth_smallest(root->left,k);
   k=k-1;
  
  if (k == 0)
  {
      printf("%d \n",root->key);
      return;
  }
  else
     find_kth_smallest(root->right,k); 
  
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
  insert(&root,18);
  insert(&root,17);
  
  int k=3;
  
  find_kth_largest(root,k);
  k=3;
  find_kth_smallest(root,k);
}
