eval.l
%{
#include "y.tab.h" extern
yylval;
%}
%%
[0-9]+ {
yylval = atoi(yytext); return NUMBER;
}
[a-zA-Z]+ { return ID; }
[ \t]+ ;
\n { return 0; }
. { return yytext[0]; }
%%
eval.y
%{
#include <stdio.h>
%}
%token NUMBER ID
%left '+' '-'
%left '*' '/'
%%
E : T {
printf("Result = %d\n", $$);
return 0;
}
T :
T '+' T { $$ = $1 + $3; }
| T '-' T { $$ = $1 - $3; }
| T '*' T { $$ = $1 * $3; }
| T '/' T { $$ = $1 / $3; }
| '-' NUMBER { $$ = -$2; }
| NUMBER { $$ = $1; }
| ID { $$ = $1; };
%%
int main() { printf("Enter the
expression\n"); yyparse();
}
int yyerror(char* s) {
printf("\nExpression is invalid\n");
}
