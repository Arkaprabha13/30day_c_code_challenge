#include <stdio.h>

// Function to compute X^n in O(n) time
long long powerLinear(long long x, long long n) {
    if (n == 0)
        return 1;
    return x * powerLinear(x, n - 1);
}

// Function to compute X^n in O(log n) time using recursion
long long powerLogarithmic(long long x, long long n) {
    if (n == 0)
        return 1;
    long long temp = powerLogarithmic(x, n / 2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main() {
    long long x = 2; // Base
    long long n = 10; // Exponent

    // Compute X^n using both methods
    long long resultLinear = powerLinear(x, n);
    long long resultLogarithmic = powerLogarithmic(x, n);

    // Print results
    printf("Linear Time: %lld\n", resultLinear);
    printf("Logarithmic Time: %lld\n", resultLogarithmic);

    return 0;
}
