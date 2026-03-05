/*
You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). 
This array represents a permutation of the integers from 1 to n with one element missing. 
Your task is to identify and return the missing element.

Examples:
Input: arr[] = [1, 2, 3, 5]
Output: 4
Explanation: All the numbers from 1 to 5 are present except 4.

Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
Output: 6
Explanation: All the numbers from 1 to 8 are present except 6.

Input: arr[] = [1]
Output: 2
Explanation: Only 1 is present so the missing element is 2.

Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size() + 1
*/

#include <stdio.h>
int main()
{
    int N;
    printf("Provide the Amount of inclusive Inputs: ");
    scanf("%d", &N);
    int M=N-1;

    int a[M];
    printf("Input Integers\n");
    for(int i=0; i<N; i++)
    {
        printf(" ");
        scanf("%d", &a[i]);
    }

    int A=1;
    for(int i=0; i<N; i++)
    {
        if(a[i]==A)
        {
            A++;
            i = -1;
        }
    }
    printf("%d is missing\n", A);
    return 0;
}

/* CODE BY GEMINI

#include <stdio.h>
int main() {
    long long n; // Use long long to prevent overflow for large inputs
    printf("Enter the value of n (the range 1 to n): ");
    scanf("%lld", &n);

    // 1. Calculate the Expected Sum
    // Formula: (n * (n + 1)) / 2
    long long expectedSum = (n * (n + 1)) / 2;

    // 2. Calculate the Actual Sum
    long long actualSum = 0;
    int temp;
    
    printf("Enter the %lld elements:\n", n - 1);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &temp);
        actualSum += temp;
    }

    // 3. The difference is the missing number
    long long missingNumber = expectedSum - actualSum;

    printf("\nThe missing element is: %lld\n", missingNumber);

    return 0;
}*/
