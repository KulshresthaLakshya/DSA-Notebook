#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) { // Outer loop to move boundary [cite: 242]
        minIndex = i; 
        for (j = i + 1; j < n; j++) { // Inner loop to find minimum [cite: 243]
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // FIXED: Updated to j, not '3' 
            }
        }
        // Swap the found minimum element with the first element [cite: 253]
        if (minIndex != i) {
            temp = arr[i]; // FIXED: Added '=' [cite: 255]
            arr[i] = arr[minIndex]; // FIXED: Added '=' [cite: 257]
            arr[minIndex] = temp; // [cite: 259]
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n); // [cite: 279]
    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // [cite: 285]
    }

    selectionSort(arr, n); // [cite: 290]

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // FIXED: Standardized output loop [cite: 301]
    }
    printf("\n");
    return 0;
}