#include <stdio.h>
#include <stdlib.h>

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, isDirected;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    isDirected = 0; 
    int matrix[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        
        if (!isDirected) {
            matrix[v][u] = 1;
        }
    }
    printMatrix(n, matrix);
    return 0;
}
