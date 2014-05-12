#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
   int key;
   struct node* next;
};
void push(struct node** head,int key)
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
void print(struct node* head)
{
    while(head != NULL)
    {
       printf("%d ",head->key);
       head=head->next;
    }
    cout<<endl;
}
struct node* swap_pair(struct node* head)
{
    if (head == NULL || head->next == NULL)
    return head;

    struct node* temp=head->next;
    head->next=temp->next;
    temp->next=head;
   
    while (head != NULL && head->next != NULL)
    {
       struct node* s=head->next;
       struct node* f=head->next->next;
       
       if (f == NULL)
       break;

       s->next=f->next;
       f->next=s;
       head->next=f;

       head=s;
       s=s->next;
       f=f->next;

    }

    return temp; 
        
} 
int main()
{
   struct node* head=NULL;
   push(&head,20);
   push(&head,30);
   push(&head,34);
   push(&head,19);
   push(&head,6);
   push(&head,89);
   push(&head,67);
   
   print(head);
   
   head=swap_pair(head);
   
   print(head);
}
