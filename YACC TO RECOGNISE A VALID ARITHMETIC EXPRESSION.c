valid.l
%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
[0-9]+ { return DIGIT;}
[a-zA-Z][a-zA-Z0-9_]* { return ID; }
\n { return NL;}
. { return yytext[0]; }
%%
valid.y
%{
#include<stdio.h>
#define YYSTYPE double
%}
%token DIGIT ID NL
%left '-' '+'
%left '*' '/'
%%
stmt : exp NL {printf("Valid expression."); exit(0);}
; exp :exp '+' exp | exp '-' exp
| exp '*' exp
| exp '/' exp
|'(' exp ')'
| ID
| DIGIT;
%%
int yyerror(char *msg)
{
printf("Invalid expression.");
}
void main ()
{ printf("Enter the expression:
"); yyparse();
}
