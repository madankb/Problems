#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
   int key;
   struct node* next;
};
void insert(struct node** head,int key)
{
   if (*head == NULL)
   {
       *head=new node;
       (*head)->key=key;
       (*head)->next=NULL;
   }
   else
   {
     struct node* temp=new node;
     temp->key=key;
     temp->next=*head;
     *head=temp;
   }
}
int size(struct node* list)
{
  int i=0;
  while (list != NULL)
  {
    i++;
    list=list->next;
  }
}
struct node* merge(struct node* front,struct node* back)
{
  if (front == NULL && back == NULL)
  return NULL;

  if (front == NULL)
  return back;

  if (back == NULL)
  return front;

  //cout<<"Front and Back key is :"<<front->key<<" "<<back->key<<endl;
  if (front->key < back->key)
  {
     front->next=merge(front->next,back);
     return front;
  }
  else
  {
    back->next=merge(front,back->next);
    return back;
  }
}
void print(struct node* p)
{
   while (p != NULL)
   {
     printf("%d ",p->key);
     p=p->next;
   }
   cout<<endl;
}
struct node* split(struct node* list,int size)
{
   if (list->next == NULL)
   return list;

   if (list == NULL) 
   return NULL;

   struct node* front=list;
   struct node* temp=list;
   struct node* back=NULL;

   int length=0;
   int half=size/2;

   while (length != half)
   {
       temp=temp->next;
       length=length+1;
   }
   
   back=temp->next;
   temp->next=NULL;

   front=split(front,half);
   back=split(back,half);
  
   list=merge(front,back);
      
   return list; 
}
struct node* mergesort(struct node* list)
{
    printf("Before Merge sort : \n");
    
    print(list);
    
    list=split(list,size(list));
    
    printf("After Merge sort : \n");
    
    print(list);
    
    return list;
}
int main()
{

   struct node* head=NULL;
   insert(&head,23);
   insert(&head,19);
   insert(&head,12);
   insert(&head,7);

   struct node* tail=NULL;
   insert(&tail,4);
   insert(&tail,3);
   insert(&tail,2);
   insert(&tail,1);

   print(head);
   print(tail);

   head=merge(head,tail);

   print(head);

   struct node* a=NULL;
   insert(&a,1);
   insert(&a,32);
   insert(&a,56);
   insert(&a,12);
   insert(&a,46);
   
   a=mergesort(a);

}
