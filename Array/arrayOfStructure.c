#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct node {
    // int key;
    char* value;
    struct node *next;
} node;

int findHash(char* value) {
    int asciNum = (int)value[0];
    return (asciNum % TABLE_SIZE);
}

node* init_hash_table(int nEntries) {
    node* HashTableNode = (node*)malloc(nEntries * sizeof(node));

    if (HashTableNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nEntries; i++) {
        // (*(HashTableNode+i)).key = -1;
        (*(HashTableNode+i)).value = NULL;
        (*(HashTableNode+i)).next = NULL;
    }

    return HashTableNode;
}

void printHashTable(node* HashTableNode, int nEntries) {
    for (int i = 0; i < nEntries; i++) {
        // printf("HashTableNode[%d]->key : %d, HashTableNode[%d]->value : %s\n", 
        //        i, (*(HashTableNode+i)).key, i, (*(HashTableNode+i)).value);
        printf("HashTableNode[%d]->value : %s\n", i, (*(HashTableNode+i)).value);
    }
}

void insertDataToHashTable(node* HashTableNode, int key, char* value){
    if(key < TABLE_SIZE){
        (*(HashTableNode+key)).value = value;
    }
}

bool searchDataInHashTable(node* HashTableNode, int key){
    if(key < TABLE_SIZE && (*(HashTableNode+key)).value != NULL){
        printf("value at key %i :>> %s\n", key, (*(HashTableNode+key)).value); 
        return true;        
    }
    return false;

}

int main(int argc, char *argv[]) {
    node* HashTable = init_hash_table(TABLE_SIZE);
    printHashTable(HashTable, TABLE_SIZE);

    char* values[] = {"Mohib", "Khan", "Pathan"};
    int arraySize = sizeof(values) / sizeof(values[0]);

    int key;

    for (int i = 0; i < arraySize; i++) {
        printf("Hash of \"%s\" : %d\n", values[i], findHash(values[i]));
        key = findHash(values[i]);
        insertDataToHashTable(HashTable, key, values[i]);
    }

    int keyHasValue = searchDataInHashTable(HashTable, 5);

    keyHasValue ? printf("Key already has some value\n") : printf("Key does not have any value\n");

    printHashTable(HashTable, TABLE_SIZE);


    free(HashTable);

    return EXIT_SUCCESS;
}
