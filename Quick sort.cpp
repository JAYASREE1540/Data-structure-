#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array using the last element as pivot
int partition(int array[], int low, int high) {
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (array[j] < pivot) {
            i++; // increment index of smaller element
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

// Function to implement quick sort
void quickSort(int array[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, array[pi] is now at right place
        int pi = partition(array, low, high);

        // Separately sort elements before partition and after partition
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Function to print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Original array: \n");
    printArray(array, size);

    quickSort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}

