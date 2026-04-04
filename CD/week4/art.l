%{
#include <stdio.h>
#include "art.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*   { return ID; }
[0-9]+                { return DIG; }
[ \t]+                ;          /* ignore spaces */
\n                    { return 0; }
.                     { return yytext[0]; }
%%

int yywrap()
{
    return 1;
}
