#include<iostream>
#include<stdio.h>
using namespace std;
int Get_Parent(int i)
{
  return (i - 1)/2;
}
int left(int i)
{
 return 2*i+1;
}
int right(int i)
{
 return 2*i+2;
}
void min_heapify(int A[],int n,int size)
{
  if (n < 0 || n >= size)
       return;

 
  int l=left(n);
  int r=right(n);
  int min=0;
  
  if (l < size && A[l] < A[n])
      min=l;
  else
      min=n;

  if (r < size && A[r] < A[min])
     min=r;

  if (min != n)
  {
     int temp=A[n];
     A[n]=A[min];
     A[min]=temp;
     min_heapify(A,min,size);
  }
  else
     return;
    
}
int extract_top(int A[],int &size)
{
  if (size <= 0)
     return -1;

  int x=A[0];
  A[0]=A[size-1];
  A[size-1]=x;
  

  size--;
  min_heapify(A,0,size);

  return x;
}
int find_min_cost(int A[],int size)
{
 
  if (size <= 0)
     return -1;

  for(int i=size-1;i>=0;i--)
      min_heapify(A,i,size);

  int min_cost=0;

  while(size > 1)  
  {
    int x=extract_top(A,size);
    int y=extract_top(A,size);

    min_cost=min_cost+x+y;
    
    A[size]=x+y;
    size++;
  }
  
  return min_cost;     
 
}
int main()
{
  int A[]={5,8,4,3,9,6};
  int n=sizeof(A)/sizeof(A[0]);
  
  
  int min_cost=find_min_cost(A,n);

  printf("Minimum cost to amalgamate the gold coins is : %d\n",min_cost);

     
}
