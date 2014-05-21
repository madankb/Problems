#include<iostream>
#include<stdio.h>
using namespace std;
int R_sum_contigious(int A[],int index,int n,int sum)
{
  if (index == n)
  return sum;

  int max_val=sum+A[index];
 
  return max(R_sum_contigious(A,index+1,n,max_val),R_sum_contigious(A,index+1,n,0));
}
int D_sum_contigious(int A[],int n)
{
  int max_ending_here,max_so_far=0;

  for (int i=0;i<n;i++)
  {
    max_ending_here=max_ending_here + A[i];

    if (max_ending_here < 0)
    {
        max_ending_here=0;
    }
    if (max_so_far < max_ending_here)
    {
        max_so_far=max_ending_here;
    }
  }
  
  return max_so_far;
}
int main()
{
  int A[]={-2,-3,4,-1,-2,-1,5,-3,6};
  int n=sizeof(A)/sizeof(A[0]);
 
  cout<<"R max sum contigious subarray is : "<<R_sum_contigious(A,0,n,0)<<endl;

  cout<<"D max sum contigious subarray is : "<<D_sum_contigious(A,n)<<endl;
 
} 
