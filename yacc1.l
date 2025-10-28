%{
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+              { yylval = atoi(yytext); return NUMBER; }
[ \t\n]             ;      /* Ignore whitespace */
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }

.                   { printf("Invalid character: %s\n", yytext); }
%%

int yywrap(void) {
    return 1;
}
