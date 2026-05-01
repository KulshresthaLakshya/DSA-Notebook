#include <stdio.h>

int find_lower_bound(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int answer = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int find_upper_bound(int arr[], int n, int x) {
    int low = 0;
    int high = n - 1;
    int answer = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}

int main() {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) break;
    }

    if (scanf("%d", &x) != 1) return 0;

    int lower_bound_index = find_lower_bound(arr, n, x);
    int upper_bound_index = find_upper_bound(arr, n, x);

    printf("%d %d\n", lower_bound_index, upper_bound_index);

    return 0;
}
