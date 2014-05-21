#include<iostream>
#include<stdio.h>
using namespace std;
int gcd(int n,int d)
{
  if (n == 0)
  return d;
  else
  return gcd(d,n%d);
} 
void array_rotate(int A[],int n,int d)
{

 int i,j,k;

 for (i=0;i<gcd(n,d);i++)
 {
     int temp=A[i];
     j=i;
     while(1)
     {
       k=j+d;
       if (k >= n)
       k=k-n;
       if (k == i)
       break;
       
       A[j]=A[k];
       j=k;
     }
     A[j]=temp;
  }
}
int main()
{
  int A[]={1,2,3,4,5,6,7,8,9,10,11,12};
  int n=sizeof(A)/sizeof(A[0]);
 
  array_rotate(A,n,2);
 
  for(int i=0;i<n;i++)
  printf("%d ",A[i]);

  cout<<endl;
}
     
      
