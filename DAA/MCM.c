#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to print the optimal parenthesization of the matrix chain
void printOptimalParenthesization(int s[][100], int i, int j) {
    if (i == j)
        printf("A%d", i);
    else {
        printf("(");
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        printf(")");
    }
}

int mChain(int p[], int n) {
    int s[n][n]; // To store the split position

    int dp[n][n];
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;

    for (int gap = 2; gap < n; gap++) {
        for (int i = 0; i + gap < n; i++) {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++) {
                int q = dp[i][k] + dp[k][j] + p[i] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                    s[i][j] = k; // Store the split position
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", dp[0][n - 1]);

    // Print the optimal parenthesization
    printOptimalParenthesization(s, 0, n - 1);

    return dp[0][n - 1];
}

int main() {
    int arr[] = {10, 30, 5, 60}; // Sequence of matrix dimensions
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum number of multiplications: %d\n", mChain(arr, n));

    return 0;
}
