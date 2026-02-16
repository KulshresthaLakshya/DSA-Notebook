/* Write a recursive function fib(n) to compute the n-th Fibonacci number where fib(0)=0 and fib(1)=1.

Input:
- Single integer n

Output:
- Print the n-th Fibonacci number

Example:  Input:6,Output:8

Explanation: Sequence: 0,1,1,2,3,5,8 at positions 0,1,2,3,4,5,6 */

#include <stdio.h>
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Rule: Current = (Previous) + (One before previous)
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int N,n;
    printf("Enter the number of terms: ");
    scanf("%d", &N);
    n = N-1;

    if (n < 0) 
    {
        printf("Invalid input. Please enter a positive number.\n");
    } 
    else 
    {
        printf("Fibonacci Series: ");
        for (int i = 0; i <= n; i++) 
        {
            printf("%d", fib(i));
            if (i < n) 
            {
                printf(", ");
            }
        }
    }

    return 0;
}