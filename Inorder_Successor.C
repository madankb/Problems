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
bool find_inorder_successor(struct node* root,struct node* rootref,int key)
{
  if (root == NULL)
      return false;

  if (key < root->key)
     return find_inorder_successor(root->left,rootref,key);
  else if (key > root->key)
     return find_inorder_successor(root->right,rootref,key);

  if (root->key == key)
  {
    if (root->right != NULL)
    {
       struct node* temp=root->right;

       while (temp->left != NULL)
           temp=temp->left;
 
       printf("Inorder successor of [%d] is [%d].\n",key,temp->key);

       return true;    
    }
    else
    {
 
      struct node* succ=NULL;

      while (rootref != NULL)
      {
          if (key < rootref->key)
          {
            succ=rootref;
            rootref=rootref->left;
          }
          else if (key > rootref->key)
               rootref=rootref->right;
          else
             break;
      }
 
      printf("Inorder successor of [%d] is [%d].\n",key,succ->key);
      
      return true;
    }
  }
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
  insert(&root,7);
  insert(&root,13);
  insert(&root,12);
  insert(&root,14);

  if(find_inorder_successor(root,root,7))
     printf("Successor is found successfuly.\n");  
  else
     printf("Key is not found in BST.\n");  
}
