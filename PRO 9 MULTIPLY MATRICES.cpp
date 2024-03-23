#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

// Function to multiply two matrices
void multiplyMatrices(int mat1[][N], int mat2[][N], int res[][N], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res[i][j] = 0;
            for (int k = 0; k < size; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[N][N], mat2[N][N], res[N][N];
    int size;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &size);

    // Generating random matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat1[i][j] = rand() % 10;
            mat2[i][j] = rand() % 10;
        }
    }

    start = clock();
    multiplyMatrices(mat1, mat2, res, size);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to multiply matrices: %f seconds\n", cpu_time_used);

    return 0;
}
