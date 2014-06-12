#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
using namespace std;
int D_LPS(char *A,int n)
{
 int R[n][n];//O(n^2) Space complexity

 memset(R,0,sizeof(R));

 for (int i=0;i<n;i++)
 {
   R[i][i]=1;
 }
 
 int start=0,max=0;
 for(int i=0;i<n-1;i++)
 {
  if (A[i] == A[i+1])
  {
    start=i;
    R[i][i+1]=2;
    max=2;
  }
 }

 for (int len=3;len <=n;len++) //O(n^2) 
 {
   for (int i=0;i<=n-len;i++)
   {
       int j=i+len-1;

       if (A[i] == A[j] && R[i+1][j-1] != 0)
       {
          R[i][j]= 2+R[i+1][j-1];
       }
       else
       {
          R[i][j]=0;
       }
       
       if (max < R[i][j])
       {
           start=i;
           max = R[i][j];
       }
       
   }
 } 

 if (max != 0)
 {
     for (int i=start;i<=start+max -1;i++)
     {
         cout<<A[i];
     }
     cout<<endl;
 }
 
 return max;
}
int main()
{
 char *A="neveroddorevenratsliveonnoevilstar";
 int n=strlen(A);

 cout<<"Longest palindrome is : "<<D_LPS(A,n)<<endl;

} 
