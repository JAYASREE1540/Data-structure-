#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

// Define a structure for the hash table
struct HashTable {
    int* array;
    int capacity;
};

// Function to create a new hash table
struct HashTable* createHashTable() {
    struct HashTable* hashTable = (struct HashTable*)malloc(sizeof(struct HashTable));
    if (hashTable == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    hashTable->capacity = SIZE;
    hashTable->array = (int*)calloc(hashTable->capacity, sizeof(int));
    if (hashTable->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return hashTable;
}

// Function to calculate hash value
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert an element into the hash table using linear probing
void insert(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    // Linear probing
    while (hashTable->array[index] != 0) {
        index = (index + 1) % SIZE;
        if (index == originalIndex) {
            printf("Hash table is full. Unable to insert %d.\n", key);
            return;
        }
    }

    hashTable->array[index] = key;
    printf("Inserted %d at index %d\n", key, index);
}

// Function to search for an element in the hash table
bool search(struct HashTable* hashTable, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    // Linear probing
    while (hashTable->array[index] != key) {
        if (hashTable->array[index] == 0)
            return false;
        index = (index + 1) % SIZE;
        if (index == originalIndex)
            return false;
    }

    return true;
}

// Function to display the hash table
void display(struct HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->capacity; i++) {
        printf("%d: %d\n", i, hashTable->array[i]);
    }
}

int main() {
    struct HashTable* hashTable = createHashTable();

    insert(hashTable, 5);
    insert(hashTable, 25);
    insert(hashTable, 15);
    insert(hashTable, 35);
    insert(hashTable, 45);
    insert(hashTable, 55);
    insert(hashTable, 65);
    insert(hashTable, 75);
    insert(hashTable, 85);
    insert(hashTable, 95);
    insert(hashTable, 105); // This should fail, as the hash table is full

    display(hashTable);

    // Search for an element
    int searchKey = 45;
    if (search(hashTable, searchKey))
        printf("%d is found in the hash table.\n", searchKey);
    else
        printf("%d is not found in the hash table.\n", searchKey);

    // Search for an element not in the hash table
    int searchKeyNotInTable = 100;
    if (search(hashTable, searchKeyNotInTable))
        printf("%d is found in the hash table.\n", searchKeyNotInTable);
    else
        printf("%d is not found in the hash table.\n", searchKeyNotInTable);

    return 0;
}

