#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
int Get_Min(int A[],int s,int e)
{
   if (s > e)
      return 0;

   int min=INT_MAX;

   for(int i=s;i<=e;i++)
   {
      if (A[i] < min)
          min=A[i];
   }

   return min;
}
int Get_Max(int A[],int s,int e)
{
   if (s > e)
      return 0;

   int max=INT_MIN;

   for(int i=s;i<=e;i++)
   {
      if (A[i] > max)
          max=A[i];
   }

   return max;
}
int Greater_min(int A[],int s,int e,int min)
{
    if (s > e)
       return 0;
       
    for(int i=s;i<=e;i++)
    {
        if (A[i] > min)
           return i;
    }
    
    return -1;
}
int Lesser_max(int A[],int s,int e,int max)
{
    if (s > e)
       return 0;
       
    for(int i=s;i<=e;i++)
    {
        if (A[i] < max)
           return i;
    }
    
    return -1;
}
int find_len_unsorted_array(int A[],int n,int &s,int &e)
{
  if (n == 0)
     return 0;

  for(int i=1;i<n;i++)
  {
    if(A[i] < A[i-1])
    {
        s=i-1;
        break;
    }    
  }
  
  if (s == -1)
       return -1;

  for(int j=n-1;j>0;j--)
  {
     if (A[j] < A[j-1])
     {
         e=j;
         break;
     }         
   }

   int unsort_min=Get_Min(A,s,e);
   int unsort_max=Get_Max(A,s,e);

   int new_s=Greater_min(A,0,s-1,unsort_min);
   int new_e=Lesser_max(A,e+1,n-1,unsort_max);

   if (new_s != -1)
      s=new_s;
      
   if (new_e != -1)
     e=new_e;
     
   return e-s+1;
} 
int main()
{
  int A[]={0,1,15,25,6,7,30,40,50};
  //int A[]={1,2,3,4,5,6};

  int n=sizeof(A)/sizeof(A[0]);

  int s=-1,e=-1;
  
  int len=find_len_unsorted_array(A,n,s,e);//O(n)
  
  if (len != -1)
  {
   printf("Min length of unsorted array is : %d.\n",len);
   printf("Start index and End index is : %d %d.\n",s,e);
  }
  else
   printf("Array is already sorted.\n");
   
}
