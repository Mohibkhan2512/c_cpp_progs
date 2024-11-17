#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct entry_t {
    char* key;
    char* value;
    struct entry_t *pNext;
} entry_t;

typedef struct hashTable_t {
    int size;
    int nEntries;
    //To hold address of memory block of size (i.e., pEntries = &Array[size*entry_t] )
    //pEntries = &Array[size*entry_t] )
    //*(pEntries+i) = pHashTable->pEntries[i] = Array[i] = (Array+i) = stores <&entry_t> )
    // **(pEntries+i) = *(pHashTable->pEntries[i]) = *(Array+i) = some entry_t with -> key, value and pNext
    struct entry_t **pEntries;
} hashTable_t;

int hashFunction(hashTable_t* pHashTable, char* key);

void initializeHashTable(hashTable_t* pHashTable, int size);

entry_t* createNewNode(char* key, char* value);

void insertDataInHashTable(hashTable_t* pHashTable, char* key, char* value);

void printAllEntriesInTable(hashTable_t* pHashTable);

void searchDataInHashTable(hashTable_t* pHashTable, char* key);

entry_t* freeAllEntriesInTableCell(entry_t* entry);

void freeAllEntriesInTable(hashTable_t* pHashTable);

hashTable_t* HashTable(int size);