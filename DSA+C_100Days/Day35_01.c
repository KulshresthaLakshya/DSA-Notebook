#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = n;
    q->front = 0;
    q->rear = 0;
    q->arr = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear < q->capacity) {
        q->arr[q->rear] = value;
        q->rear++;
    }
}

void display(struct Queue* q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d%s", q->arr[i], (i == q->rear - 1 ? "" : " "));
    }
    printf("\n");
}

int main() {
    int n, value;

    if (scanf("%d", &n) != 1) return 0;

    struct Queue* q = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(q, value);
    }

    display(q);
    free(q->arr);
    free(q);

    return 0;
}
