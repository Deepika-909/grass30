%{
#include "calc.tab.h"
#include <stdlib.h>
%}

%option noyywrap

%%

[0-9]+(\.[0-9]+)?   { yylval = atof(yytext); return NUM; }

[+\-*/()]           { return yytext[0]; }

\n                  { return '\n'; }

[ \t]+              ;     // ignore spaces

.                   { printf("Invalid char: %s\n", yytext); }

%%