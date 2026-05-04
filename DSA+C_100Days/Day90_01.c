#include <stdio.h>
#include <stdbool.h>

bool can_paint(int arr[], int n, int k, int limit) {
    int painters = 1;
    int current_work = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > limit) return false;
        if (current_work + arr[i] > limit) {
            painters++;
            current_work = arr[i];
            if (painters > k) return false;
        } else {
            current_work += arr[i];
        }
    }
    return true;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int arr[n];
    long long low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_paint(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%lld\n", result);
    return 0;
}
