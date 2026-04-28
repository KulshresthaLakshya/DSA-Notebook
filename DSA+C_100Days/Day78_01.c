#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 1; v <= n; v++)
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int key[MAX];
    bool mstSet[MAX];
    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);
}

int main() {
    int n, m;
    int graph[MAX][MAX] = {0};

    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        if (scanf("%d %d %d", &u, &v, &w) != 3) break;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    primMST(graph, n);

    return 0;
}
