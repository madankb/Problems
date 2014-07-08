#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
  int key;
  struct node* next;
  struct node* arbitary;
};
void insert(struct node** list,int key)
{
  struct node* temp=new node;
  temp->key=key;
  temp->next=*list;
  *list=temp;
}
void print(struct node* list)
{
  while(list != NULL)
  {
    printf("%d ",list->key);
    list=list->next;
  }

  cout<<endl;
}
void copy_node(struct node* list)
{
  if(list == NULL)
    return;

  copy_node(list->next);

  struct node* ref=new node;
  ref->key=list->key;
  ref->next=list->next;

  list->next=ref;

}
void copy_arbitary(struct node* list)
{
  if (list == NULL)
     return;

  list->next->arbitary=list->arbitary->next;
  copy_arbitary(list->next->next);
}
struct node* restore_original(struct node* list,struct node* copy)
{
  if (list == NULL)
     return NULL;

  copy=list->next;
  list->next=copy->next;

  copy->next=restore_original(list->next,copy->next);

  return copy;
}
struct node* clone(struct node* list)
{
  if (list == NULL)
     return NULL;

  copy_node(list);
  copy_arbitary(list);

  struct node* copy=NULL;

  copy=restore_original(list,copy);

  return copy;  
}
int main()
{
  struct node* list=NULL;

  for(int i=5;i>=1;i--)
     insert(&list,i);

  print(list);

  list->arbitary=list->next->next;
  list->next->arbitary=list;
  list->next->next->arbitary=list->next->next->next->next;
  list->next->next->next->arbitary=list->next->next;
  list->next->next->next->next->arbitary=list->next;

  struct node* copy=clone(list);
  print(copy);
  print(list);
  
  int i=0;

  struct node* ref=copy;

  while (i < 5)
  {
    cout<<ref->arbitary->key<<endl;    
    ref=ref->next;
    i++;
  }
}    
