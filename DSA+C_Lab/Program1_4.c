/*
1.1) Inputting & Printing Array
1.2) Inserting in Array
1.3) Deletion in Array
1.4) Array using dynamic m/m allocation(sum of all elements of an Array) 
*/

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, i, sum = 0;
    int *a;

    printf("Enter size of array: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        sum = sum + a[i];
    }

    printf("Sum of elements = %d", sum);
    free(a);
    return 0;
}