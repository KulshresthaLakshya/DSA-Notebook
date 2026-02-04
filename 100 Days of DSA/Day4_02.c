/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.
Consider the number of elements in nums which are not equal to val be k, to get accepted, 
you need to do the following things:
Change the array nums such that the first k elements of nums contain the elements which are not equal to val. 
The remaining elements of nums are not important as well as the size of nums.
Return k.
 
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 
Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/

#include <stdio.h>
int main()
{
    int N;
    printf("Make an input for size of Array:\n");
    scanf("%d", &N);

    int nums[N];
    printf("Fill in your Array\n");
    for(int i=0; i<N; i++)
    {
        scanf("%d", &nums[i]);
    }

    int val;
    printf("Number to be deleted: ");
    scanf("%d", &val);

    int flag= 0;
    for(int i=0; i<N; i++)
    {
        flag++;
        if(nums[i]==val)
        {
            nums[i]= -1;
            flag--;
        }
    }

    printf("Output: [");
    for(int i=0; i<N; i++)
    {
        if(i<N-1)
        {
            if(nums[i]!=-1)
            {
                printf("%d,", nums[i]);
            }
            else
            {
                if(nums[i]==-1)
                {
                    printf("_,");
                }
            }
        }
        if(i==N-1)
        {
            if(nums[i]==-1)
            {
            printf("_]");
            }
            else
            {
                if(nums[i]!=-1)
                printf("%d",nums[i]);
                printf("]");
            }
        }
    }
    return 0;
}