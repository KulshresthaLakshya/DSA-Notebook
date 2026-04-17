#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to find the index of a value in the inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

/* Recursive function to construct the tree. 
   'postIndex' is passed as a pointer to maintain its state across calls. */
struct Node* buildTree(int in[], int post[], int inStrt, int inEnd, int* postIndex) {
    if (inStrt > inEnd) return NULL;

    // Pick current node from Postorder traversal using postIndex
    struct Node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    // If node has no children, return
    if (inStrt == inEnd) return node;

    // Find index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, node->data);

    // Build Right subtree before Left subtree
    node->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(in, post, inStrt, inIndex - 1, postIndex);

    return node;
}

// Function to print preorder traversal (Root, Left, Right)
void printPreorder(struct Node* node) {
    if (node == NULL) return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;
    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printPreorder(root);
    printf("\n");

    return 0;
}
