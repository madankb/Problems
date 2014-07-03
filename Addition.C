#include<iostream>
#include<stdio.h>
using namespace std;
int Add(int x,int y)
{
    while (y != 0)
    {
        int carry=x&y;
        
        x=x^y;
        
        y=carry<<1;
    }
    
    return x;
}    
int main()
{
  cout<<"Addition is : "<<Add(12,15)<<endl;
}
