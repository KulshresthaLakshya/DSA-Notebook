#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

typedef struct {
    int data;
    int hd; 
    int level; 
} NodeInfo;

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        curr->left = newNode(arr[i++]);
        if (curr->left) queue[tail++] = curr->left;
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    return root;
}

void getNodesInfo(struct Node* root, int hd, int level, NodeInfo info[], int* size) {
    if (root == NULL) return;
    info[*size].data = root->data;
    info[*size].hd = hd;
    info[*size].level = level;
    (*size)++;
    getNodesInfo(root->left, hd - 1, level + 1, info, size);
    getNodesInfo(root->right, hd + 1, level + 1, info, size);
}

int compare(const void* a, const void* b) {
    NodeInfo* n1 = (NodeInfo*)a;
    NodeInfo* n2 = (NodeInfo*)b;
    if (n1->hd != n2->hd) return n1->hd - n2->hd;
    return n1->level - n2->level;
}

void printVerticalOrder(struct Node* root, int n) {
    NodeInfo* info = (NodeInfo*)malloc(sizeof(NodeInfo) * n);
    int size = 0;
    getNodesInfo(root, 0, 0, info, &size);

    qsort(info, size, sizeof(NodeInfo), compare);

    for (int i = 0; i < size; i++) {
        printf("%d", info[i].data);
        if (i + 1 < size && info[i].hd == info[i + 1].hd) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    printVerticalOrder(root, n);

    return 0;
}
