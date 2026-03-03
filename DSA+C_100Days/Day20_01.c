#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long arg1 = *(const long long *)a;
    long long arg2 = *(const long long *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long arr[n];
    long long prefix_sums[n];
    long long current_sum = 0;
    int zero_sum_count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        current_sum += arr[i];
        prefix_sums[i] = current_sum;

        if (current_sum == 0) {
            zero_sum_count++;
        }
    }

    qsort(prefix_sums, n, sizeof(long long), compare);

    long long counter = 1;
    for (int i = 1; i < n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            counter++;
        } else {
            zero_sum_count += (counter * (counter - 1)) / 2;
            counter = 1;
        }
    }

    zero_sum_count += (counter * (counter - 1)) / 2;

    printf("%d\n", zero_sum_count);

    return 0;
}
