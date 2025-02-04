#include <stdio.h>
#include <stdlib.h>

// 函數用於分配矩陣的記憶體
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// 釋放矩陣記憶體
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// 讀取 data.txt
int*** readData(const char* filename, int* matrixCount, int dimensions[][2]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d", matrixCount); // 讀取矩陣個數
    int*** matrices = (int***)malloc((*matrixCount) * sizeof(int**));

    for (int i = 0; i < *matrixCount; i++) {
        int rows, cols;
        fscanf(file, "%d %d", &rows, &cols);
        dimensions[i][0] = rows;
        dimensions[i][1] = cols;

        matrices[i] = allocateMatrix(rows, cols);

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                fscanf(file, "%d", &matrices[i][r][c]);
            }
        }
    }

    fclose(file);
    return matrices;
}

// 矩陣相乘
int** multiply(int** A, int** B, int rowsA, int colsA, int colsB) {
    int** result = allocateMatrix(rowsA, colsB);

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// 矩陣鏈相乘
int** matrixChainMultiplication(int*** matrices, int matrixCount, int dimensions[][2]) {
    int** result = matrices[0];
    int rows = dimensions[0][0];
    int cols = dimensions[0][1];

    for (int i = 1; i < matrixCount; i++) {
        int** nextResult = multiply(result, matrices[i], rows, cols, dimensions[i][1]);
        if (i > 1) {
            freeMatrix(result, rows);
        }
        cols = dimensions[i][1];
        result = nextResult;
    }

    return result;
}

// 將結果寫入 answer.txt
void writeResult(const char* filename, int** matrix, int rows, int cols) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

// 主程式
int main() {
    const char* dataFile = "data.txt";
    const char* answerFile = "answer.txt";

    int matrixCount;
    int dimensions[100][2]; // 假設最多 100 個矩陣

    // 讀取 data.txt
    int*** matrices = readData(dataFile, &matrixCount, dimensions);

    // 矩陣鏈相乘
    int** result = matrixChainMultiplication(matrices, matrixCount, dimensions);

    // 寫入 answer.txt
    writeResult(answerFile, result, dimensions[0][0], dimensions[matrixCount - 1][1]);

    // 釋放記憶體
    for (int i = 0; i < matrixCount; i++) {
        freeMatrix(matrices[i], dimensions[i][0]);
    }
    free(matrices);
    freeMatrix(result, dimensions[0][0]);

    printf("Result written to %s\n", answerFile);
    return 0;
}
