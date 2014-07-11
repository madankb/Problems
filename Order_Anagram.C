#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct word
{
   int index;
   char *str;
};
struct duparray
{
  struct word* array;
  int size;
};
int compChar(const void *a,const void *b)
{
  return *(char*)a - *(char*)b;
}
int compStr(const void *x,const void *y)
{
  struct word* a=(struct word*)x;
  struct word *b=(struct word*)y;

  return strcmp(a->str,b->str);
}
struct duparray* create_array(char* list[],int size)
{
  struct duparray* dup=new duparray;
  dup->array=new word[size];
  dup->size=size;

  return dup;
  
}
void print_anagrams(char* list[],int size)
{

  struct duparray* dup=create_array(list,size);
  
  for (int i=0;i<size;i++)
  {
    dup->array[i].index=i;
    dup->array[i].str=new char[strlen(list[i])+1];
    strcpy(dup->array[i].str,list[i]);
  }

  for(int i=0;i<size;i++)
  {
    qsort(dup->array[i].str,strlen(dup->array[i].str),sizeof(char),compChar);
  }

  qsort(dup->array,size,sizeof(dup->array[0]),compStr);
  
  for (int i=0;i<size;i++)
  {
      cout<<list[dup->array[i].index]<<endl;
  }
  
  return;
}
int main()
{
   char* list[]={"cat","dog","tac","god","act"};
   int size=sizeof(list)/sizeof(list[0]);
   
   print_anagrams(list,size);
   
}
