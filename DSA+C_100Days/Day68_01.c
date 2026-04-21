#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = -1;
int n;

void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

void kahnsAlgorithm() {
    int topo_order[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (adj[j][i]) {
                indegree[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    while (front <= rear) {
        int u = dequeue();
        topo_order[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    enqueue(v);
                }
            }
        }
    }

    if (count < n) {
        printf("Error: The graph contains a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Ordering (Kahn's): ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    kahnsAlgorithm();

    return 0;
}
