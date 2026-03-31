// Implement Binary Trees& the transversals
// Insert, traverse and delete(Leaf node in case of BT)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// --- Level Order Insertion using a Simple Queue ---
void insertBT(struct Node** root, int data) {
    struct Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Temporary queue for level order traversal
    struct Node* queue[100]; 
    int front = 0, rear = 0;
    queue[rear++] = *root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        } else {
            queue[rear++] = temp->right;
        }
    }
}

// --- Delete Leaf Node ---
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->data == key && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);
    return root;
}

// --- Traversals ---
void inOrder(struct Node* root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- Binary Tree Menu ---\n1. Insert\n2. Delete Leaf\n3. In-Order Traverse\n4. Pre-Order\n5. Post-Order\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                insertBT(&root, val);
                break;
            case 2:
                printf("Leaf Value to Delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                break;
            case 3: inOrder(root); printf("\n"); break;
            case 4: preOrder(root); printf("\n"); break;
            case 5: postOrder(root); printf("\n"); break;
            case 0: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}