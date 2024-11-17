#include <stdio.h>
#include <stdlib.h>

struct LinkedList{
    int data;
    struct LinkedList *nextNode;
};


struct LinkedList* createNode();

void createLinkedList(struct LinkedList* node, int size);

void traverseLinkedList(struct LinkedList* node);

void deleteLinkedList(struct LinkedList* node);

void addNodeAtTheEndOfLL(struct LinkedList* node);

struct LinkedList* addNodeAtTheBeginigOfLL(struct LinkedList* node);

void addNodeAtIndexOfLL(struct LinkedList* node);

struct LinkedList* reverseLinkedList(struct LinkedList* node);