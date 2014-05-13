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
void print(struct node* head)
{
	for(;head != NULL;head=head->next)
	{
		printf("%d ",head->key);
	}
	cout<<endl;
}
void Reverse_LL(struct node* odd)
{
	if (odd == NULL || odd->next == NULL)
	return;
	
	struct node* even=odd->next;
	
	odd->next=even->next;
	
	even->next=NULL;
	
	odd=odd->next;
	
	while(odd->next != NULL)
	{
		struct node* temp=odd->next->next;
		
		odd->next->next=even;
		even=odd->next;
		odd->next=temp;
		
		if (temp != NULL)
		odd=temp;
	}
	
	odd->next=even;	
	
}			
int main()
{
	struct node* head=NULL;
	insert(&head,2);
	insert(&head,3);
	insert(&head,4);
	insert(&head,5);
	insert(&head,6);
	//insert(&head,7);
	
	print(head);
	
	Reverse_LL(head);
	
	print(head);
}		
	  