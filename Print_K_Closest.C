#include<iostream>
#include<stdio.h>
using namespace std;
int binary_search(int A[],int n,int x)
{
  int low=0;
  int high=n-1;

  int mid=0;

  while(1)
  {
      
    if (x < A[low])
    {
        printf("Key is out of index\n");
        return low; 
    }

    if (x > A[high])
    {
        printf("Key is out of index\n");
        return high;
    }

    if (x == A[low])
    {
        printf("key is found at the index : %d\n",low);
        return low;
    }
     
    if (x == A[high])
    {
        printf("key is found at the index : %d\n",high);
        return high;
    }
   
    mid=low + (high - low)/2;
     
    if (x == A[mid])
    {
       printf("Key is found at the index : %d\n",mid);
       return mid;
    }

    if (x < A[mid])
        high=mid-1;

    if (x > A[mid])
        low=mid+1;

  }

}
void printKclosest(int A[],int n,int x,int k)
{
   int l=binary_search(A,n,x); //O(log n)
   int count=0;
   int r=l+1;
      
   if (A[l] == x)
       l--;

   while (l >= 0 &&  r < n && count < k) //O(k)
   {
        if (x - A[l] < A[r] - x) 
        printf("%d\n",A[l--]);
        else
        printf("%d\n",A[r++]);

       count++;  
   }
 
   while (l >= 0 && count < k)
   {
      printf("%d\n",A[l--]);
      count++;
   }

   while ( r < n && count < k)
  {
     printf("%d\n",A[r++]);
     count++;
  }
 
} 
int main()
{
  int A[]={12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56};

  int n=sizeof(A)/sizeof(A[0]);

  printKclosest(A,n,35,5);//O(k+log n)
}
