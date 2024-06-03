#include <stdio.h>

int binarySearch(int array[], int size, int key) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (array[mid] == key)
            return mid; // Element found, return its index

        if (array[mid] < key)
            low = mid + 1; // Continue searching in the right half
        else
            high = mid - 1; // Continue searching in the left half
    }

    return -1; // Element not found
}

int main() {
    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(array) / sizeof(array[0]);
    int key, index;

    // Input
    printf("Enter the number to search: ");
    scanf("%d", &key);

    // Perform binary search
    index = binarySearch(array, size, key);

    // Output
    if (index != -1)
        printf("Element %d found at position %d.\n", key, index + 1);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}

