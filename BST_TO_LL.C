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
  if(*root == NULL)
  {
    *root=new node;
    (*root)->key=key,
    (*root)->left=NULL;
    (*root)->right=NULL;
     return;
  }
  else if ((*root)->key > key)
      insert(&(*root)->left,key);
  else
      insert(&(*root)->right,key);
 
}
void print_inorder(struct node* root)
{
  if(root == NULL)
  return;

  print_inorder(root->left);
  printf("%d ",root->key);
  print_inorder(root->right);
}
struct node* convert_LL(struct node* root)
{
  if (root == NULL)
  return root;

  if (root->left != NULL)
  {
     struct node* temp=convert_LL(root->left);

     for(;temp->right != NULL;temp=temp->right)
     {
     }

     temp->right=root;
     root->left=temp;
  }

  if (root->right != NULL)
  {
    struct node* temp=convert_LL(root->right);
    
    for(;temp->left != NULL;temp=temp->left)
    {
    }

    temp->left=root;
    root->right=temp;
  }
  
  return root; 
  
}
struct node* get_head(struct node* root)
{
  while (root->left != NULL)
       root=root->left;

  return root;
}
void print_list(struct node* head)
{
 if (head == NULL)
 return;

 for(;head != NULL;head=head->right)
 {
    printf("%d ",head->key);
 }
 cout<<endl;

}  
int main()
{

 struct node* root=NULL;
 insert(&root,10);
 insert(&root,8);
 insert(&root,9);
 insert(&root,6);
 insert(&root,18);
 insert(&root,19);
 insert(&root,16);
 
 print_inorder(root);
 
 cout<<endl;
 
 root=convert_LL(root);

 struct node* head=get_head(root);

 print_list(head);

}
