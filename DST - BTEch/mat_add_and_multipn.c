#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("\nMatrix:\n");
    for (int i = 0;i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int rows, int cols) {
    for (int i = 0;i < rows; i++) {
        for (int j = 0; j < cols;j++) {
            C[i][j] = A[i][j] + B[i][j] ;
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int Arows, int Acols, int Bcols) {
    for (int i = 0; i < Arows; i++) {
        for (int j = 0; j < Bcols; j++) {
            C[i][j] = 0;
            for (int k = 0; k < Acols; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int Arows, Acols, Brows, Bcols;

    printf("Enter number of rows and columns for Matrix A: ");
    scanf("%d %d", &Arows, &Acols);
    inputMatrix(A, Arows, Acols);
    printMatrix(A, Arows, Acols);

    printf("Enter number of rows and columns for Matrix B: ");
    scanf("%d %d", &Brows, &Bcols);
    if (Arows != Brows || Acols != Bcols) {
        printf("Matrices must be of the same size for addition.\n");
        return 0;
    }
    inputMatrix(B, Brows, Bcols);
    printMatrix(B, Brows, Bcols);

    addMatrices(A, B, C, Arows, Acols);
    printf("\nMatrix A + B:\n");
    printMatrix(C, Arows, Acols);

    if (Acols != Brows) {
        printf("Matrix multiplication is not possible. Columns of A must equal rows of B.\n");
        return 0;
    }
    multiplyMatrices(A, B, C, Arows, Acols, Bcols);
    printf("\nMatrix A * B:\n");
    printMatrix(C, Arows, Bcols);

    return 0;
}
