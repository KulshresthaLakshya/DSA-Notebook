#include <stdio.h>

int main() {
    int rows, cols;

    // 1. Get dimensions
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];

    // 2. Input the Matrix
    printf("Enter elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 3. Print Transposed Matrix
    // Notice: We loop up to 'cols' first, then 'rows'
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            // We swap the indices: [j][i] instead of [i][j]
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}