/* Linear Search with Comparison Count

Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)
*/

#include <stdio.h>
int main()
{
    int N, index, count=0;
    printf("Provide the size of the Array: ");
    scanf("%d", &N);

    int a[N], search, found;
    printf("Input Integers\n");
    for(int i=0; i<N; i++)
    {
        printf(" ");
        scanf("%d", &a[i]);
    }
    printf("Enter integer that has to be found: \n");
    scanf("%d", &search);

    for(int i=0; i<N; i++)
    {
        count++;
        if(a[i]==search)
        {
            printf("Found at index %d", i);
            printf("\nComparison was done %d times", count);
            printf("\n");
            found = 1;
            break;
        }
    }
        if(found==0)
        {
            printf("Not found");
            printf("\n");
            printf("Comparisons = %d\n", count);
        }
    return 0;
}
