#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t* next;
} node_t;

typedef struct queue_t{
    node_t* front;
    node_t* rear;
} queue_t;

bool isEmpty(queue_t* queue){
    if (queue->front == NULL){
        return true;
    }
    return false;
}

queue_t* createQueque(){
    queue_t* queue = malloc(sizeof(queue_t));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(queue_t* queue, int data){
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = node;
        return;
    }

    queue->rear->next = node;
    queue->rear = node;
}

void dequeue(queue_t* queue){
    if (queue->front == NULL) {
        queue->rear = NULL;
        printf("Queue is empty!!");
    }
    node_t* removedNode = queue->front;
    queue->front = queue->front->next;

    printf("Removed Node with Data:>> %d \n", removedNode->data);
    free(removedNode);
}

void printQueueContent(queue_t* queue){
    node_t* node = queue->front;
    printf("Current queue contents :>>");
    while (node != NULL) {
        printf(" %d -> ", node->data);
        node = node->next;
    }
    printf(" NULL\n");
}

void peek(queue_t* queue){
    printf("Current queue front data :>> %d \n", queue->front->data);
}

int main (int argc, char *argv[]) {

    queue_t* queue = createQueque();

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);

    printQueueContent(queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);

    printQueueContent(queue);

    return EXIT_SUCCESS;
}