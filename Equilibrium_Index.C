#include<iostream>
#include<stdio.h>
using namespace std;
int find_equilibrium(int A[],int n)
{
  int sum=0;
  
  for(int i=0;i<n;i++)
     sum=sum+A[i];

  int leftsum=0;

  for(int i=0;i<n;i++)   
  {
     sum=sum-A[i];

     if(sum == leftsum)//Leftsum holds sum until i-1 and sum holds sum after i+1 to end.
        return i;

     leftsum=leftsum+A[i];
  }

  return -1;
}
int main()
{
  int A[]={1,4,2,0,3,2};

  int n=sizeof(A)/sizeof(A[0]);
  
  int x=find_equilibrium(A,n);

  if (x == -1)
     printf("There is no equilibrium index. \n");
  else
     printf("Equilibrium index is : [%d] \n",x);

}
