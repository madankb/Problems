#include<iostream>
#include<stdio.h>
#include<limits.h>
using namespace std;
int sum_frequency(int freq[],int i,int j)
{
 int sum=0;

 for(int k=i;k<=j;k++)
    sum=sum+freq[k];

 return sum;
}
int R_optimalSearchTree(int keys[],int freq[],int i,int j)
{
  if (i > j)
     return 0;

 if (i == j)
    return freq[i];

 int sum=sum_frequency(freq,i,j);

 int min=INT_MAX;

 for(int r=i;r<=j;r++)
 {
   int cost=R_optimalSearchTree(keys,freq,i,r-1)+R_optimalSearchTree(keys,freq,r+1,j);

   if (cost < min)
      min=cost;
 }

 return sum+min;

}
int D_optimalSearchTree(int freq[],int n)
{
  int cost[n][n];

  for(int i=0;i<n;i++)
      cost[i][i]=freq[i];

  for(int L=2;L<=n;L++)//j-i+1 = L
  {
    for(int i=0;i<=n-L;i++)
    {
      int j=i+L-1;
      
      cost[i][j]=INT_MAX; 

      int sum=sum_frequency (freq,i,j);
      
      for(int r=i;r<=j;r++)
      {
         int min=((r > i)?cost[i][r-1]:0) + ((r < j)?cost[r+1][j]:0) + sum;
        
         if (min < cost[i][j])
            cost[i][j]=min;
      }
       
    }
 }

 return cost[0][n-1];
} 
int main()
{
    int keys[] = {10, 12, 20,24};
    int freq[] = {34, 8, 50,4};
    int n = sizeof(keys)/sizeof(keys[0]);
    printf("Cost of Optimal recursive BST is : %d \n", R_optimalSearchTree(keys,freq,0,n-1));
    printf("Cost of Optimal dynamic BST is   : %d \n",D_optimalSearchTree(freq,n));
    return 0;
}
