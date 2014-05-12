#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct node
{
   int key;
   struct node* left;
   struct node* right;
};
void insert(struct node** a,int key)
{

    if (*a == NULL)
    {
       *a=new node;
       (*a)->key=key;
       (*a)->left=NULL;
       (*a)->right=NULL;
    }
    else if (key < (*a)->key)
    {
           insert(&(*a)->left,key);
    }
    else
    {
           insert(&(*a)->right,key);
    }
}
void print(struct node* a)
{
  if (a == NULL)
  return;

  print(a->left);
  printf("%d ",a->key);
  print(a->right);
}
void vertical_view(map<int,vector<int> > &m,struct node* a,int value)
{
  if (a == NULL)
  return;

  vertical_view(m,a->left,value-1);
  //m.insert({value,a->key});
  m[value].push_back(a->key);
  vertical_view(m,a->right,value+1);
}
int main()
{

   struct node* b=NULL;
   insert(&b,40);
   insert(&b,50);
   insert(&b,12);
   insert(&b,13);
   insert(&b,11);
   insert(&b,45);
   insert(&b,56);

   print(b);

   cout<<endl;
   
   map<int,vector<int> > a;
   vertical_view(a,b,0);
   
   cout<<"Map size :"<<a.size()<<endl;
   
   for(map<int,vector<int> >::iterator itr=a.begin();itr != a.end();itr++)
   {
       for (int i=0;i<itr->second.size();i++)
       {
           cout<<"Key :  "<<itr->first<<"  value :"<<itr->second[i]<<endl;
       }
   }
}  
