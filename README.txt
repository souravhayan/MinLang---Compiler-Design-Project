MinLang Compiler-
A simple educational compiler for the MinLang programming language built with Flex and Bison.


Overview-
MinLang Compiler is an educational project that demonstrates fundamental compiler construction concepts. It supports basic programming constructs including variables, arrays, arithmetic operations, control flow, and I/O operations.


Features-
1.Variables: int and float data types
2.Arrays: Array declarations and element access
3.Arithmetic: Basic math operations (+, -, *, /)
4.Comparisons: Relational operators (>, <, ==)
5.Control Flow: if-else statements and while/for loops
6.I/O: print() and read() statements
7.Error Detection: Unused variable warnings and semantic analysis


Installation-
1.GCC Compiler
2.Flex (lexical analyzer)
3.Bison (parser generator)

MinLang-Compiler/
│
├── Source Files
│   ├── flex.l                   # Lexical analyzer specification
│   ├── parser.y                 # Parser grammar rules
│   └── minlang.exe              # Compiled executable
│
├── Generated Files (auto-created during build)
│   ├── parser.tab.c             # Generated parser code
│   ├── parser.tab.h             # Generated parser headers
│   └── lex.yy.c                 # Generated lexer code
│
├── Test Files
│   ├── math_test.ml             # Arithmetic operations test
│   ├── array_test.ml            # Array operations test
│   ├── condition_test.ml        # Conditional statements test
│   ├── loop_test.ml             # Loop structures test
│   ├── error_test.ml            # Error detection test
│   └── studentgrade_test.ml     # Complete feature demo
│
├── Scripts
│   └── run_all_tests.bat        # Batch file to run all tests
│
└── Documentation
    └── README.md                # This file


Key Components-
flex.l: Defines tokens and lexical rules
parser.y: Defines grammar rules and semantic actions
Symbol Table: Tracks variables and their usage
Error Handling: Detects syntax and semantic errors
Statistics: Reports compilation metrics


Compilation Output-
The compiler provides detailed output including:
1.Token recognition
2.Variable declarations
3.Expression evaluation
4.Symbol table display
5.Compilation statistics
6.Error warnings

