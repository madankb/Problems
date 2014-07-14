#include<iostream>
#include<stdio.h>
using namespace std;
int No_of_BST(int A[],int start,int end)
{
  if (start > end)
     return 0;

 if (start == end)
    return 1;

 int max=0;

 for(int i=start;i<=end;i++)
 {
    max=max+No_of_BST(A,start,i-1)+No_of_BST(A,i+1,end);
 }

 return max;
}
int main()
{
  int A[]={1,2};
  int size=sizeof(A)/sizeof(A[0]);
  
  cout<<"Number of BST is : "<<No_of_BST(A,0,size-1)<<endl;
}
