#include <stdio.h>

// Recursive function to find max
int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max = findMax(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}

// Recursive function to find min
int findMin(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int min = findMin(arr, n - 1);
    return (arr[n - 1] < min) ? arr[n - 1] : min;
}

int main() {
    int arr[] = {5, 8, 1, 20, 45, 0, 13};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum: %d\n", findMax(arr, size));
    printf("Minimum: %d\n", findMin(arr, size));

    return 0;
}
