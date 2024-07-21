#include <stdio.h>

// Function to perform Bubble Sort
void bubble_sort(int arr[], int n) {
    int i, j, temp;
    // Loop through the entire array
    for (i = 0; i < n - 1; i++) {
        // For each pass, compare adjacent elements and swap if needed
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Main function to test the bubble sort
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements in the array

    bubble_sort(arr, n); // Call bubble sort function

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

