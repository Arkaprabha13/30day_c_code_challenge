#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to solve the Fractional Knapsack problem and print the selected items
double fractionalKnapsack(int W, int values[], int weights[], int n) {
    // Calculate value per unit weight for each item and store it in a separate array
    double valuePerWeight[n];
    for (int i = 0; i < n; i++) {
        valuePerWeight[i] = (double)values[i] / weights[i];
    }

    // Create an array to store the indices of items
    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    // Sort the indices array based on the value per unit weight (descending order)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (valuePerWeight[indices[j]] < valuePerWeight[indices[j + 1]]) {
                swap(&indices[j], &indices[j + 1]);
            }
        }
    }

    double totalValue = 0.0; // Total value of the knapsack
    int currentWeight = 0;   // Current weight in the knapsack

    printf("Knapsack Table:\n");
    printf("Item | Weight | Value | Value/Weight | Taken\n");
    printf("--------------------------------------------\n");

    // Loop through all items
    for (int i = 0; i < n; i++) {
        int index = indices[i]; // Get the index of the current item
        // If adding the whole item exceeds the knapsack capacity
        if (currentWeight + weights[index] <= W) {
            // Add the whole item
            currentWeight += weights[index];
            totalValue += values[index];
            printf("%4d | %6d | %5d | %13.2f |   Yes\n", index + 1, weights[index], values[index], valuePerWeight[index]);
        } else {
            // Add a fraction of the item
            int remainingWeight = W - currentWeight;
            double fraction = (double)remainingWeight / weights[index];
            totalValue += fraction * values[index];
            currentWeight += remainingWeight;
            printf("%4d | %6d | %5d | %13.2f |   Yes (Fraction %.2f)\n", index + 1, remainingWeight, (int)(fraction * values[index]), valuePerWeight[index], fraction);
            break; // Knapsack is full
        }
    }

    printf("--------------------------------------------\n");
    printf("Total value of the knapsack: %.2f\n", totalValue);

    return totalValue;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int W = 50; // Knapsack capacity

    double maxValue = fractionalKnapsack(W, values, weights, n);

    return 0;
}
