#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void func1()
{
  for(int i=0;i<4;i++)
  {
    printf("hello world \n");
  }
}

void func2()
{
  printf("hello world");
    printf("hello world");
      printf("hello world");
        printf("hello world");
 }
 
int main()
{
 clock_t t1,t2;
 t1= clock();
 func1();
 t1= clock()-t1;
 
 double tt1 = ((double)t1/CLOCKS_PER_SEC);
 printf("%f Time taken by for loop \n",tt1);
 
 t2=clock();
 func2();
 t2=clock()-t2; 
 double tt2 = ((double)t2/CLOCKS_PER_SEC);
 printf("\n %f Time taken by normal printing\n",tt2);
 
 
 }
 
 
  
