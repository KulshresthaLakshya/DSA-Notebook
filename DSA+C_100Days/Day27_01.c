#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection
int getIntersection(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    struct Node *ptr1 = head1, *ptr2 = head2;

    if (c1 > c2) {
        d = c1 - c2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = c2 - c1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL;
  
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head1) head1 = tail1 = temp;
        else { tail1->next = temp; tail1 = temp; }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head2) head2 = tail2 = temp;
        else { tail2->next = temp; tail2 = temp; }
    }

    int result = getIntersection(head1, head2);

    if (result != -1) printf("%d\n", result);
    else printf("No Intersection\n");

    return 0;
}
