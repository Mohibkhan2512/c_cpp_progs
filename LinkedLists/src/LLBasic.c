#include <stdio.h>
#include <stdlib.h>
#include "LLBasic.h"
// struct LinkedList{
//     int data;
//     struct LinkedList *nextNode;
// };

struct LinkedList* createNode(){
    struct LinkedList* node = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    node->nextNode = NULL;

    return node;
}

void createLinkedList(struct LinkedList* node, int size){
    int ipData;
    for(int i = 0; i < size; i++){
        printf("Enter data for node [%p, %d], index %d: ", node, (i+1), i);
        scanf("%d", &ipData); 
        if (i < (size - 1)){
            node->data = ipData;
            node->nextNode = createNode();
        }
        else{
            node->data = ipData;
        }  
        // printf("Data for node: %d\t", node->data);
        // printf("Next node for node: %p\n", node->nextNode);
        node = node->nextNode;
    }
}

void traverseLinkedList(struct LinkedList* node){
    printf("\n===================\nList: ");
    int index = 0;
    while(node != NULL){
        printf("| node: %d [%p], index: %d -> next: %p | ",  node->data, node, index, node->nextNode);
        node = node->nextNode;
        index++;
    }
}

void deleteLinkedList(struct LinkedList* node){
    printf("\n===================\nDeleting entire LinkedList\n");
    struct LinkedList* nextNodePointer = node;
    while(nextNodePointer != NULL){
        printf("nextNodePointer: %p\n", nextNodePointer);
        printf("Freeing node with data: %d\n", node->data);
        nextNodePointer = node->nextNode;
        free(node);
        node = nextNodePointer;
    }

}

void addNodeAtTheEndOfLL(struct LinkedList* node){
    printf("\n===================\nAdding node at the end of LinkedList\n");

    int ipData;
    while (node->nextNode != NULL){
        node = node->nextNode;
    }

    printf("\nEnter data for last node: ");
    scanf("%d", &ipData); 

    node->nextNode = createNode();
    node = node->nextNode;
    node->data = ipData;
    printf("\n===================\n");
}

struct LinkedList* addNodeAtTheBeginigOfLL(struct LinkedList* node){
    printf("\n===================\nAdding node at the beginig of LinkedList\n");
    int ipData;
    printf("\nEnter data for first node: ");
    scanf("%d", &ipData); 
    struct LinkedList* firstNode;
    firstNode = createNode();
    firstNode->nextNode = node;
    firstNode->data = ipData;

    return firstNode;
    printf("\n===================\n");
}

void addNodeAtIndexOfLL(struct LinkedList* node){
    printf("\n===================\nAdding node at a particular index of LinkedList\n");
    int ipData;
    int ipIndex;
    int curIndex = 0;

    printf("\nEnter index, data for node: ");
    scanf("%d, %d", &ipIndex, &ipData);

    printf("ipIndex: %d, ipData: %d\n", ipIndex, ipData);

    
    while (node->nextNode != NULL && curIndex < (ipIndex-1)){
        node = node->nextNode;
        curIndex++;
    }

    struct LinkedList* newNode;
    newNode = createNode();
    newNode->nextNode = node->nextNode;
    newNode->data = ipData;
    node->nextNode = newNode;
    // node = node->nextNode;
    // node->data = ipData;
    printf("\n===================\n");
}

struct LinkedList* reverseLinkedList(struct LinkedList* node){
    printf("\n===================\nReversingLinkedList");
    struct LinkedList* prevNodePointer = NULL;
    struct LinkedList* curNodePointer = node;
    struct LinkedList* nextNodePointer = NULL;
    
    while (curNodePointer != NULL){
        nextNodePointer = curNodePointer->nextNode;
        curNodePointer->nextNode = prevNodePointer;
        prevNodePointer = curNodePointer;
        curNodePointer = nextNodePointer;
    }
    node = prevNodePointer;
    return node;
    printf("\n===================\n");
}

