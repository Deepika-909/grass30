%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
int yyerror(char *s);
%}

%union {
    double dval;
}

%token <dval> NUM
%type <dval> E

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

Statement:
      E '\n' { printf("Answer: %g\n", $1); }
      ;

E:
      E '+' E { $$ = $1 + $3; }
    | E '-' E { $$ = $1 - $3; }
    | E '*' E { $$ = $1 * $3; }
    | E '/' E { $$ = $1 / $3; }
    | '-' E %prec UMINUS { $$ = -$2; }
    | NUM { $$ = $1; }
    ;

%%

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *s) {
    printf("Invalid Expression\n");
    return 0;
}
