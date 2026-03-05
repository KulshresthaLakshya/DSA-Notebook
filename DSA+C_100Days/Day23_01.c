#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}
struct Node* buildList(int count) {
    if (count == 0) return NULL;
    int val;
    scanf("%d", &val);
    struct Node* head = createNode(val);
    struct Node* current = head;
    for (int i = 1; i < count; i++) {
        scanf("%d", &val);
        current->next = createNode(val);
        current = current->next;
    }
    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d%s", head->data, head->next ? " " : "");
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 0;
    struct Node* list1 = buildList(n);
    
    if (scanf("%d", &m) != 1) return 0;
    struct Node* list2 = buildList(m);

    struct Node* mergedHead = mergeLists(list1, list2);
    printList(mergedHead);

    return 0;
}
