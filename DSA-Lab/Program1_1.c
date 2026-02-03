/*
1.1) Inputting & Printing Array
1.2) Inserting in Array
1.3) Deletion in Array
1.4) Array using dynamic m/m allocation(sum of all elements of an Array) 
*/

#include <stdio.h>
int main()
{
    int N;
    printf("Provide the size of the Array: ");
    scanf("%d", &N);

    int a[N];
    for(int i=0; i<N; i++)
    {
        printf("Input Values: ");
        scanf("%d", &a[i]);
    }
    printf("Array: ");
      for(int i=0; i<N; i++)
    {
        printf("[%d]", a[i]);
    }
    printf("\n");
    return 0;
}
