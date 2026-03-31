#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node * next;
};

struct node* head = NULL;

//INSERTION FUNCTIONS
void insertAtBeginning() {
    int item;
    printf("Provide the new element: ");
    scanf("%d", &item);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->info = item;

    if (head == NULL) {
        new_node->next = new_node;
        head = new_node;
    } else {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        new_node->next = head;
        temp->next = new_node;
        head = new_node;
    }
}

void insertAtEnd() {
    if (head == NULL) {
        insertAtBeginning();
        return;
    }
    int item;
    printf("Provide the new element: ");
    scanf("%d", &item);
    struct node* last_node = (struct node*) malloc(sizeof(struct node));
    last_node->info = item;

    struct node* ptr = head;
    while(ptr->next != head) {
        ptr = ptr->next;
    }
    ptr->next = last_node;
    last_node->next = head;
}

void insertAfterRandom() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int item, value;
    printf("Insert after which value? ");
    scanf("%d", &value);

    struct node *ptr = head;
    do {
        if (ptr->info == value) {
            printf("Provide the new element: ");
            scanf("%d", &item);
            struct node* new_node = (struct node*) malloc(sizeof(struct node));
            new_node->info = item;
            new_node->next = ptr->next;
            ptr->next = new_node;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);
    printf("Value not found!\n");
}

//DELETION FUNCTIONS
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* to_delete = head;
    if (head->next == head) {
        head = NULL;
    } 
    else
    {
        struct node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        head = head->next;
        temp->next = head;
    }
    free(to_delete);
    printf("Node deleted from beginning.\n");
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct node* to_delete = temp->next;
    temp->next = head;
    free(to_delete);
    printf("Node deleted from end.\n");
}

void deleteAfterRandom() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int value;
    printf("Delete after which value? ");
    scanf("%d", &value);

    struct node* temp = head;
    do {
        if (temp->info == value) {
            struct node* to_delete = temp->next;

            if (to_delete == head) {
                deleteFromBeginning(); 
                return;
            }
            
            temp->next = to_delete->next;
            free(to_delete);
            printf("Node deleted.\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Value not found!\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    printf("\nList: ");
    do {
        printf("%d -> ", temp->info);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Circular Linked List Menu ---");
        printf("\n1. Insert Beginning\t2. Insert End\t3. Insert After");
        printf("\n4. Delete Beginning\t5. Delete End\t6. Delete After");
        printf("\n7. Display\t\t0. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAfterRandom(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteAfterRandom(); break;
            case 7: display(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 0);
    return 0;
}