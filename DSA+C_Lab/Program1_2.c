/*
1.1) Inputting & Printing Array
1.2) Inserting in Array
1.3) Deletion in Array
1.4) Array using dynamic m/m allocation(sum of all elements of an Array) 
*/

#include <stdio.h>
int main()
{
    int pos, new, N; 
    printf("Provide the size of the Array: ");
    scanf("%d", &N);

    int a[N+1];
    for(int i=0; i<N; i++)
    {
        printf("Input Values: ");
        scanf("%d", &a[i]);
    }
    printf("Current Array: ");
      for(int i=0; i<N; i++)
    {
        printf("[%d]", a[i]);
    }

    printf("\nProvide Index: ");
    scanf("%d", &pos);
    printf("Provide New element to be inserted on index %d: ",pos);
    scanf("%d", &new);

    for(int i=N; i>=pos; i--)
    {
        a[i+1]=a[i];
    }
    a[pos]=new;

    printf("Updated Array is: ");
    for(int i=0; i<N+1; i++)
    {
        printf("[%d]", a[i]);
    }
    printf("\n");

    return 0;
}