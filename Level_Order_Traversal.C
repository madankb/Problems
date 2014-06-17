#include<iostream>
#include<stdio.h>
#include<queue>
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
   else if (key < (*root)->key)
       insert(&(*root)->left,key);
   else
       insert(&(*root)->right,key);
}
void print_level_order(struct node* root)
{
    if (root == NULL)
       return;

    queue<struct node*> q;
    q.push(root);

    while (!q.empty())
    {
         printf("%d ",q.front()->key);

         if (q.front()->left != NULL)
                 q.push(q.front()->left);
        
         if (q.front()->right != NULL)
                 q.push(q.front()->right);

         q.pop();
    }  
        
}
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

   print_level_order(root);
} 

