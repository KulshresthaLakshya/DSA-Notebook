#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Deque;

void initDeque(Deque *dq) {
    dq->front = dq->rear = NULL;
    dq->size = 0;
}

bool isEmpty(Deque *dq) {
    return dq->size == 0;
}

void pushFront(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void pushBack(Deque *dq, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (isEmpty(dq)) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

void popFront(Deque *dq) {
    if (isEmpty(dq)) return;

    Node *temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }

    free(temp);
    dq->size--;
}

void popBack(Deque *dq) {
    if (isEmpty(dq)) return;

    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }

    free(temp);
    dq->size--;
}

int getFront(Deque *dq) {
    return isEmpty(dq) ? -1 : dq->front->data;
}

int getBack(Deque *dq) {
    return isEmpty(dq) ? -1 : dq->rear->data;
}

void display(Deque *dq) {
    Node *curr = dq->front;
    printf("Deque: ");
    while (curr) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    Deque myDeque;
    initDeque(&myDeque);

    pushBack(10);
    pushBack(20);
    pushFront(5);
    
    display(&myDeque);

    printf("Front: %d\n", getFront(&myDeque));
    printf("Size: %d\n", myDeque.size);

    popBack(&myDeque);
    display(&myDeque);

    return 0;
}
