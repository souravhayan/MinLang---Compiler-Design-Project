%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
int line_num = 1;
int token_count = 0;
%}
%option noyywrap
%%
"int"           { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return INT; }
"float"         { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return FLOAT; }
"if"            { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return IF; }
"else"          { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return ELSE; }
"while"         { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return WHILE; }
"for"           { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return FOR; }
"print"         { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return PRINT; }
"read"          { token_count++; printf("  [+] KEYWORD: %s\n", yytext); return READ; }

[a-zA-Z][a-zA-Z0-9]*  { 
                        token_count++;
                        printf("  -> VARIABLE: %s\n", yytext);
                        yylval.str = strdup(yytext); 
                        return IDENTIFIER; 
                      }

[0-9]+          { 
                  token_count++;
                  printf("  -> NUMBER: %s\n", yytext);
                  yylval.ival = atoi(yytext); 
                  return INT_NUM; 
                }

"+"             { token_count++; return PLUS; }
"-"             { token_count++; return MINUS; }
"*"             { token_count++; return MULTIPLY; }
"/"             { token_count++; return DIVIDE; }
"="             { token_count++; return ASSIGN; }
"=="            { token_count++; return EQ; }
"!="            { token_count++; return NE; }
"<"             { token_count++; return LT; }
">"             { token_count++; return GT; }
"<="            { token_count++; return LE; }
">="            { token_count++; return GE; }

"("             { token_count++; return LPAREN; }
")"             { token_count++; return RPAREN; }
"{"             { token_count++; return LBRACE; }
"}"             { token_count++; return RBRACE; }
"["             { token_count++; return LBRACKET; }
"]"             { token_count++; return RBRACKET; }
";"             { token_count++; return SEMICOLON; }

[ \t]+          { /* ignore spaces */ }
\n              { line_num++; }
"//".*          { /* ignore comments */ }

.               { printf("  [!] ERROR: Unknown character '%s'\n", yytext); }

%%
int get_token_count() {
    return token_count;
}
