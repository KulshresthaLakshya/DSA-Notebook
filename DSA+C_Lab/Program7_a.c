/* 
1.	Write a C program to implement a Queue data structure using an array. The program should be modular and use separate functions for each operation.
(i)	Insert (Enqueue): Add an element to the Queue.
(ii)	Delete (Dequeue): Remove an element from the Queue.
(iii)	Display: Display all elements of the Queue.
(iv)	Peek: Display the front element of the Queue.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

// Function Declaration
void enqueue(int value);
void dequeue();
void display();
void peek();

int main() {
    int choice, value;
    while (1) 
    {
        printf("\n--- Queue Operations ---");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
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
                peek();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

// (i) Insert (Enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert %d", value);
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("\nInserted %d", value);
    }
}

// (ii) Delete (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Nothing to delete.");
    } else {
        printf("\nDeleted: %d", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// (iii) Display
void display() {
    if (front == -1) {
        printf("\nQueue is empty.");
    } else {
        printf("\nQueue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// (iv) Peek
void peek() {
    if (front == -1) {
        printf("\nQueue is empty.");
    } else {
        printf("\nFront element is: %d\n", queue[front]);
    }
}