// Implement Binary Trees& the transversals
// Insert, traverse and delete(Leaf node in case of BT)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Traversals
void preOrder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

//Insertion (BST Logic)
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

//Delete Leaf Node
struct Node* deleteLeaf(struct Node* root, int key) {
    if (root == NULL) {
        printf("Node not found.\n");
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteLeaf(root->left, key);
    } else if (key > root->data) {
        root->right = deleteLeaf(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Leaf node deleted successfully.\n");
            return NULL;
        } else {
            printf("Error: The node is not a leaf node!\n");
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val, tChoice;

    do {
        printf("\n--- Binary Tree Operations ---");
        printf("\n1. Insert\n2. Delete Leaf\n3. Traverse\n0. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;
                
            case 2:
                printf("Enter leaf value to delete: ");
                scanf("%d", &val);
                root = deleteLeaf(root, val);
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                    break;
                }
                printf("\nChoose Traversal:\n1. Pre-order\n2. In-order\n3. Post-order\nChoice: ");
                scanf("%d", &tChoice);
                printf("Result: ");
                if (tChoice == 1) preOrder(root);
                else if (tChoice == 2) inOrder(root);
                else if (tChoice == 3) postOrder(root);
                printf("\n");
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 0);

    return 0;
}