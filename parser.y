%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern int yylex();
extern int line_num;
extern FILE *yyin;
extern int get_token_count();
void yyerror(const char *s);

struct symbol {
    char name[50];
    char type[10];
    int value;
    int is_array;
    int array_size;
    int is_used;
};

struct symbol symbol_table[100];
int symbol_count = 0;

int var_count = 0;
int array_count = 0;
int assignment_count = 0;
int expression_count = 0;
int loop_count = 0;
int condition_count = 0;
int print_count = 0;

int find_symbol(char *name);
void add_symbol(char *name, char *type, int is_array, int size);
void print_symbol_table();
void print_statistics();
void check_unused_variables();
%}

%union {
    int ival;
    char *str;
}

%token <str> IDENTIFIER
%token <ival> INT_NUM
%token INT FLOAT IF ELSE WHILE FOR PRINT READ
%token PLUS MINUS MULTIPLY DIVIDE ASSIGN
%token EQ NE LT GT LE GE
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON

%type <ival> expression term factor
%type <str> type

%left EQ NE LT GT LE GE
%left PLUS MINUS
%left MULTIPLY DIVIDE

%%

program:
    statement_list
    {
        printf("\n==========================================\n");
        printf("    COMPILATION SUCCESSFUL!\n");
        printf("==========================================\n");
        print_symbol_table();
        print_statistics();
        check_unused_variables();
    }
    ;

statement_list:
    statement_list statement
    | statement
    ;

statement:
    declaration_statement
    | assignment_statement
    | if_statement
    | while_statement
    | for_statement
    | print_statement
    | read_statement
    | LBRACE statement_list RBRACE
    ;

declaration_statement:
    type IDENTIFIER SEMICOLON
    {
        printf("Declaring variable: %s (type: %s)\n", $2, $1);
        add_symbol($2, $1, 0, 0);
        var_count++;
    }
    | type IDENTIFIER LBRACKET INT_NUM RBRACKET SEMICOLON
    {
        printf("Declaring array: %s[%d] (type: %s)\n", $2, $4, $1);
        add_symbol($2, $1, 1, $4);
        array_count++;
    }
    ;

type:
    INT     { $$ = "int"; }
    | FLOAT { $$ = "float"; }
    ;

assignment_statement:
    IDENTIFIER ASSIGN expression SEMICOLON
    {
        int pos = find_symbol($1);
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", $1);
        } else {
            printf("Assigning: %s = %d\n", $1, $3);
            symbol_table[pos].value = $3;
            symbol_table[pos].is_used = 1;
            assignment_count++;
        }
    }
    | IDENTIFIER LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
    {
        int pos = find_symbol($1);
        if (pos == -1) {
            printf("ERROR: Array %s not declared\n", $1);
        } else if (!symbol_table[pos].is_array) {
            printf("ERROR: %s is not an array\n", $1);
        } else if ($3 >= symbol_table[pos].array_size || $3 < 0) {
            printf("ERROR: Array index out of bounds\n");
        } else {
            printf("Array assignment: %s[%d] = %d\n", $1, $3, $6);
            symbol_table[pos].value = $6;
            symbol_table[pos].is_used = 1;
            assignment_count++;
        }
    }
    ;

if_statement:
    IF LPAREN expression RPAREN statement
    {
        printf("If statement executed (condition = %d)\n", $3);
        condition_count++;
    }
    | IF LPAREN expression RPAREN statement ELSE statement
    {
        printf("If-else statement executed (condition = %d)\n", $3);
        condition_count++;
    }
    ;

while_statement:
    WHILE LPAREN expression RPAREN statement
    {
        printf("While loop executed (condition = %d)\n", $3);
        loop_count++;
    }
    ;

for_statement:
    FOR LPAREN assignment_statement expression SEMICOLON assignment_statement RPAREN statement
    {
        printf("For loop executed\n");
        loop_count++;
    }
    ;

print_statement:
    PRINT LPAREN expression RPAREN SEMICOLON
    {
        printf("OUTPUT: %d\n", $3);
        print_count++;
    }
    | PRINT LPAREN IDENTIFIER RPAREN SEMICOLON
    {
        int pos = find_symbol($3);
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", $3);
        } else {
            printf("OUTPUT: %s = %d\n", $3, symbol_table[pos].value);
            symbol_table[pos].is_used = 1;
            print_count++;
        }
    }
    ;

read_statement:
    READ LPAREN IDENTIFIER RPAREN SEMICOLON
    {
        int pos = find_symbol($3);
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", $3);
        } else {
            printf("Reading input for: %s\n", $3);
            symbol_table[pos].is_used = 1;
        }
    }
    ;

