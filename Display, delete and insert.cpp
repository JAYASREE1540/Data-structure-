#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice, position, element, i;

    while (1) {
        // Menu
        printf("\nArray Operations Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert
                if (size >= MAX_SIZE) {
                    printf("Error: Array is full. Cannot insert.\n");
                    break;
                }
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                if (position < 0 || position > size) {
                    printf("Error: Invalid position.\n");
                    break;
                }
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                for (i = size; i > position; i--) {
                    array[i] = array[i - 1];
                }
                array[position] = element;
                size++;
                printf("Element inserted successfully.\n");
                break;

            case 2: // Delete
                if (size == 0) {
                    printf("Error: Array is empty. Cannot delete.\n");
                    break;
                }
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("Error: Invalid position.\n");
                    break;
                }
                for (i = position; i < size - 1; i++) {
                    array[i] = array[i + 1];
                }
                size--;
                printf("Element deleted successfully.\n");
                break;

            case 3: // Display
                if (size == 0) {
                    printf("Array is empty.\n");
                    break;
                }
                printf("Array elements: ");
                for (i = 0; i < size; i++) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;

            case 4: // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Error: Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}

