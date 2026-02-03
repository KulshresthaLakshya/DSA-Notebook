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
    printf("Provide the Rows of the 1st Array: ");
    scanf("%d", &N);
    printf("Provide the Columns of the 1st Array: ");
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

    int A,B;
    printf("Provide the Rows of the 2nd Array: ");
    scanf("%d", &A);
    printf("Provide the Columns of the 2nd Array: ");
    scanf("%d", &B);

    int b[A][B];
    for(int i=0; i<A; i++)
    {
        for(int j=0; j<B; j++)
        {
            printf("Provide the element for (i,j)=%d,%d: ", i,j);
            scanf("%d", &b[i][j]);
        }
    }
    //[N][M]*[A][B]
    if(N==B)
    {
        //Multiplication LOOP, To be Learned
        int c[M][A];
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < B; j++) 
            {
                c[i][j] = 0;
                for (int k = 0; k < M; k++) 
                {
                    c[i][j]=c[i][j]+a[i][k]*b[k][j];
                }
            }
        }
        printf("Multiplied Array is\n");
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                printf("[%d]", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrices Cannot be Multiplied\n");
    }
    return 0;
}