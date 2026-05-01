#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void insert(int value);
void hpify_mx(int i);
void del_root();
void bld_heap();
void hpify_dwn(int i);
void display();
void swap(int *a, int *b);

int heap[MAX];
int size = 0;
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Max Heap Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete Root\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                del_root();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

void insert(int value)
{
    if(size == MAX)
    {
        printf("Heap Overflow!\n");
        return;
    }
    heap[size] = value;
    size++;
    hpify_mx(size-1);
    printf("Inserted %d\n", value);
}

void hpify_mx(int i)
{
    while(i > 0 && heap[(i-1)/2] < heap[i])
    {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

void del_root()
{
    if(size == 0)
    {
        printf("Heap Underflow!\n");
        return;
    }
    printf("Deleted root: %d\n", heap[0]);
    heap[0] = heap[size-1];
    size--;
    bld_heap();
}

void bld_heap()
{
    for(int i = size/2-1; i >= 0; i--)
    {
        hpify_dwn(i);
    }
}

void hpify_dwn(int i)
{
    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;
    if(left < size && heap[left] > heap[largest])
        largest = left;
    if(right < size && heap[right] > heap[largest])
        largest = right;
    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);
        hpify_dwn(largest);
    }
}

void display()
{
    if(size == 0)
    {
        printf("Heap is empty!\n");
        return;
    }
    printf("Heap elements: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}