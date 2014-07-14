#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
struct node
{
  int key;
  struct node* left;
  struct node* right;
  struct node* adj;
};
void insert(struct node** root,int key)
{
   if (*root == NULL)
   {
      *root=new node;
      (*root)->key=key;
      (*root)->left=NULL;
      (*root)->right=NULL;
      (*root)->adj=NULL;
   }
   else if (key < (*root)->key)
       insert(&(*root)->left,key);
   else
       insert(&(*root)->right,key);
}
void change_Adj(struct node* root)
{
  if(root == NULL)
    return;
  
  queue<struct node*> q;
  
  if (root->left != NULL)
      q.push(root->left);
  
  if(root->right != NULL)
     q.push(root->right);

  while(!q.empty())
  {
   struct node* temp=q.front();
  
    if (temp->left != NULL)
      q.push(temp->left);
  
     if(temp->right != NULL)
      q.push(temp->right);
 
     q.pop();
  
    temp->adj=q.front();
   
  }
};
int main()
{
   struct node* root=NULL;
   insert(&root,10);
   insert(&root,8);
   insert(&root,9);
   insert(&root,7);
   insert(&root,12);
   insert(&root,13);
   insert(&root,11);
 
   if (root->left->adj == NULL)
      cout<<"It is empty"<<endl;

   change_Adj(root);  

   if (root->left->right->adj != NULL)
      cout<<"It is not empty"<<root->left->right->adj->key<<endl;

} 
