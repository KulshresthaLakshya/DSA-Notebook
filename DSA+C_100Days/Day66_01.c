#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

bool isCycleUtil(int u) {
    if (!visited[u]) {
        visited[u] = true;
        recStack[u] = true;

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                if (!visited[v] && isCycleUtil(v))
                    return true;
                else if (recStack[v])
                    return true;
            }
        }
    }
    recStack[u] = false;
    return false;
}

bool hasCycle() {
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleUtil(i))
                return true;
        }
    }
    return false;
}

int main() {
    V = 4;
    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;
    adj[2][3] = 1;

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
