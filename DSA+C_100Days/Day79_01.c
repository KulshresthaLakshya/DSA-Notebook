#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minDistance(int dist[], bool visited[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++)
        if (visited[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int n, int src) {
    int dist[MAX];
    bool visited[MAX];

    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d%c", dist[i], (i == n ? '\n' : ' '));
    }
}

int main() {
    int n, m, src;
    int graph[MAX][MAX] = {0};

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    scanf("%d", &src);
    dijkstra(graph, n, src);

    return 0;
}
