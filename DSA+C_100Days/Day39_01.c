#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int arr[MAX_SIZE];
    int size;
} MinHeap;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *h, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (h->arr[index] < h->arr[parent]) {
            swap(&h->arr[index], &h->arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(MinHeap *h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void insert(MinHeap *h, int x) {
    if (h->size >= MAX_SIZE) return;
    h->arr[h->size] = x;
    heapifyUp(h, h->size);
    h->size++;
}

int peek(MinHeap *h) {
    if (h->size <= 0) return -1;
    return h->arr[0];
}

int extractMin(MinHeap *h) {
    if (h->size <= 0) return -1;
    int minVal = h->arr[0];

    h->arr[0] = h->arr[h->size - 1];
    h->size--;

    heapifyDown(h, 0);
    return minVal;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    MinHeap h = {.size = 0};

    for (int i = 0; i < n; i++) {
        char op[20];
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            insert(&h, val);
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek(&h));
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin(&h));
        }
    }

    return 0;
}
