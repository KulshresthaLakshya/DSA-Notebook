#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int adj[MAX][MAX];
bool visited[MAX];
int n;

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS Implementation
void BFS(int start) {
    for(int i = 0; i < n; i++) visited[i] = false;

    enqueue(start);
    visited[start] = true;

    printf("BFS Traversal: ");
    while (front <= rear && front != -1) {
        int curr = dequeue();
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

// DFS Implementation
void DFS(int curr) {
    visited[curr] = true;
    printf("%d ", curr);

    for (int i = 0; i < n; i++) {
        if (adj[curr][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    BFS(0);

    for(int i = 0; i < n; i++) visited[i] = false;
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}