#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE];
    int size, i, key;

    // Input
    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Key to search
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Linear search
    int found = 0;
    for (i = 0; i < size; i++) {
        if (array[i] == key) {
            found = 1;
            printf("Element %d found at position %d.\n", key, i + 1);
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

