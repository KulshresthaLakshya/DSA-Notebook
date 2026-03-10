#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to reverse a linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to check if palindrome
bool isPalindrome(struct Node* head) {
    if (head == NULL || head->next == NULL) return true;

    struct Node *slow = head, *fast = head;

    // 1. Find the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 2. Reverse the second half
    struct Node* secondHalf = reverseList(slow);
    struct Node* firstHalf = head;
    struct Node* copySecondHalf = secondHalf;

    // 3. Compare halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return false; 
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    int n, val;
    struct Node *head = NULL, *tail = NULL;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head) head = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    if (isPalindrome(head)) printf("Palindrome\n");
    else printf("Not a Palindrome\n");

    return 0;
}
