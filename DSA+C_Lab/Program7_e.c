#include <stdio.h>
#include <stdlib.h>
#define MAX 10
typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

// Function Declaration
void initQueue(Queue *q);
void enqueue(Queue *q, int val);
int dequeue(Queue *q);
int isEmptyQueue(Queue *q);

Queue q1, q2;
void push(int val);
void pop();
void peek();
int isEmptyStack();
void display();

int main() {
    initQueue(&q1);
    initQueue(&q2);
    int choice, val;
    while (1) {
        printf("\n--- Stack using Two Queues ---");
        printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: 
                if (isEmptyStack()) printf("\nStack is empty.");
                else printf("\nStack is not empty.");
                break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}


void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue *q, int val) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->arr[++(q->rear)] = val;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) return -1;
    int val = q->arr[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return val;
}

int isEmptyQueue(Queue *q) {
    return (q->front == -1);
}
// (i) Push: Make push operation costly to maintain LIFO
void push(int val) {
    enqueue(&q2, val);
    while (!isEmptyQueue(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }
    Queue temp = q1;
    q1 = q2;
    q2 = temp;
    
    printf("\n%d pushed to stack.", val);
}

// (ii) Pop: Simply dequeue from q1
void pop() {
    if (isEmptyStack()) {
        printf("\nStack Underflow!");
        return;
    }
    printf("\nPopped element: %d", dequeue(&q1));
}

// (iii) Peek
void peek() {
    if (isEmptyStack()) {
        printf("\nStack is empty.");
    } else {
        printf("\nTop element: %d", q1.arr[q1.front]);
    }
}

// (iv) isEmpty
int isEmptyStack() {
    return isEmptyQueue(&q1);
}

// (v) Display
void display() {
    if (isEmptyStack()) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack elements (Top to Bottom): ");
        for (int i = q1.front; i <= q1.rear; i++) {
            printf("%d ", q1.arr[i]);
        }
        printf("\n");
    }
}