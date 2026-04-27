#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

struct Node {
    int target;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];
int visit_count = 0;

void add_edge(int u, int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->target = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int v) {
    visited[v] = 1;
    visit_count++;
    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->target]) {
            dfs(temp->target);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }

    if (n > 0) {
        dfs(1);
    }

    if (visit_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
