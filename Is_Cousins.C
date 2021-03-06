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
int find_level(struct node* root,struct node* a)
{
  if (root == NULL)
      return 0;

  if (root->key == a->key)
      return 1;

  int l=find_level(root->left,a);

  if (l == 0)  
  {
     int r=find_level(root->right,a);

     if (r == 0)   
        return 0;
     else
       return r+1;
  }
  else
    return 1+l;

}
bool Is_Sibling(struct node* root,struct node* a,struct node* b)
{
  if (root == NULL)
    return false;

  return ((root->left == a && root->right == b) || (root->left == b && root->right == a) || Is_Sibling(root->left,a,b) || Is_Sibling(root->right,a,b));
}
bool Is_Cousin(struct node* root,struct node* a,struct node* b)
{

  if (root == NULL || a	== NULL|| b ==	NULL)
    return false;

  int l=find_level(root,a);
  int r=find_level(root,b);

  if (l != r)
    return false;

  if (!Is_Sibling(root,a,b))
    return true;

  return false;
}
int main()
{
  struct node* root=NULL;
  insert(&root,6);
  insert(&root,10);
  insert(&root,3);
  insert(&root,5);
  insert(&root,2);
  insert(&root,7);
  insert(&root,12);

  print_inorder(root);
  cout<<endl;

  Is_Cousin(root,root->left->left,root->right->left);
}
