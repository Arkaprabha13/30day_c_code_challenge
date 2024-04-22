#include <stdio.h>
#include <limits.h>
void printParenthesis(int i, int j, int n, int bracket[][n]) {
    if (i == j) {
        // printf("%c", (char)(i + 'A' - 1));
        printf(" M%d",i);
        return;
    }

    printf("(");
    printParenthesis(i, bracket[i][j], n, bracket);
    printParenthesis(bracket[i][j] + 1, j, n, bracket);
    printf(")");
}


void matrixChainOrder(int p[], int n) {
    int m[n][n];
    int bracket[n][n];

    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i +L -1< n; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX / 2;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization is: ");
    printParenthesis(1, n - 1, n, bracket);
    printf("\nOptimal Cost is: %d\n", m[1][n - 1]);
}

int main() {
    int arr[] = { 40, 20, 30, 10, 30 };
    int n = sizeof(arr) / sizeof(arr[0]);
    matrixChainOrder(arr, n);
    return 0;
}
