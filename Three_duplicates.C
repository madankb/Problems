#include<iostream>
#include<stdio.h>
#define INT_SIZE 32
using namespace std;
int Get_Single(int A[],int n)
{
  int result=0;
  int sum;
 
  int x=0;
 
  for(int i=0;i<INT_SIZE;i++)
  {
    sum=0;
    x=(1<<i);//Left shift       

    for(int j=0;j<n;j++)
    {
       if (A[j] & x) //Bitwise AND to check the bits are set at same position
          sum=sum+1;
    }

    if (sum%3) //Modula finds the place where extra bit is set.
       result=result|x; //Bitwise OR to copy the set bits
  }

  return result;
}  
int main()
{
  int A[]={14,14,14,5,18,18,18,27,27,27};
  int n=sizeof(A)/sizeof(A[0]);

  int x=Get_Single(A,n);
  cout<<"Non duplicate value is : "<<x<<endl;
}
