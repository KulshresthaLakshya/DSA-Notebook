#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int u, v, weight;
};

void bellmanFord(int n, int m, struct Edge edges[], int src) {
    int dist[n];

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Relax all edges (n - 1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return;
        }
    }

    // Step 4: Output distances
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}

int main() {
    int n, m, src;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    scanf("%d", &src);
    bellmanFord(n, m, edges, src);

    return 0;
}
