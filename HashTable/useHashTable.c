#include "hashTable.h"

int main(int argc, char *argv[]) { 
    int size = 5;
    hashTable_t* pHashTable = HashTable(size);

    insertDataInHashTable(pHashTable, "1", "Anjali");
    insertDataInHashTable(pHashTable, "2", "Vartika");
    insertDataInHashTable(pHashTable, "3", "Manish");
    insertDataInHashTable(pHashTable, "4", "Mohib");
    insertDataInHashTable(pHashTable, "5", "Mayank");

    printAllEntriesInTable(pHashTable);

    searchDataInHashTable(pHashTable, "1");
    searchDataInHashTable(pHashTable, "2");
    searchDataInHashTable(pHashTable, "3");
    searchDataInHashTable(pHashTable, "4");
    searchDataInHashTable(pHashTable, "5");
 
    // Key is not presnt in hash table
    searchDataInHashTable(pHashTable, "randomKey");

    freeAllEntriesInTable(pHashTable); // free all entries in each slot

    free(pHashTable->pEntries); // free (i.e., pEntries = &Array[sizeOfTable*entry_t] )
    free(pHashTable); // free pHashTable pointer

    return EXIT_SUCCESS;
}