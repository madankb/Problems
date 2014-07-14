#include<iostream>
#include<stdio.h>
using namespace std;
int No_of_BST(int A[],int start,int end)
{
 if (start >= end)
    return 1;

 int sum=0;

 for(int i=start;i<=end;i++)
 {
    int left=No_of_BST(A,start,i-1);
    int right=No_of_BST(A,i+1,end);
  
   sum = sum + (left*right);
 }

 return sum;
}
int main()
{
  int A[]={1,2,3,4};
  int size=sizeof(A)/sizeof(A[0]);
  
  cout<<"Number of BST is : "<<No_of_BST(A,0,size-1)<<endl;
}
