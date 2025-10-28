%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER
%token PLUS MINUS MUL DIV LPAREN RPAREN

%left PLUS MINUS
%left MUL DIV
%nonassoc UMINUS   /* For unary minus */

%%
expr:
      expr PLUS expr    { $$ = $1 + $3; }
    | expr MINUS expr   { $$ = $1 - $3; }
    | expr MUL expr     { $$ = $1 * $3; }
    | expr DIV expr     { 
                            if ($3 == 0) {
                                yyerror("Division by zero");
                            }
                            $$ = $1 / $3; 
                         }
    | LPAREN expr RPAREN { $$ = $2; }
    | MINUS expr %prec UMINUS { $$ = -$2; }
    | NUMBER             { $$ = $1; }
    ;

%%
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main(void) {
    printf("Enter an arithmetic expression:\n");
    if (yyparse() == 0)
        printf("Valid expression.\n");
    else
        printf("Invalid expression.\n");
    return 0;
}
