/*
Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3
*/
#include <stdio.h>
int main() 
{
    int n;
    printf("Enter Input for Size of Array: \n");
    scanf("%d", &n);
    
    int nums[n];
    for (int j = 0; j < n; j++) 
    {
        scanf("%d", &nums[j]);
    }

    int i = 0; 
    for (int j = 1; j < n; j++) 
    {
        if (nums[j] != nums[i]) 
        {
            i++;
            nums[i] = nums[j];
        }
    }

    for (int x = 0; x <= i; x++) 
    {
        printf("%d", nums[x]);
        if (x < i) printf(" "); 
    }
    printf("\n");
    return 0;
}