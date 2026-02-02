/* Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left */
#include <stdio.h>
int main()
{
    int N, pos;
    printf("Input The size of Array: ");
    scanf("%d", &N);

    int a[N];
    for(int i=0; i<N; i++)
    {
        printf("Input value for Position %d index %d: ", i+1, i);
        scanf("%d", &a[i]);
    }

    printf("Current Array: ");
    for(int i=0; i<N; i++)
    {
        printf("[%d]", a[i]);
    }

    printf("\nEnter the Position to delete the element: ");
    scanf("%d", &pos);
    if(pos>=N)
    {
        printf("Invalid Position");
    }
    else
    {
        for(int i=(pos-1); i<N; i++)
        {
            a[i]=a[i+1];
        }
        printf("Updated array is: ");
        for(int i=0; i<N-1; i++)
        {
            printf("[%d]", a[i]);
        }
    }   
    printf("\n");
    return 0;
}
