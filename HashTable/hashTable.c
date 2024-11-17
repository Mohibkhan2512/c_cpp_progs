// Uncomment line 1 to 23 to run as standalone program

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>
// #include <string.h>


// typedef struct entry_t {
//     char* key;
//     char* value;
//     struct entry_t *pNext;
// } entry_t;

// typedef struct hashTable_t {
//     int size;
//     int nEntries;
//     //To hold address of memory block of size (i.e., pEntries = &Array[size*entry_t] )
//     //pEntries = &Array[size*entry_t] )
//     //*(pEntries+i) = pHashTable->pEntries[i] = Array[i] = (Array+i) = stores <&entry_t> )
//     // **(pEntries+i) = *(pHashTable->pEntries[i]) = *(Array+i) = some entry_t with -> key, value and pNext
//     struct entry_t **pEntries;
// } hashTable_t;

#include "hashTable.h"


int hashFunction(hashTable_t* pHashTable, char* key) {
    int entryIndex;
    int sum = 0, factor = 31;
    for (int i = 0; i < strlen(key); i++) {
 
        // sum = sum + (ascii value of
        // char * (primeNumber ^ x))...
        // where x = 1, 2, 3....n
        sum = ((sum % pHashTable->size)
               + (((int)key[i]) * factor) % pHashTable->size)
              % pHashTable->size;
 
        // factor = factor * prime
        // number....(prime
        // number) ^ x
        factor = ((factor % __INT16_MAX__)
                  * (31 % __INT16_MAX__))
                 % __INT16_MAX__;
    }
 
    entryIndex = sum;
    return entryIndex;
}

void initializeHashTable(hashTable_t* pHashTable, int size) {
    pHashTable->size = size;
    pHashTable->nEntries = 0;
    
    //assign address of memory block of size (i.e., 
    //pEntries = &Array[size*entry_t] )
    //*(pEntries+i) = pHashTable->pEntries[i] = Array[i] = (Array+i) = <&entry_t> initially NULL )
    // **(pEntries+i) = *(pHashTable->pEntries[i]) = *(Array+i) = some entry with -> key, value and pNext
    pHashTable->pEntries = (entry_t**)malloc(pHashTable->size*sizeof(entry_t**));

    for (int i = 0; i < pHashTable->size; i++) {
        //same as pHashTable->*(pEntries+i) -> i corresponds to 
        //address to entry_t <i.e, &entry_t> (initially NULL) 
        //for each memory block in HahTable
        pHashTable->pEntries[i] = NULL; 
    }
}

entry_t* createNewNode(char* key, char* value) {
    entry_t* entry = (entry_t*)malloc(sizeof(entry_t*));
    entry->key = key;
    entry->value = value;
    entry->pNext = NULL;

    return entry;
}

void insertDataInHashTable(hashTable_t* pHashTable, char* key, char* value) {
    int entryIndex = hashFunction(pHashTable, key);
    printf("Key: %s mapped to index %d in hash table: \n", key, entryIndex);
    
    if (pHashTable->pEntries[entryIndex] == NULL) {
        pHashTable->pEntries[entryIndex] = createNewNode(key, value);
        return;
    }

    // If there is already an entry at pHashTable->pEntries[entryIndex]
    entry_t* curEntry = pHashTable->pEntries[entryIndex];
    while (curEntry->pNext != NULL) {
        curEntry = curEntry->pNext;
    }
    // Insert the new node at the end of the list
    curEntry->pNext = createNewNode(key, value);
}

void printAllEntriesInTable(hashTable_t* pHashTable) {
    printf("========================\n");
    printf("=======Hash Table=======\n");
    for (int i = 0; i < pHashTable->size; i++) {
        if (pHashTable->pEntries[i] != NULL) {
            entry_t* entry = pHashTable->pEntries[i];
            printf("Slot[%i] ----- ", i);
            while (entry != NULL) {
                printf("<key: %s, value: %s> ", entry->key, entry->value);
                entry = entry->pNext;
            }
            printf("\n"); // Add a newline after each slot
        }
    }
    printf("========================\n");
}

void searchDataInHashTable(hashTable_t* pHashTable, char* key) {
    int entryIndex = hashFunction(pHashTable, key);
    entry_t* curEntry = pHashTable->pEntries[entryIndex];
    bool keyFound = false;

    while(curEntry != NULL) {
        if(curEntry->key == key){
            printf("Found key in HashTable: <key: %s, value: %s> \n", curEntry->key, curEntry->value);
            keyFound = true;
            break;
        }
        curEntry = curEntry->pNext;
    }

    // If no key found in the hashMap for a given key
    if (keyFound == false) {
        printf("key: %s is not present in HashTable.\n", key);
    }
}

entry_t* freeAllEntriesInTableCell(entry_t* entry) {
    if (entry == NULL) {
        return NULL;
    }
    if (entry->pNext != NULL) {
        entry->pNext = freeAllEntriesInTableCell(entry->pNext);
    }
    free(entry);
    return NULL;
}

void freeAllEntriesInTable(hashTable_t* pHashTable) {
    for (int i = 0; i < pHashTable->size; i++) {
        if (pHashTable->pEntries[i] != NULL) {
            freeAllEntriesInTableCell(pHashTable->pEntries[i]);
            pHashTable->pEntries[i] = NULL; // Set the entry to NULL after freeing
        }
    }
}

hashTable_t* HashTable(int size) {
    hashTable_t* pHashTable = (hashTable_t*)malloc(sizeof(hashTable_t*));
    initializeHashTable(pHashTable, size);

    return pHashTable;
}

// Uncomment to run as standalone program
// int main(int argc, char *argv[]) { 
//     hashTable_t* pHashTable = (hashTable_t*)malloc(sizeof(hashTable_t*));
//     int size = 5;
//     initializeHashTable(pHashTable, size);

//     insertDataInHashTable(pHashTable, "1", "Anjali");
//     insertDataInHashTable(pHashTable, "2", "Vartika");
//     insertDataInHashTable(pHashTable, "3", "Manish");
//     insertDataInHashTable(pHashTable, "4", "Mohib");
//     insertDataInHashTable(pHashTable, "5", "Mayank");

//     printAllEntriesInTable(pHashTable);

//     searchDataInHashTable(pHashTable, "1");
//     searchDataInHashTable(pHashTable, "2");
//     searchDataInHashTable(pHashTable, "3");
//     searchDataInHashTable(pHashTable, "4");
//     searchDataInHashTable(pHashTable, "5");
 
//     // Key is not presnt in hash table
//     searchDataInHashTable(pHashTable, "randomKey");

//     freeAllEntriesInTable(pHashTable); // free all entries in each slot

//     free(pHashTable->pEntries); // free (i.e., pEntries = &Array[sizeOfTable*entry_t] )
//     free(pHashTable); // free pHashTable pointer

//     return EXIT_SUCCESS;
// }