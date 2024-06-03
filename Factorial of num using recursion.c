#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    int num;
    unsigned long long fact;

    // Input
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);

    // Error check for negative number
    if (num < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return 1; // Exit with error code
    }

    // Calculate factorial using recursion
    fact = factorial(num);
    printf("Factorial of %d = %llu\n", num, fact);

    return 0;
}

