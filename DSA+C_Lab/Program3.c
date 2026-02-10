#include <stdio.h>
#include <stdlib.h>

//Declaring Structure for node
struct Node 
{
    int info;
    struct Node* next;
};

//Declaring Head
struct Node* head = NULL;

//INSERT IN THE BEGAINNING FUNTION
void insertAtBeginning() {
    int value;
    printf("Enter value to insert at beginning: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = head;
    head = newNode;
}

// INSERT AT THE END FUNCTION
void insertAtEnd() {
    int value;
    printf("Enter value to insert at end: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// INSERT IN THE MIDDLE FUNTION
void insertAfterRandom() {
    int target, value;
    printf("Enter the element to insert after: ");
    scanf("%d", &target);
    
    struct Node* temp = head;
    while (temp != NULL && temp->info != target) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found.\n", target);
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);
    
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

// DELETE FROM THE BEGAINNING FUNTION
void deleteFromBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

//  DELETE FROM THE END FUNTION
void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

//  DELETE AFTER THE VALUE FUNTION
void deleteAfterRandom() {
    int target;
    printf("Enter the element to delete after: ");
    scanf("%d", &target);

    struct Node* temp = head;
    while (temp != NULL && temp->info != target) {
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        struct Node* toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
    } else {
        printf("No element exists after %d.\n", target);
    }
}

// TRANSVERSE (PRINTING) FUNCTION
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Main Body
int main() 
{
    int choice;

    do 
    {
        printf("\n--------------Singly Linked List Menu------------");
        printf("\nFOR INSERTING");
        printf("\n1. Insert Beginning\t2. Insert End\t3. Insert After Element\t");
        printf("\nFOR DELETING");
        printf("\n4. Delete Beginning\t5. Delete End\t6. Delete After Element\t");
        printf("\nFOR DISPLAYNG");
        printf("\n7. Display List\t\t8. Exit");

        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        switch(choice) 
        {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAfterRandom(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteAfterRandom(); break;
            case 7: display(); break;
            case 8: printf("Exiting program...\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } 
    while(choice != 8);
    return 0;
}