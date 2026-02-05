/*
2.1) Inputing & Printing 2D Array
2.2) Multiplication of 2, 2D Arrays
2.3) Printing Row & column of 2D Matrix
2.4) Create Structure Student with following: SAP iD, Name, CGPA & print SAP ID of people with CGPA>=7
*/

#include <stdio.h>
int main()
{
    int N,M;
    printf("Provide the Rows of the Array: ");
    scanf("%d", &N);
    printf("Provide the Columns of the Array: ");
    scanf("%d", &M);

    int a[N][M];
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            printf("Provide the element for (i,j)=%d,%d: ", i,j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");
    for(int i=0; i<N; i++)
    {
        printf("Row %d is: ", i);
        for(int j=0; j<M; j++)
        {
            printf("[%d]", a[i][j]);
        }
        printf("\n");
    }
    for(int i=0; i<N; i++)
    {
        printf("Column %d is: ", i);
        for(int j=0; j<M; j++)
        {
            printf("[%d]", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}