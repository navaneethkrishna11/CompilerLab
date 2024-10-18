%{
#include<stdio.h>
#include<string.h>
char str[100]; char
replace[3] = "abc";
char replace_with[3] = "ABC";
%}
%%
abc {strcat(str,"ABC");}
[a-zA-Z] {strcat(str,yytext);}
" " {strcat(str, " ");}
"\n" { printf("%s\n", str);exit(0);}
%%
int main()
{
printf("Enter the input text:
"); yylex(); return 0;
}
int yywrap()
{
}
