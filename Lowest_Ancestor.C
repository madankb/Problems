#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
  int key;
  struct node* left;
  struct node* right;
};
void insert(struct node** head,int key)
{
   if (*head == NULL)
   {
      *head=new node;
      (*head)->key=key;
      (*head)->left=NULL;
      (*head)->right=NULL;
      return;
   }

   if (key < (*head)->key)
   {
      insert(&(*head)->left,key);
   }
   else
   {
      insert(&(*head)->right,key);
   }
}
bool search(struct node* head,int a)
{
  if(head == NULL)
  return false;
  
  if (a < head->key)
  {
     return search(head->left,a);
  }
  else if (a > head->key)
  {
    return search(head->right,a);
  }
  else
  {
    return true;
  }
} 
int LCA(struct node* head,int a,int b)
{
  if (head == NULL)
  return -1;

  if (head->key < a && head->key < b)
  {
     return LCA(head->right,a,b);
  }
  else if (head->key > a && head->key > b)
  { 
     return LCA(head->left,a,b); 
  }
  else
  {
    if (search(head,a) && search(head,b))
        return head->key;
    else
        return -1;
  }
}
int main()
{
  struct node* head=NULL;
  insert(&head,12);
  insert(&head,8);
  insert(&head,7);
  insert(&head,10);
  insert(&head,6);
  insert(&head,20);
  insert(&head,24);
  insert(&head,18);
  insert(&head,19);
  insert(&head,14);

  cout<<"LCA is : "<<LCA(head,19,14)<<endl;
}
   
