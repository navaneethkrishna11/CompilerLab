%{
#include<stdio.h
> int v=0; int
cons = 0;
%}
%%
[aeiouAEIOU] {v++;}
[a-zA-Z] {cons++;}
"\n" {printf("%d vowels and %d consonants\n", v, cons);exit(0);}
%%
int main()
{
printf("Enter the input text:
"); yylex(); return 0;
}
int yywrap()
{
}
