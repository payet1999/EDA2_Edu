#include <stdio.h>
#include <stdlib.h>
#include "headers/queue.h"


Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

int dequeue(Queue *q) {
    if (q->front == NULL) {
        return -1;
    }
    QueueNode *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return value;
}

// NOTE: Siempre esta bien poner comentarios con esta estructura en C para describir metodos (en todos obvio).
// Se usa esta nomenclatura para poder generar documentación de codigo a posteriori facilmente 
// con Doxygen o del estilo
/**
 * @brief Get size of a Queue object
 * @param q Queue object to be evaluated
 * @return Integer indicating Queue size
 */
int queueSize(Queue *q) {
    return q->size;
}

void freeQueue(Queue *q) {
    while (q->front != NULL) {
        dequeue(q);
    }
    free(q);
}
