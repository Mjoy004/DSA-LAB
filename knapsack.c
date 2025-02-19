#include <stdio.h>

// Function to get the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: No items or zero capacity
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];  // Maximum value that can be obtained
}

int main() {
    int values[] = {60, 100, 120}; 
    int weights[] = {10, 20, 30}; 
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    printf("Maximum value in knapsack = %d\n", knapsack(capacity, weights, values, n));

    return 0;
}
