#include <stdio.h>
#include <stdbool.h>

bool is_valid(int arr[], int n, int m, int mid) {
    int students = 1;
    int current_sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) return false;
        if (current_sum + arr[i] > mid) {
            students++;
            current_sum = arr[i];
            if (students > m) return false;
        } else {
            current_sum += arr[i];
        }
    }
    return true;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    int arr[n];
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > low) low = arr[i];
        high += arr[i];
    }

    if (m > n) {
        printf("-1\n");
        return 0;
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (is_valid(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);
    return 0;
}
