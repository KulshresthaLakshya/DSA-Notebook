#include<stdio.h> [cite: 81]
#include<stdlib.h> [cite: 83]

struct node { [cite: 85]
    int data; [cite: 87]
    struct node *left; [cite: 89]
    struct node *right; [cite: 91]
}; [cite: 93]

struct node* create(int data) { [cite: 96]
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); [cite: 98]
    newnode->data = data; [cite: 100]
    newnode->left = NULL; [cite: 102]
    newnode->right = NULL; [cite: 104]
    return newnode; [cite: 106]
}

struct node* insert(struct node* root, int data) { [cite: 112]
    if (root == NULL) [cite: 113]
        return create(data); [cite: 114]
    
    if (data < root->data) [cite: 116]
        root->left = insert(root->left, data); [cite: 122]
    else [cite: 119]
        root->right = insert(root->right, data); [cite: 123]
    
    return root; [cite: 124]
}

void inorder(struct node* root) { [cite: 131]
    if (root != NULL) { [cite: 132]
        inorder(root->left); [cite: 133]
        printf("%d ", root->data); [cite: 134]
        inorder(root->right); [cite: 136]
    }
}

void preorder(struct node* root) { [cite: 145]
    if (root != NULL) {
        printf("%d ", root->data); [cite: 150]
        preorder(root->left); [cite: 152]
        preorder(root->right); [cite: 154]
    }
}

void postorder(struct node* root) { [cite: 161]
    if (root != NULL) {
        postorder(root->left); [cite: 163]
        postorder(root->right); [cite: 165]
        printf("%d ", root->data); [cite: 167]
    }
}

int main() { [cite: 174]
    struct node* root = NULL; [cite: 181]
    int choice, x; [cite: 182]
    
    while(1) { [cite: 183]
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n"); [cite: 184]
        scanf("%d", &choice); [cite: 185]
        
        switch(choice) { [cite: 188]
            case 1:
                printf("You selected Insert\n"); [cite: 198]
                scanf("%d", &x); [cite: 199]
                root = insert(root, x); [cite: 200]
                break;
            case 2:
                printf("You selected Inorder\n"); [cite: 203]
                inorder(root); [cite: 204]
                printf("\n"); [cite: 206]
                break;
            case 3:
                printf("You selected Preorder\n"); [cite: 221]
                preorder(root); [cite: 222]
                printf("\n"); [cite: 223]
                break;
            case 4:
                printf("You selected Postorder\n"); [cite: 226]
                postorder(root); [cite: 227]
                printf("\n"); [cite: 228]
                break;
            case 5:
                printf("Exiting...\n"); [cite: 231]
                exit(0); [cite: 232]
            default:
                printf("Invalid choice\n"); [cite: 234]
        }
    }
    return 0; [cite: 268]
}