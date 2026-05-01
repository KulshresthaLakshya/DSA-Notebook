#include <stdio.h>

void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minimum_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minimum_index]) {
                minimum_index = j;
            }
        }
        int temp = arr[minimum_index];
        arr[minimum_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) break;
    }

    selection_sort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", arr[i], (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
