#include <stdio.h>

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 1;

    int matrix[m][n];
    int sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int min_dim = (m < n) ? m : n;

    for (int i = 0; i < min_dim; i++) {
        sum += matrix[i][i];
    }

    printf("%d\n", sum);

    return 0;
}
