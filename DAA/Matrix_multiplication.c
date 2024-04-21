#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate memory for a matrix of size rows x cols
int **allocateMatrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free memory allocated for a matrix
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to read a matrix from a file
int **readMatrixFromFile(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    fscanf(file, "%d %d", rows, cols);
    int **matrix = allocateMatrix(*rows, *cols);
    for (int i = 0; i < *rows; ++i) {
        for (int j = 0; j < *cols; ++j) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);
    return matrix;
}

// Function to write a matrix to a file
void writeMatrixToFile(const char *filename, int **matrix, int rows, int cols) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

// Function to perform matrix multiplication
int **matrixMultiply(int **matrix1, int **matrix2, int rows1, int cols1, int cols2) {
    int **result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Read matrices from file
    int **matrix1 = readMatrixFromFile("matrix1.txt", &rows1, &cols1);
    int **matrix2 = readMatrixFromFile("matrix2.txt", &rows2, &cols2);

    // Check if multiplication is possible
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible.\n");
        return 1;
    }

    // Perform multiplication
    int **result = matrixMultiply(matrix1, matrix2, rows1, cols1, cols2);

    // Print result matrix
    printf("Result Matrix:\n");
    printMatrix(result, rows1, cols2);

    // Write result matrix to file
    writeMatrixToFile("result.txt", result, rows1, cols2);

    // Free memory
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, rows1);

    return 0;
}