expression:
    expression PLUS term
    {
        $$ = $1 + $3;
        printf("  %d + %d = %d\n", $1, $3, $$);
        expression_count++;
    }
    | expression MINUS term
    {
        $$ = $1 - $3;
        printf("  %d - %d = %d\n", $1, $3, $$);
        expression_count++;
    }
    | expression EQ term
    {
        $$ = ($1 == $3) ? 1 : 0;
        printf("  %d == %d is %s\n", $1, $3, $$ ? "TRUE" : "FALSE");
        expression_count++;
    }
    | expression LT term
    {
        $$ = ($1 < $3) ? 1 : 0;
        printf("  %d < %d is %s\n", $1, $3, $$ ? "TRUE" : "FALSE");
        expression_count++;
    }
    | expression GT term
    {
        $$ = ($1 > $3) ? 1 : 0;
        printf("  %d > %d is %s\n", $1, $3, $$ ? "TRUE" : "FALSE");
        expression_count++;
    }
    | term
    {
        $$ = $1;
    }
    ;

term:
    term MULTIPLY factor
    {
        $$ = $1 * $3;
        printf("  %d * %d = %d\n", $1, $3, $$);
    }
    | term DIVIDE factor
    {
        if ($3 == 0) {
            printf("ERROR: Division by zero!\n");
            $$ = 0;
        } else {
            $$ = $1 / $3;
            printf("  %d / %d = %d\n", $1, $3, $$);
        }
    }
    | factor
    {
        $$ = $1;
    }
    ;

factor:
    INT_NUM
    {
        $$ = $1;
    }
    | IDENTIFIER
    {
        int pos = find_symbol($1);
        if (pos == -1) {
            printf("ERROR: Variable %s not declared\n", $1);
            $$ = 0;
        } else {
            $$ = symbol_table[pos].value;
            symbol_table[pos].is_used = 1;
        }
    }
    | LPAREN expression RPAREN
    {
        $$ = $2;
    }
    ;

%%

int find_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_symbol(char *name, char *type, int is_array, int size) {
    if (find_symbol(name) != -1) {
        printf("WARNING: Variable %s already declared\n", name);
        return;
    }
    
    memset(&symbol_table[symbol_count], 0, sizeof(struct symbol));
    strcpy(symbol_table[symbol_count].name, name);
    strcpy(symbol_table[symbol_count].type, type);
    symbol_table[symbol_count].value = 0;
    symbol_table[symbol_count].is_array = is_array;
    symbol_table[symbol_count].array_size = size;
    symbol_table[symbol_count].is_used = 0;
    symbol_count++;
}

void print_symbol_table() {
    printf("\n--- SYMBOL TABLE ---\n");
    printf("Name\t\tType\t\tArray\tSize\tUsed\n");
    printf("------------------------------------------------\n");
    
    for (int i = 0; i < symbol_count; i++) {
        printf("%s\t\t%s\t\t%s\t%d\t%s\n",
               symbol_table[i].name,
               symbol_table[i].type,
               symbol_table[i].is_array ? "Yes" : "No",
               symbol_table[i].array_size,
               symbol_table[i].is_used ? "Yes" : "No");
    }
    printf("------------------------------------------------\n");
}

void print_statistics() {
    printf("\n===========================================\n");
    printf("              STATISTICS                   \n");
    printf("===========================================\n");
    printf("| Lines processed      : %-15d |\n", line_num);
    printf("| Tokens found         : %-15d |\n", get_token_count());
    printf("| Variables declared   : %-15d |\n", var_count);
    printf("| Arrays declared      : %-15d |\n", array_count);
    printf("| Assignments          : %-15d |\n", assignment_count);
    printf("| Expressions          : %-15d |\n", expression_count);
    printf("| Loops                : %-15d |\n", loop_count);
    printf("| Conditions           : %-15d |\n", condition_count);
    printf("| Print statements     : %-15d |\n", print_count);
    printf("===========================================\n");
}


void check_unused_variables() {
    printf("\n--- UNUSED VARIABLES ---\n");
    int unused_count = 0;
    
    for (int i = 0; i < symbol_count; i++) {
        if (!symbol_table[i].is_used) {
            printf("WARNING: Variable '%s' is not used\n", symbol_table[i].name);
            unused_count++;
        }
    }
    
    if (unused_count == 0) {
        printf("Great! All variables are used.\n");
    }
    printf("---------------------------\n");
}

void yyerror(const char *s) {
    printf("ERROR at line %d: %s\n", line_num, s);
    printf("\n--- PARTIAL SYMBOL TABLE ---\n");
    print_symbol_table();
}

int main(int argc, char **argv) {
    printf("====================================\n");
    printf("      MinLang Compiler\n");
    printf("      Compiler For Beginners\n");
    printf("====================================\n");
    
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("ERROR: Cannot open file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
        printf("Reading file: %s\n\n", argv[1]);
    } else {
        printf("Enter your code:\n\n");
    }
    
    int result = yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    if (result == 0) {
        printf("\nCompilation finished successfully!\n");
    } else {
        printf("\nCompilation failed!\n");
    }
    
    return result;
}
