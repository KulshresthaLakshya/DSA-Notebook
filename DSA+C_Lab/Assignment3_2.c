#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else node->right = insert(node->right, data);
    return node;
}

int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int arr[] = {50, 15, 62, 5, 20, 58, 91, 3, 8, 37, 60, 24};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i < n; i++) root = insert(root, arr[i]);

    printf("Root: %d\n", root->data);
    printf("Nodes in Left Subtree: %d\n", countNodes(root->left));
    printf("Nodes in Right Subtree: %d\n", countNodes(root->right));

    return 0;
}