#include<iostream>
#include<stdio.h>
using namespace std;
int comp(const void *a,const void *b)
{
	int x=*(int *)a;
	int y=*(int *)b;
	
	if (x%2 != 0 && y%2 != 0)
		return y-x;
	else if (x%2 == 0 && y%2 == 0)
	    return x-y;	
	else if (x%2 == 0 && y%2 != 0)
	    return 1;
	else
	    return -1;    
	
}	
int main()
{
	int A[]={7,13,2,6,9,15,18};
	
	qsort(A,sizeof(A)/sizeof(A[0]),sizeof(A[0]),comp);
	
	for (int i=0;i<sizeof(A)/sizeof(A[0]);i++)
	{
		cout<<A[i]<<" ";
	}
	cout<<endl;	
}