#include<iostream>
#include<stdio.h>
#include<deque>
using namespace std;
void print_k_sliding(int A[],int n,int k)
{
  int i;
  deque<int> q;

  for (i=0;i<k;i++)
  {
     while(!q.empty() && A[i] >= A[q.back()])
           q.pop_back();

      q.push_back(i);

  }

  printf("%d ",A[q.front()]);

  for(;i<n;i++)
  {
      
     while(!q.empty() && q.front() <= i-k)
         q.pop_front();

     while(!q.empty() && A[i] >= A[q.back()])
          q.pop_back();

     q.push_back(i);

     printf("%d ",A[q.front()]);
  }
}
int main()
{
   int A[]={8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
   int k=4;
   int n=sizeof(A)/sizeof(A[0]);

   print_k_sliding(A,n,k);
}
