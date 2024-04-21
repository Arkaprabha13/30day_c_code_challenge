#include <stdio.h>
#include <string.h>

// Function to find the length of the longest common subsequence
int lcsLength(char X[], char Y[], int m, int n) {
    int L[m + 1][n + 1];

    // Build L[m+1][n+1] in bottom-up fashion
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    return L[m][n];
}

// Function to print all possible LCS
void printAllLCS(char X[], char Y[], int m, int n, char lcs[], int index, int length) {
    if (m == 0 || n == 0) {
        if (length == 0) {
            printf("%s\n", lcs);
        }
        return;
    }

    if (X[m - 1] == Y[n - 1])
    {
        lcs[index - 1] = X[m - 1];
        printAllLCS(X, Y, m - 1, n - 1, lcs, index - 1, length - 1);
    }
    else if (lcsLength(X, Y, m - 1, n) >= length && lcsLength(X, Y, m, n - 1) >= length
    {
        printAllLCS(X, Y, m - 1, n, lcs, index, length);
        printAllLCS(X, Y, m, n - 1, lcs, index, length);
    } 
    else if (lcsLength(X, Y, m - 1, n) >= lcsLength(X, Y, m, n - 1))
        printAllLCS(X, Y, m - 1, n, lcs, index, length);
    else if (lcsLength(X, Y, m, n - 1) >= lcsLength(X, Y, m - 1, n))
        printAllLCS(X, Y, m, n - 1, lcs, index, length);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCAB";
    int m = strlen(X);
    int n = strlen(Y);

    int length = lcsLength(X, Y, m, n);
    char lcs[length + 1];
    lcs[length] = '\0'; // Null terminator

    printf("All possible Longest Common Subsequences:\n");
    printAllLCS(X, Y, m, n, lcs, length, length);

    return 0;
}
