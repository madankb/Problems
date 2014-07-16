#include<iostream>
#include<stdio.h>
using namespace std;
int find_max_repeating_number(int A[],int k,int n)
{
 if (n <= 0)
    return 0;

 for(int i=0;i<n;i++)
 {
   int index=A[i]%k;
   A[index]=A[index]+k;
 }

 int max=0,max_index=0;
 for(int i=0;i<n;i++)
 {
   if (max < A[i])
   {
       max=A[i];
       max_index=i;
   }
 }
 
 return max_index;
    
}
int main()
{
  int A[]={4,4,5,2,1,4,3,7,6};
  int n=sizeof(A)/sizeof(A[0]);
  int k=9;
  
  int i=find_max_repeating_number(A,k,n);
 
  cout<<"Maximum repeating number : "<<i<<endl;
};
