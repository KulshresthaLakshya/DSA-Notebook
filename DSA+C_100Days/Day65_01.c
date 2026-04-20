#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int V, E;

bool isCycleUtil(int u, int parent) {
    visited[u] = true;

    for (int v = 0; v < V; v++) {
        if (adj[u][v]) {
            if (!visited[v]) {
                if (isCycleUtil(v, u))
                    return true;
            }
            else if (v != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle() {
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleUtil(i, -1))
                return true;
        }
    }
    return false;
}

int main() {
    V = 3;
    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;

    if (isCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
