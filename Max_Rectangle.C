#include<iostream>
#include<stdio.h>
#include<string.h>
#define R 4
#define C 5
using namespace std;
int kadanes_algorithm(int temp[],int n,int& start,int& end)
{
  int sum=0;
  int max_so_far=0,max_current=0;
  int int_start=0;
  
  for(int i=0;i<n;i++)
  {
    max_current=max_current+temp[i];
 
    if (max_current < 0)
    {
       max_current=0;
       int_start=i+1;
    }
    if (max_so_far < max_current)
    {
       max_so_far=max_current;
       start=int_start;
       end=i;
    }
  }

return max_so_far;
}    
int Max_Sum_Rectangle(int A[R][C])
{
    int temp[R];
    int sum=0,max_sum=0;
    int finalstart,finalend,finaltop,finaldown;
    int start,end;
    
    for (int i=0;i<C;i++)//Rectangle starts with column 0,1,2,3
    {
        memset(temp,0,sizeof(temp));
        for (int j=i;j<C;j++)//For each column from above extend the rectangle like (0,0)(0,1)(0,2)(0,3),(1,1)(1,2)(1,3)(2,2)(2,3)(3,3)
        {
            for(int k=0;k<R;k++)//for each rectangle, calc sum of row values for it 
            {
                temp[k]=temp[k]+A[k][j];
            }
            
            sum=kadanes_algorithm(temp,R,start,end);
            
            if (max_sum < sum)
            {
                max_sum=sum;
                finaltop=i;
                finalend=j;
                finalstart=start;
                finaldown=end;
            }
        }
    }
    
cout<<"Start co-ordinates : ("<<finalstart<<","<<finaltop<<")"<<endl;
cout<<"End co-ordinates : ("<<finaldown<<","<<finalend<<")"<<endl;

return max_sum;    
}
int main()
{
  int A[R][C]={{1,2,-1,-4,-20},
               {-8,-3,4,2,1},
               {3,8,10,1,3},
               {-4,-1,1,7,-6}};

  int temp[]={-2,-3,4,-1,-2,1,5,-3};
  int x,y;
  cout<<"Max array is : "<<kadanes_algorithm(temp,sizeof(temp)/sizeof(temp[0]),x,y)<<endl;
  
  cout<<"Max Rectangle array is : "<<Max_Sum_Rectangle(A)<<endl;
}
