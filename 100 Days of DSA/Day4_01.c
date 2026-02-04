/* Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5
Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays
*/
#include <stdio.h>
int main()
{
  int N;
  printf("Make an input for size of Array:\n");
  scanf("%d", &N);

  int a[N];
  printf("Fill in your Array\n");
  for(int i=0; i<N; i++)
  {
     printf("Position %d: \n", i+1);
     scanf("%d", &a[i]);
  }

  printf("Reverse Array is\n");
  for(int i=(N-1); i>=0; i--)
  {
    printf("%d ", a[i]);
  }
  return 0;
}