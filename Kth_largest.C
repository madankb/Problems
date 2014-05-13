#include<iostream>
#include<stdio.h>
using namespace std;
int left(int i)
{
  return 2*i+1;
}
int right(int i)
{
  return 2*i+2;
}
void min_heapify(int A[],int index,int size)
{
   int l=left(index);
   int r=right(index);
   int smallest=index;

   if (l < size && A[index] > A[l])
   {
      smallest=l;
   }
   if (r < size && A[smallest] > A[r])
   {
      smallest=r;
   }
   
   if (smallest != index)
   {
      int temp=A[index];
      A[index]=A[smallest];
      A[smallest]=temp;
      
      min_heapify(A,smallest,size);
   }
}
int kth_smallest_element(int A[],int k,int size)
{
  int c=1;
 
  while (c<k)//k-1 swap, so kth incident has kth largest elements.
  {
     cout<<"c is :"<<c<<endl; 
     int temp=A[0];
     A[0]=A[size-1];
     A[size-1]=temp;

     c=c+1;
     size=size-1;
  
     min_heapify(A,0,size);// O(k log n) only the swapped element is heapified 
  }

  return A[0]; 
  
}

int main()
{
     int A[4][4]={{10,20,30,40},
                  {15,25,35,45},
                  {24,29,37,48},
                  {32,33,39,50}};

     int B[16];
     int n=0;

     for(int i=0;i<4;i++)
     {
       for(int j=0;j<4;j++)
       {
           B[n]=A[i][j];
           n++;
       }
     }
  
     for(int i=0;i<n;i++)
     {
      cout<<B[i]<<" ";
     }
     cout<<endl;

     for(int i=n;i>=0;i--)
     {
         min_heapify(B,i,n);// O(n) since it runs from backward to heapify all elements
     }

     for(int i=0;i<n;i++)
     {
      cout<<B[i]<<" ";
     }
     cout<<endl;
     
     cout<<"Kth smallest element in array is : "<<kth_smallest_element(B,7,n)<<endl; // O(n + k log n)
     
     for(int i=0;i<n;i++)
     {
      cout<<B[i]<<" ";
     }
     cout<<endl;

}          
