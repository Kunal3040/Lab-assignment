#include <stdio.h>

// Function to perform Selection Sort
void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Main function to test the selection sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array

    selection_sort(arr, n); // Call selection sort function

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

