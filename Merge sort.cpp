#include <stdio.h>

// Function to merge two subarrays of array[].
// First subarray is array[l..m]
// Second subarray is array[m+1..r]
void merge(int array[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    // Merge the temporary arrays back into array[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int array[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(array, l, m);
        mergeSort(array, m + 1, r);

        // Merge the sorted halves
        merge(array, l, m, r);
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

    mergeSort(array, 0, size - 1);

    printf("Sorted array: \n");
    printArray(array, size);

    return 0;
}

