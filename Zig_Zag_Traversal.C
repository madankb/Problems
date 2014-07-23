#include<iostream>
#include<stdio.h>
#include<stack>
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
void print_zig_zag(struct node* root)
{
 stack<struct node*> s1;
 stack<struct node*>s2;
 

 s1.push(root);

 while (!s1.empty() || !s2.empty())
 {
   
   while(!s1.empty())
   {
     struct node* temp=s1.top();
     s1.pop();

     cout<<temp->key<<" ";
      
     if (temp->right != NULL)
        s2.push(temp->right);
     
     if (temp->left != NULL)
        s2.push(temp->left);  
   }
 
   while (!s2.empty())
   {
     struct node* temp=s2.top();
     s2.pop();

     cout<<temp->key<<"  ";

     if (temp->left != NULL)
        s1.push(temp->left);

     if (temp->right != NULL)
        s1.push(temp->right);

   }

 }       
 
};
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
}
