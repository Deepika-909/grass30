%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%%

S: A B
 | A
 ;

A: 'a' A
 | 'a'
 ;

B: 'b' B
 | 'b'
 ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter input (a's followed optionally by b's): ");
    
    if (yyparse() == 0)
        printf("Input is valid according to the grammar.\n");
        
    return 0;
}