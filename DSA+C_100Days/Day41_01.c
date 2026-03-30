#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = q->front;
    printf("%d\n", temp->data);
    
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue();

    char operation[20];
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%s", operation);
        
        if (strcmp(operation, "enqueue") == 0) {
            scanf("%d", &value);
            enqueue(q, value);
        } else if (strcmp(operation, "dequeue") == 0) {
            dequeue(q);
        }
    }

    return 0;
}
