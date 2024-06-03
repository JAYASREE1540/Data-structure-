#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted with node i
// n is the size of heap
void heapify(int array[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&array[i], &array[largest]);

        // Recursively heapify the affected sub-tree
        heapify(array, n, largest);
    }
}

// Function to perform heap sort
void heapSort(int array[], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&array[0], &array[i]);

        // Call max heapify on the reduced heap
        heapify(array, i, 0);
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

    heapSort(array, size);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}

