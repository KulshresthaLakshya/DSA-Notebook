#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Hash Table structure
struct HashTable {
    struct Node* chain[SIZE];
};

// Initialize table
void init(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++)
        ht->chain[i] = NULL;
}

// Hash Function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert into Hash Table
void insert(struct HashTable* ht, int value) {
    int index = hashFunction(value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = ht->chain[index];
    ht->chain[index] = newNode;
}

// Display the table
void display(struct HashTable* ht) {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = ht->chain[i];
        printf("Index %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct HashTable ht;
    init(&ht);

    int keys[] = {15, 11, 25, 8, 32, 45, 12};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(&ht, keys[i]);
    }

    printf("Hash Table with Chaining:\n");
    display(&ht);

    return 0;
}