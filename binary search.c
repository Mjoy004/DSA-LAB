#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search in the left half
        if (arr[mid] > target)
            right = mid - 1;
        else // If target is larger, search in the right half
            left = mid + 1;
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50}; // Must be sorted
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array.\n");

    return 0;
}
