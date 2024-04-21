#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Function to generate a random pivot and place it at the end
int randomPartition(int arr[], int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

// Function to implement Randomized Quick Sort
void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivotIndex - 1);
        randomizedQuickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Example array
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Regular Quick Sort
    int comparisonsRegular = 0;
    quickSort(arr, 0, n - 1, &comparisonsRegular);
    printf("Sorted array using Quick Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Number of comparisons: %d\n", comparisonsRegular);

    // Randomized Quick Sort
    int arrRandomized[] = {12, 11, 13, 5, 6, 7}; // Reset the array
    int comparisonsRandomized = 0;
    randomizedQuickSort(arrRandomized, 0, n - 1);
    printf("\nSorted array using Randomized Quick Sort: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arrRandomized[i]);
    printf("\n");
    printf("Number of comparisons: %d\n", comparisonsRandomized);

    return 0;
}
