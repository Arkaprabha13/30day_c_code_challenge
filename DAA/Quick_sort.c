#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high, comparisons);
        quickSort(arr, low, pivotIndex - 1, comparisons);
        quickSort(arr, pivotIndex + 1, high, comparisons);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0;

    quickSort(arr, 0, n - 1, &comparisons);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
