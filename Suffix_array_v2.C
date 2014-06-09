#include<iostream>//http://stackoverflow.com/questions/17761704/suffix-array-algorithm
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct suffix
{
  int index;
  int rank[2];
};
bool comp(struct suffix r1,struct suffix r2)
{
  if (r1.rank[0] == r2.rank[0])
  {
     if (r1.rank[1] < r2.rank[1])
         return true;
     else
         return false;
  }
  else
  {
      if (r1.rank[0] < r2.rank[0])
          return true;
      else
          return false;
  } 
}  
void suffix_array(char *txt,int n,int A[])
{
  struct suffix suffixes[n];

  for (int i=0;i<n;i++)
  {
    suffixes[i].index=i;
    suffixes[i].rank[0]=txt[i] - 'a';
    suffixes[i].rank[1]=((i+1) < n)? (txt[i+1] - 'a'):-1;
  }
 
  sort(suffixes,suffixes+n,comp);

  for (int i=0;i<n;i++)
  {
    cout<<"Index is : "<<suffixes[i].index<<endl;
  }

  
  for(int k=4;k<2*n;k=k*2)
  {
     int prev_rank=suffixes[0].rank[0];
     suffixes[0].rank[0]=0;
     A[suffixes[0].index]=0;

     int rank=0;

    for (int i=1;i<n;i++)
    {
        int temp=0;

        if(suffixes[i].rank[0] == prev_rank && suffixes[i].rank[1] == suffixes[i-1].rank[1])
        {
               prev_rank=suffixes[i].rank[0];
               suffixes[i].rank[0]=rank;
        }
        else
        {
               prev_rank=suffixes[i].rank[0];
               suffixes[i].rank[0]=++rank;
        }
                
        A[suffixes[i].rank[0]]=i;        
    }

    for (int i=0;i<n;i++)
    {
       int next_index=suffixes[i].index+k/2;
       suffixes[i].rank[1]=(next_index < n) ? suffixes[A[next_index]].rank[0]:-1;
    }
    
    sort(suffixes,suffixes+n,comp);
  }
  cout<<endl;
  for (int i=0;i<n;i++)
  {
    cout<<"Index is : "<<suffixes[i].index<<endl;
  }
}
int main()
{
 char *txt="banana";
 int n=strlen(txt);

 int A[n];

 suffix_array(txt,n,A);
}
 
