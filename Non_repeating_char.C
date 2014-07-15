#include<iostream>
#include<stdio.h>
#include<string.h>
#define MAX_CHAR 256
using namespace std;
struct node
{
  char t;
  struct node* prev;
  struct node* next;
};
void append(struct node** list,struct node** tail,char A)
{
  if (*list == NULL)
  {
    *list=new node;
    (*list)->t=A;
    (*list)->prev=NULL;
    (*list)->next=NULL;
    *tail=*list;
  }
  else
  {
    struct node* temp=new node;
    temp->t=A;
    temp->prev=*tail;
    temp->next=NULL;
    (*tail)->next=temp;
    *tail=temp;
  }
}
void removed_node(struct node** list,struct node** tail,struct node* r)
{
  if (r == NULL)
      return;

  if (r == *list)
  {
    *list=(*list)->next;
    if (*list)
       (*list)->prev=NULL;
  }
  if (r == *tail)
  {
   (*tail)=(*tail)->prev;
   if (*tail)  
     (*tail)->next=NULL;
  }
  if (r->prev != NULL && r->next != NULL)
  {
    (r->prev)->next=r->next;
    (r->next)->prev=r->prev;
  }

}
char find_non_repeating_char(char A,bool visited[],struct node** dll_ptr,struct node** list,struct node** tail)
{
 
 if (visited[A] == true)
 {
   return (*list)?(*list)->t:'\0';
 }
 else if (visited[A] == false && dll_ptr[A] == NULL)
 {
   append(list,tail,A);
   dll_ptr[A]=*tail;
   return (*list)->t;
 }
 else if (visited[A] == false && dll_ptr[A] != NULL)
 {
   visited[A]=true;
   
   removed_node(list,tail,dll_ptr[A]); 
   delete dll_ptr[A];
   dll_ptr[A]=NULL;
   
   return (*list)?(*list)->t:'\0';
 }
 }
int main()
{
 char *A="geeksforgeeks";
 //char *A="HHHH";
 int n=strlen(A);
 
 bool visited[MAX_CHAR]={0};
 struct node** dll_ptr=new node*[MAX_CHAR];
 struct node* list=NULL;
 struct node* tail=NULL;

 for(int i=0;i<MAX_CHAR;i++)
         dll_ptr[i]=NULL;
  
 for(int i=0;i<n;i++)
 {
   char t=find_non_repeating_char(*(A+i),visited,dll_ptr,&list,&tail);
   cout<<"First non-repeating character is : "<<t<<endl;
 }

}
