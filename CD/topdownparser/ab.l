%{
#include "ab.tab.h"
%}

%%
a   return 'a';
b   return 'b';
\n  return 0;
.   ;
%%

int yywrap() {
    return 1;
}