#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
  int key;
  struct node* next;
};
void push(struct node** list,int key)
{
  if (*list == NULL)
  {
   (*list)=new node;
   (*list)->key=key;
   (*list)->next=NULL;
  }
  else
  {
   struct node* temp=new node;
   temp->key=key;
   temp->next=*list;
   *list=temp;
  }
}
int Get_Count(struct node* list)
{
  int count=0;
 
  while(list != NULL)
  {
     count++;
     list=list->next;
  }

  return count;
}
void Add_Digit(struct node* list,struct node* root,int &a)
{
  if (list == NULL)
     return;

  Add_Digit(list->next,root,a);

  int sum=0;

  sum=list->key+a;
 
 if (sum >= 10 && list != root)
 {
    list->key=sum%10;
    a=sum/10;
 }
 else
 {
    list->key=sum; 
    a=0; 
 }
   
}  
int main()
{
  struct node* first=NULL;
  
  push(&first,9);
  push(&first,9);
  push(&first,6);
  push(&first,1);

  int a=1;
 
  Add_Digit(first,first,a);

  for(struct node* temp=first;temp != NULL;temp=temp->next)
     printf("%d ---> ",temp->key);

  cout<<endl;

}
