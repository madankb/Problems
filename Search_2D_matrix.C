#include<iostream>
#include<stdio.h>
#define R 4
#define C 4
using namespace std;
bool search(int A[R][C],int s,int e,int t)
{
  if (s >= R || s < 0 || e >= C || e < 0)
     return false;

  int r=A[s][e];

  if (r == t)
  {
     printf("Target [%d] found at the index(%d,%d). \n",t,s,e);
     return true;
  }

  if (t < r)
     return search(A,s-1,e,t);
  else
     return search(A,s,e+1,t);

  return false; 
}
int main()
{
  int A[R][C]={{1,5,13,29},
             {11,16,25,38}, 
             {45,49,52,57},
             {51,54,59,66}};

  if (search(A,R-1,0,2))
      printf("Element is found.\n");
  else
      printf("No such element in matrix. \n");
};

 
