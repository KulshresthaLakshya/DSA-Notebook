#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n < 2) return 1;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int min_l = left, min_r = right;
    int min_sum = INT_MAX;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            min_l = left;
            min_r = right;
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            break;
        }
    }


    printf("%d %d\n", arr[min_l], arr[min_r]);

    return 0;
}
