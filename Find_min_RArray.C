#include<iostream>
#include<stdio.h>
using namespace std;
int find_min(int A[],int low,int high)
{
  if (high < low)
  return A[0];
  
  if (low == high)
  return A[low];

  int mid=low+(high-low)/2;//Formula to go both on above and below partition
  
  if (A[mid -1] > A[mid])
  return A[mid];
  
  if (A[mid] > A[mid+1])
  return A[mid+1];
  
  if (A[mid] == A[mid-1] && A[mid]==A[mid+1]) //Special case O(n)
  return min(find_min(A,low,mid-1),find_min(A,mid+1,high));
  
  if (A[high] > A[mid])
  return find_min(A,low,mid-1); //O(log n)
  
  return find_min(A,mid+1,high);
}
int main()
{

 //int A[]= {2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2}; //Special case
 int A[]={5, 6, 1, 2, 3, 4};
 int n=sizeof(A)/sizeof(A[0]);

 cout<<"Min element is : "<<find_min(A,0,n-1)<<endl;
}
