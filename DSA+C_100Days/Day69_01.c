#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int target, weight;
    struct Node* next;
};
struct HeapNode {
    int v;
    int dist;
};
struct MinHeap {
    int size;
    int capacity;
    struct HeapNode** array;
};
struct Node* newNode(int target, int weight) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->target = target;
    node->weight = weight;
    node->next = NULL;
    return node;
}
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return minHeap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;

    if (smallest != idx) {
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

struct HeapNode* extractMin(struct MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    struct HeapNode* root = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void insertMinHeap(struct MinHeap* minHeap, int v, int dist) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->v = v;
    node->dist = dist;
    minHeap->array[minHeap->size] = node;
    int i = minHeap->size++;
    while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        swapHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void dijkstra(struct Node* adj[], int V, int src) {
    int dist[V];
    for (int i = 0; i < V; ++i) dist[i] = INT_MAX;

    struct MinHeap* minHeap = createMinHeap(V * V); 
    dist[src] = 0;
    insertMinHeap(minHeap, src, dist[src]);

    while (minHeap->size != 0) {
        struct HeapNode* heapNode = extractMin(minHeap);
        int u = heapNode->v;

        struct Node* temp = adj[u];
        while (temp != NULL) {
            int v = temp->target;
            if (dist[u] != INT_MAX && temp->weight + dist[u] < dist[v]) {
                dist[v] = dist[u] + temp->weight;
                insertMinHeap(minHeap, v, dist[v]);
            }
            temp = temp->next;
        }
        free(heapNode);
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i) printf("%d \t\t %d\n", i, dist[i]);
}
