#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int post[], int inStrt, int inEnd, int* postIndex) {
    if (inStrt > inEnd) return NULL;

    struct Node* node = newNode(post[(*postIndex)--]);

    if (inStrt == inEnd) return node;

    int inIndex = search(in, inStrt, inEnd, node->data);

    node->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(in, post, inStrt, inIndex - 1, postIndex);

    return node;
}

void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int in[] = {8, 6, 9, 4, 7, 2, 5, 1, 3};
    int post[] = {8, 9, 6, 7, 4, 5, 2, 3, 1};
    int n = sizeof(in) / sizeof(in[0]);
    int postIndex = n - 1;

    struct Node* root = buildTree(in, post, 0, n - 1, &postIndex);

    printf("Inorder traversal of constructed tree: \n");
    printInorder(root);
    return 0;
}