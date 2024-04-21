#include <stdio.h>
#include <limits.h>

// Function to find optimal matrix chain multiplication
void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int i, j, k, L, q;

    // Initialize the cost matrix
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // Fill in the cost matrix
    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
}

int main() {
    int arr[] = {13, 5, 89, 3, 34}; // Sequence of matrix dimensions
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
