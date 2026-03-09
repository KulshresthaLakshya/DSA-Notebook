#include <stdio.h>
#include <stdlib.h>

// 1. Define the Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// 2. Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// 3. Function to insert at the end of the list
void append(struct Node** head_ref, int value) {
    struct Node* newNode = createNode(value);
    
    // If the list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Otherwise, traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Adjust pointers for both directions
    last->next = newNode;
    newNode->prev = last;
}

// 4. Function to traverse and print forward
void printForward(struct Node* node) {
    while (node != NULL) {
        printf("%d%s", node->data, node->next ? " " : "");
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, value;
    struct Node* head = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        append(&head, value);
    }

    printForward(head);

    return 0;
}
