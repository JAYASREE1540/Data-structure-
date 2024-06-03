#include <stdio.h>

int main() {
    int numbers[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 101};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Odd numbers: ");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 != 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    printf("Even numbers: ");
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            printf("%d ", numbers[i]);
        }
    }
    printf("\n");

    return 0;
}

