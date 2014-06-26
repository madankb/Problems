#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int Max_rectangle_area(int hist[],int n)//O(n)
{
  if (n <= 0)
     return 0;

 int max_area=0;
 int temp_area=0;
 
 stack<int> s;
 
 int i=0;

 while(i < n)
 {
   if(s.empty() || hist[s.top()] <= hist[i])
      s.push(i++);
   else
   {
      int t=s.top();//s.top() always has the smallest element of current element
      s.pop();//Keep on pops until the element smaller than hist[i]

      temp_area=hist[t] * (s.empty()?i:i-1-s.top());//i-1 comes to current index

      if (max_area < temp_area)
          max_area=temp_area;
   }
 }

 while(!s.empty())
 {
  
   int t=s.top();
   s.pop();

   temp_area=hist[t] * (s.empty()?n:n-1-s.top());

  if (max_area < temp_area)
       max_area=temp_area;

 }

 return max_area;
} 

int main()
{
  int hist[]={6,2,5,4,5,1,6};
  int n=sizeof(hist)/sizeof(hist[0]);
  
  cout<<"Max rectangle is : "<<Max_rectangle_area(hist,n)<<endl;

}
