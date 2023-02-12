%{
#include "update_config.h"
//#include "zySingleton.h"
%}

%token NUMBER
%token WORD
//%token HOUR
//%token MIN
//%token SEC

%start config

%%
config:
    | config WORD '=' NUMBER {update_config_number($1, $3);}
    | config WORD '=' WORD {update_config_string($1, $3);}
    ;
%%

int parse_item(const char *item)
{
  YY_BUFFER_STATE buffer = yy_scan_buffer(item, strlen(item));
  yyparse();
  yy_delete_buffer(buffer);
  return 0;
}