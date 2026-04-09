#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* left_lca = findLCA(root->left, n1, n2);
    struct Node* right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca) return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    struct Node* root = newNode(arr[0]);
    queue[0] = root;
    
    int head = 0, tail = 1, i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
      
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[tail++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[tail++] = curr->right;
        }
        i++;
    }
    free(queue);
    return root;
}

int main() {
    int n, n1, n2;
    if (scanf("%d", &n) != 1) return 0;
    
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);

    struct Node* root = buildTree(arr, n);
    struct Node* lca = findLCA(root, n1, n2);

    if (lca) printf("%d\n", lca->data);

    free(arr);
    return 0;
}
