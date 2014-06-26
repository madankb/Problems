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
bool find_merge_point(struct node* first,struct node* second)
{
  if (first == NULL || second == NULL)
      return false;

  int c1=Get_Count(first);
  int c2=Get_Count(second);

  int d=0;

  struct node* track=NULL;

  if(c1 >= c2)
  {
    d=c1-c2;
    track=first;
  }
  else
  {
    d=c2-c1;  
    track=second;
  }

  if(track == first)
  {
    while(d > 0)
    {
        first=first->next;
        d=d-1;
    } 
  }
  else
  {
     while(d > 0)
     {
        second=second->next;
        d=d-1;
     } 
  }

  while (first != NULL && second != NULL)
  {
     if (first == second)
     {
        printf("Merge point exists at : %d \n",first->key);       
        return true;
     }

     first=first->next;
     second=second->next;
  }

 return false;

}
int main()
{
  struct node* first=NULL;
  
  for(int i=5;i>=1;i--)
   push(&first,i);

  struct node* second=NULL;

  for(int i=16;i<=17;i++)
   push(&second,i);

  second->next->next=first->next->next->next->next;

  if (find_merge_point(first,second))
      printf("Merge point detected. \n");
  else
      printf("Merge point does not exists. \n"); 

}
