#include<iostream>
#include<stdio.h>
#include<stack>
#define N 4
using namespace std;
int find_celebrity(bool M[N][N])
{
  stack<int> s;
  
  for(int i=0;i<N;i++)
     s.push(i);

  while (s.size() > 1)
  {
  
    int A=s.top();
    s.pop();
 
    int B=s.top();
    s.pop();

    if (M[A][B] && !M[B][A])
        s.push(B);
    else
        s.push(A);

  }

  cout<<"Size is : "<<s.size()<<endl;
  
  int C=s.top();
  s.pop();

  cout<<"C is : "<<C<<endl;

  for(int i=0;i<N;i++)
  {
     if (i != C)
          s.push(i);
  }

  while (s.size() > 0)
  {
     
    int A=s.top();
    s.pop();

    if(M[C][A])
      return -1;

  }

  return C;  
     
}
int main()
{
  bool M[N][N]={{0,0,1,0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
  
  cout<<find_celebrity(M)<<endl;
}
