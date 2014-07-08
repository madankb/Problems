#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
struct Queue
{
  int max_page_size;
  int cur_page_size;
  struct qnode* front;
  struct qnode* rear;
};
struct qnode
{
  int page_number;
  struct qnode* prev;
  struct qnode* next;
};
struct Hash
{
  int slot_size;
  struct qnode** slot;
};
void dequeue(Queue* q,Hash* h)
{
    if(q->rear == NULL) 
      return;

    h->slot[q->rear->page_number]=NULL;

    
    struct qnode* ref=q->rear->prev;

    delete q->rear;
    q->rear=NULL;
    
    if (ref != NULL)
    {
      ref->next=NULL;
      q->rear=ref;
    }

    q->cur_page_size--;   
 
}
void enqueue(Queue* q,Hash* h,int page)
{
  if (q->max_page_size == q->cur_page_size)
     dequeue(q,h);

  struct qnode* temp=NULL;

  temp=new qnode;
  temp->page_number=page;
  temp->prev=NULL;
  temp->next=q->front;

  h->slot[page]=temp;
    
  if (q->front != NULL)
      q->front->prev=temp; 
  else
      q->rear=temp;

  q->front=temp;
  q->cur_page_size++; 
}
struct Queue* createqueue(int qsize)
{
 
  struct Queue* q=new Queue;
  
  q->front=q->rear=NULL;

  q->max_page_size=qsize;
  q->cur_page_size=0;

  return q;
}
struct Hash* createhash(int slot_size)
{
 struct Hash* h=new Hash;
 h->slot_size=slot_size;
 h->slot=new qnode*[slot_size];

 for(int i=0;i<slot_size;i++)
 {
     h->slot[i]=NULL;
 }

 return h;

}
void ReferencePage(Queue* q,Hash* h,int ref_page)
{
  if (ref_page >= h->slot_size)
  {
      printf("The Page can't be stored in the current slot size.\n");
      return;
  }
  if (h->slot[ref_page] == NULL)
     enqueue(q,h,ref_page);
  else
  {
   
     if (h->slot[ref_page] != q->front)
     { 
        struct qnode* temp=h->slot[ref_page];
        struct qnode* ref=temp->next;

        if (ref != NULL)
            ref->prev=temp->prev;
        else
            q->rear=temp->prev;

        temp->prev->next=ref;
        temp->prev=NULL; 

        temp->next=q->front;
        q->front->prev=temp; 

        q->front=temp;
     }
 }
   
}
void queue_order(qnode* q)
{
  while(q != NULL)
  {
    printf("%d ",q->page_number);
    q=q->next;
  }
  cout<<endl;
}
void hash_print(Hash* h)
{
  for(int i=0;i<h->slot_size;i++)
  {
      if (h->slot[i] != NULL)
         printf("%d ",h->slot[i]->page_number);
  }
  cout<<endl;
}
int main()
{
  int qsize=4;
  int slot_size=10;
  
  
  Queue* q=createqueue(qsize);
  Hash*  h=createhash(slot_size);

  ReferencePage(q,h,1);
  ReferencePage(q,h,2);
  ReferencePage(q,h,3);

  queue_order(q->front);

  ReferencePage(q,h,1);
  
  queue_order(q->front);
 
  ReferencePage(q,h,4);

  queue_order(q->front);

  ReferencePage(q,h,7);
  
  queue_order(q->front);

  hash_print(h);
    
}
