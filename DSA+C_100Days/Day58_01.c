#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) return NULL;

    struct Node* root = newNode(preorder[(*preIndex)++]);

    if (inStart == inEnd) return root;

    int inIndex = search(inorder, inStart, inEnd, root->data);

    root->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return root;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* preorder = (int*)malloc(sizeof(int) * n);
    int* inorder = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    free(preorder);
    free(inorder);
    return 0;
}
