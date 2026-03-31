#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int queue[MAX];
int front = 0, rear = -1;

void enqueue(int val) {
    queue[++rear] = val;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, i, temp;
    if (scanf("%d", &n) != 1) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        enqueue(temp);
    }
    for (i = 0; i < n; i++) {
        push(dequeue());
    }
    front = 0;
    rear = -1;
    for (i = 0; i < n; i++) {
        enqueue(pop());
    }

    for (i = front; i <= rear; i++) {
        printf("%d%s", queue[i], (i == rear ? "" : " "));
    }

    return 0;
}
