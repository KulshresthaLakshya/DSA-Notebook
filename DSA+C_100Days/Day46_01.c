#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

void printLevelOrder(struct Node* root) {
    if (root == NULL) return;

    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];
        
        printf("%d ", curr->data);

        if (curr->left != NULL) {
            queue[rear++] = curr->left;
        }
        if (curr->right != NULL) {
            queue[rear++] = curr->right;
        }
    }
    free(queue);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printLevelOrder(root);
    printf("\n");

    free(arr);
    return 0;
}
