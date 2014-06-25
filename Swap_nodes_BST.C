#include<iostream>
#include<stdio.h>
#include<limits.h>
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
  else if(key < (*root)->key)
    insert(&(*root)->left,key);
  else
    insert(&(*root)->right,key);
}
void inorder(struct node* root)
{
  if (root==NULL) 
     return;

  inorder(root->left);
  cout<<root->key<<"  ";
  inorder(root->right);
}
void find_swapping(struct node* root,struct node** first,struct node** middle,struct node** last,struct node** prev)
{
  if(root == NULL)
     return;
  
  find_swapping(root->left,first,middle,last,prev);

  if (*prev && root->key < (*prev)->key)
  {
    
     if(!*first)
     {
       *first=*prev;
       *middle=root;
     }
     else
       *last=root;
        
   }

   *prev=root;
 
  find_swapping(root->right,first,middle,last,prev);
    
}
bool find_fix_swap_nodes(struct node* root)
{
   
  struct node* first,*middle,*last,*prev;
  first=middle=last=prev=NULL;
  
  find_swapping(root,&first,&middle,&last,&prev);
  
  if(first && last)
  {
    int temp=first->key;
    first->key=last->key;
    last->key=temp;
    
    return true;
  }
  else if (first && middle)
  {
      int temp=first->key;
      first->key=middle->key;
      middle->key=temp;
      
      return true;
  }

  return false;  
}
int main()
{
  struct node* root=NULL;
  
  insert(&root,24);
  insert(&root,18);
  insert(&root,20);
  insert(&root,15);
  insert(&root,32);
  insert(&root,29);
  insert(&root,35);
  
  root->left->key=32;
  root->right->key=18;
      
  inorder(root);
  
  cout<<endl;
  
  if(find_fix_swap_nodes(root))
  {
      printf("Swapped nodes are reverted.\n");
      inorder(root);
      cout<<endl;
      
  }
 else
     printf("There is no swapped nodes. \n");
}
