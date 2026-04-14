#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) { // Start from second element 
        key = arr[i]; // Store current element as key [cite: 154]
        j = i - 1; // Set index for comparison [cite: 156]

        // Shift elements of arr[0..i-1] that are greater than key [cite: 160, 162]
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // Place key at correct position [cite: 169]
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n); // [cite: 187]
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // [cite: 190]
    }
    
    insertionSort(arr, n); // [cite: 194]
    
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // [cite: 204]
    }
    printf("\n");
    return 0;
}