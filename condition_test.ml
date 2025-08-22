// Condition Test - Fixed Version
int x;
int y;
int temp;

x = 15;
y = 10;

if (x > y) {
    print(100);
}

if (x < y) {
    print(200);
} else {
    print(300);
}

if (x == y) {
    print(400);
}

// Instead of (x != y), use alternative logic
if (x == y) {
    print(0);
} else {
    print(500);
}

print(x);
print(y);
