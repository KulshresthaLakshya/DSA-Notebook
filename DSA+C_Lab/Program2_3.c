/*
2.1) Inputing & Printing 2D Array
2.2) Multiplication of 2, 2D Arrays
2.3) Printing Row & column SUM of 2D Matrix
2.4) Create Structure Student with following: SAP iD, Name, CGPA & print SAP ID of people with CGPA>=7
*/
#include <stdio.h>
int main() {
    int N, M;
    printf("Provide the Rows of the Array: ");
    scanf("%d", &N);
    printf("Provide the Columns of the Array: ");
    scanf("%d", &M);

    int a[N][M];

    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n--- Row Sums ---\n");
    for(int i=0; i<N; i++) {
        int rowSum = 0;
        for(int j=0; j<M; j++) {
            rowSum += a[i][j];
        }
        printf("Sum of Row %d: %d\n", i, rowSum);
    }

    printf("\n--- Column Sums ---\n");
    for(int j=0; j<M; j++) {
        int colSum = 0;
        for(int i=0; i<N; i++) {
            colSum += a[i][j];
        }
        printf("Sum of Column %d: %d\n", j, colSum);
    }

    return 0;
}