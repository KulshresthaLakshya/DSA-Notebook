#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
// Function to delete the first occurrence of a key
void deleteKey(struct Node** head_ref, int key) 
{
    struct Node *temp = *head_ref, *prev = NULL;
    // Case 1: If the head node itself holds the key
    if (temp != NULL && temp->data == key) 
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    // Case 2: Search for the key to be deleted
    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }
    // Case 3: If key was not present in linked list
    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp); 
}
struct Node* buildList(int n) 
{
    if (n <= 0) return NULL;
    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) 
    {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) 
        {
            head = newNode;
            tail = head;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}
void printList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    int n, key;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* head = buildList(n);
  
    if (scanf("%d", &key) != 1) 
    {
        printList(head);
        return 0;
    }
    deleteKey(&head, key);
    printList(head);
    return 0;
}
