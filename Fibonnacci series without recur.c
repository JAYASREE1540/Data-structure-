#include <stdio.h>

int main() {
    int n, i;
    unsigned long long fib1 = 0, fib2 = 1, nextTerm;

    // Input
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    // Generating Fibonacci Series
    for (i = 1; i <= n; ++i) {
        printf("%llu, ", fib1);
        nextTerm = fib1 + fib2;
        fib1 = fib2;
        fib2 = nextTerm;
    }

    return 0;
}

