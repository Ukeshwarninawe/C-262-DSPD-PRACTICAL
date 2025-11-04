#include <stdio.h>

#define SIZE 7

int main() {
    int hashTable[SIZE];
    int i, key, n, index;

    // Initialize hash table with -1 (empty)
    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter %d keys: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &key);

        // Hash function
        index = key % SIZE;

        // Linear probing if collision occurs
        int start = index;
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == start) {
                printf("Hash table is full! Cannot insert %d\n", key);
                break;
            }
        }

        if (hashTable[index] == -1)
            hashTable[index] = key;
    }

    printf("\nFinal Hash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Slot %d : Empty\n", i);
        else
            printf("Slot %d : %d\n", i, hashTable[i]);
    }

    return 0;
}