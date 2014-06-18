#include<iostream>
#include<stdio.h>
#define MAX_HEAP_SIZE 128
using namespace std;
bool greatest(int a,int b)
{
   return a > b;
}
bool lowest(int a,int b)
{
  return a < b;
}
int average(int a,int b)
{
  return (a+b)/2;
}
int Signum(int a,int b)
{
  if (a == b)
  return 0;

  return (a < b)?-1:1;
}
class Heap
{

public:  
  Heap(int *b,bool(*c)(int,int))
  {
    A=b;
    comp=c;
    heapsize=-1;
  };
  
  int *A;
  int heapsize;
  bool(*comp)(int,int);
  
 int left(int i)
 {
   return 2*i+1;
 }

 int right(int i)
 {
   return 2*i+2;
 }
 
 int parent(int i)
 {
    if (i <= 0)
     return -1;
     
   return (i-1)/2;
 }

 int GetTop()
 {
  if (heapsize >= 0)
     return A[0];

  return -1;
 }
 
 int GetCount()
 {
   return heapsize+1;
 }
 
 void swap(int &a,int &b)
 {
   int temp=a;
   a=b;
   b=temp;
 }

 void heapify(int size)//O(Log N)
 {
    int p=parent(size);
    if(p >= 0 && comp(A[size],A[p]))
    {
       swap(A[p],A[size]);
       heapify(p);
    }
 }
 
 int ExtractTop()//O(log N)
 {
    int ret=-1;

    if (heapsize >= 0)
    {
      ret=A[0];//Element which is min in minheap and max in maxheap.
      swap(A[0],A[heapsize]);
      heapsize--;//Extracted and tailed back element is no longer considered.
      heapify(parent(heapsize+1));//heapsize+1 gives place where replaced and heapification starts from it parent
    }

    return ret;
 }
      
 bool Insert(int key)//O(log N)
 {
   bool ret=false;
   
   if (heapsize < MAX_HEAP_SIZE)
   {
     ret=true;
     heapsize++;
     A[heapsize]=key;
     heapify(heapsize);
   }    

   return ret;
 }

 void print()
 {
   if (heapsize >= 0)
    for(int i=0;i<=heapsize;i++)
     printf("%d ",A[i]);
 
   cout<<endl;
 }  
};
class MaxHeap:public Heap
{
    public:
    MaxHeap():Heap(new int[MAX_HEAP_SIZE],&greatest){};//constructor delegation
};
class MinHeap:public Heap
{
    public:
    MinHeap():Heap(new int[MAX_HEAP_SIZE],&lowest){};
};
int find_median(int key,int &m,Heap &l,Heap &r)
{
    int sign=Signum(l.GetCount(),r.GetCount());
    switch(sign)
    {
        case 1://Left has more elements 
             
            if (key < m)
            {
                r.Insert(l.ExtractTop());//Left top will be in right top
                l.Insert(key);
            }
            else
            {
                r.Insert(key);//Goes right side and both balanced
            }
            
            m=average(l.GetTop(),r.GetTop());
        
        break;    
        
        case 0://Left and right are equal, so median is in middle
        
            if (key < m)
            {
                l.Insert(key);
                m=l.GetTop();
            }
            else
            {
                r.Insert(key);
                m=r.GetTop();
            }
            
        break;    
            
        case -1:
        
            if (key < m)
            {
                l.Insert(key);
            }
            else
            {
                l.Insert(r.ExtractTop());
                r.Insert(key);
            }
           
           m=average(l.GetTop(),r.GetTop());
        
        break;    
    }
    
    return m;
}
int main()
{
    Heap *minheap=new MinHeap();
    
    Heap *maxheap=new MaxHeap();

    int A[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int size = sizeof(A)/sizeof(A[0]);

    int m=0;

    for (int i=0;i<size;i++)
    {
       m=find_median(A[i],m,*maxheap,*minheap);//O(N.Log N)
       cout<<m<<endl;       
    }
} 
