// Syntax Error Test File
int x;
float y;
int numbers[3];
int result;

// Valid code
x = 10;
y = 5.5;
numbers[0] = 100;

// Valid operations
result = x + 5;
print(result);
print(x);

// Intentional syntax errors (uncomment to test):
// missing_var = 50;        // Error: undeclared variable
// numbers[5] = 10;         // Error: array out of bounds  
// result = x / 0;          // Error: division by zero
// int bad syntax;          // Error: missing semicolon
// x == = 10;               // Error: invalid operator
