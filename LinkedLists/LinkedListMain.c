#include <stdio.h>
#include <stdlib.h>
#include "LLBasic.h"

int main()
{   
    int LLSize;
    printf("Enter initial length of LinkedList: ");
    scanf("%d", &LLSize);

    struct LinkedList* firstNode = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    firstNode->nextNode = NULL;

    createLinkedList(firstNode, LLSize);

    traverseLinkedList(firstNode);

    // addNodeAtTheEndOfLL(firstNode);

    // firstNode = addNodeAtTheBeginigOfLL(firstNode);

    // addNodeAtIndexOfLL(firstNode);

    firstNode = reverseLinkedList(firstNode);

    traverseLinkedList(firstNode);

    deleteLinkedList(firstNode);

    return 0;
}