#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
void enqueue(int element);
void dequeue();
void display();

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Queue Operations ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid selection.");
        }
    }
    return 0;
}

// (i) Insert (Enqueue)
void enqueue(int element) {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        printf("\nQueue is Full (Overflow)!");
    } else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        printf("\nInserted -> %d", element);
    }
}

// (ii) Delete (Dequeue)
void dequeue() {
    if (front == -1) {
        printf("\nQueue is Empty (Underflow)!");
    } else {
        int element = items[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        printf("\nDeleted element -> %d", element);
    }
}

// (iii) Display
void display() {
    int i;
    if (front == -1) {
        printf("\nNothing to display.");
    } else {
        printf("\nFront -> %d", front);
        printf("\nItems -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", items[i]);
        }
        printf("%d ", items[i]);
        printf("\nRear -> %d\n", rear);
    }
}