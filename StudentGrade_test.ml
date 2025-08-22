// Simple Grade Test - Fixed Version
int student1;
int student2;
int student3;
int total;
int average;
int passed;

// Initialize scores
student1 = 85;
student2 = 72;
student3 = 90;

// Print individual scores
print(student1);
print(student2);
print(student3);

// Calculate total directly
total = student1 + student2 + student3;
print(total);

// Calculate average
average = total / 3;
print(average);

// Count passed students (> 74 instead of >= 75)
passed = 0;
if (student1 > 74) {
    passed = passed + 1;
}
if (student2 > 74) {
    passed = passed + 1;
}
if (student3 > 74) {
    passed = passed + 1;
}

print(passed);

// Final evaluation (> 79 instead of >= 80)
if (average > 79) {
    print(100);
} else {
    print(50);
}
