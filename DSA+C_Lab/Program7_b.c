/*2.	Write a C program to implement a Queue using a Linked List. The program should support the following operations using separate functions:
(i)	Enqueue (Insert): Insert an element into the Queue.
(ii)	Dequeue (Delete): Remove an element from the Queue.
(iii)	Display: Display all elements of the Queue.
(iv)	Peek: Display the front element of the Queue.
*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

// Function Declaration
void enqueue(int value);
void dequeue();
void display();
void peek();

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linked List Queue Operations ---");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Peek");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
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
                printf("\nInvalid choice!");
        }
    }
    return 0;
}

// (i) Enqueue: Add to the rear
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed!");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n%d enqueued to queue.", value);
}

// (ii) Dequeue: Remove from the front
void dequeue() {
    if (front == NULL) {
        printf("\nQueue Underflow! Queue is empty.");
        return;
    }
    struct Node* temp = front;
    printf("\nDequeued element: %d", front->data);
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
}

// (iii) Display: Traverse from front to rear
void display() {
    if (front == NULL) {
        printf("\nQueue is empty.");
    } else {
        struct Node* temp = front;
        printf("\nQueue elements: ");
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// (iv) Peek: Show the front element
void peek() {
    if (front == NULL) {
        printf("\nQueue is empty.");
    } else {
        printf("\nFront element: %d\n", front->data);
    }
}