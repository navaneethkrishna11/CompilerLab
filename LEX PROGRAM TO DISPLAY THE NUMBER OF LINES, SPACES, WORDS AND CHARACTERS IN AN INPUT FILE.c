%{
#include<stdio.h>
#include<ctype.h>
int lines = 0; int
spaces = 0; int
words = 0; int
characters = 0;
int in_word = 0;
%}
%%
\n { lines++;  in_word = 0; }
[ \t] { spaces++; in_word = 0; }
[a-zA-Z0-9_] { characters++; if (!in_word) { words++; in_word = 1; } }
. { characters++; }
%%
int main(void) {
yyin = fopen("input.txt",
"r"); if (!yyin) {
perror("Error opening file");
return 1;
}
yylex();
fclose(yyin);
printf("\nThis file contains:");
printf("\n\t%d lines", lines);
printf("\n\t%d spaces", spaces);
printf("\n\t%d words", words);
printf("\n\t%d characters\n", characters);
return 0;
}
int yywrap() {
return 1;
}
