#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest

        // Find the minimum element in the remaining array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
