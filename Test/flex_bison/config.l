%{
#include "config.tab.h"

void yyerror(char *message)
{
  printf("\nError: %s\n",message);
}

%}


%%

[0-9]+ {return NUMBER;}
[a-zA-Z][a-zA-Z0-9]* {return WORD;}
[\n]+ {}
[ \t]+ {}
%%