#include <fcntl.h>    // open
#include <unistd.h>   // read, write, close, ftruncate
#include <stdlib.h>   // malloc, free, strtol, exit
#include <stdio.h>    // snprintf
#include <string.h>   // memcpy

// The chain_matrix_multiplication function multiplies matrices in order.
// The parameters are:
//   - matrices: an array of pointers; each pointer is a matrix stored as a flat int array
//   - rows: an array of ints giving the number of rows for each matrix
//   - cols: an array of ints giving the number of columns for each matrix
//   - count: number of matrices (at least 1)
// It returns a pointer to a newly allocated matrix which is the result of
// multiplying matrices[0] x matrices[1] x ... x matrices[count-1].

extern "C" {
int* chain_matrix_multiplication(int** matrices, int* rows, int* cols, int count);
}

/*
extern "C" {
int* chain_matrix_multiplication(int** matrices, int* rows, int* cols, int count) {
    // The result begins as a copy of the first matrix.
    int r = rows[0];
    int c = cols[0];
    int* result = (int*) malloc(r * c * sizeof(int));
    if (!result) return NULL;
    memcpy(result, matrices[0], r * c * sizeof(int));

    // Multiply (result) by each subsequent matrix.
    for (int i = 1; i < count; i++) {
        int r2 = rows[i];   // rows of the new (right-hand) matrix
        int c2 = cols[i];   // columns of the new matrix

        // Check that the dimensions are valid: result's columns must equal new matrix’s rows.
        if (c != r2) {
            free(result);
            return NULL;  // Dimension mismatch
        }

        // Allocate memory for the product matrix (dimensions: r x c2).
        int* product = (int*) malloc(r * c2 * sizeof(int));
        if (!product) {
            free(result);
            return NULL;
        }

        // Standard triple-loop matrix multiplication.
        for (int a = 0; a < r; a++) {
            for (int b = 0; b < c2; b++) {
                int sum = 0;
                for (int k = 0; k < c; k++) {
                    // result is stored as row-major (a * c + k)
                    // matrices[i] is stored as row-major (k * c2 + b)
                    sum += result[a * c + k] * matrices[i][k * c2 + b];
                }
                product[a * c2 + b] = sum;
            }
        }
        free(result);   // free the old result
        result = product;
        c = c2;         // update current column count for next multiplication
    }
    return result;
}
} // end extern "C"
*/

// Main function: read input, call chain_matrix_multiplication, and write output.
int main() {
    // Open the input file for reading.
    int fd = open("/workspace/input.txt", O_RDONLY);
    if (fd < 0)
        return 1;

    // Read the entire input file into a buffer.
    // (Assume the file is not larger than 8192 bytes.)
    size_t buffer_size = 8192;
    char* input_buffer = (char*) malloc(buffer_size + 1);
    if (!input_buffer) {
        close(fd);
        return 1;
    }
    ssize_t bytes_read = read(fd, input_buffer, buffer_size);
    if (bytes_read < 0) {
        free(input_buffer);
        close(fd);
        return 1;
    }
    input_buffer[bytes_read] = '\0';
    close(fd);

    // Parse the input.
    // The first integer is the number of matrices.
    char* p = input_buffer;
    char* endptr;
    int count = (int) strtol(p, &endptr, 10);
    p = endptr;

    // Allocate arrays for the rows, columns, and the matrix pointers.
    int* rows_arr = (int*) malloc(count * sizeof(int));
    int* cols_arr = (int*) malloc(count * sizeof(int));
    int** matrices = (int**) malloc(count * sizeof(int*));
    if (!rows_arr || !cols_arr || !matrices) {
        free(input_buffer);
        if (rows_arr) free(rows_arr);
        if (cols_arr) free(cols_arr);
        if (matrices) free(matrices);
        return 1;
    }

    // For each matrix, first read its dimensions then its content.
    for (int i = 0; i < count; i++) {
        // Skip any whitespace.
        while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t')
            p++;
        int r = (int) strtol(p, &endptr, 10);
        p = endptr;
        while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t')
            p++;
        int c = (int) strtol(p, &endptr, 10);
        p = endptr;
        rows_arr[i] = r;
        cols_arr[i] = c;

        // Allocate memory for this matrix (stored in row-major order).
        int* mat = (int*) malloc(r * c * sizeof(int));
        if (!mat) {
            // Free any previously allocated matrices.
            for (int j = 0; j < i; j++) {
                free(matrices[j]);
            }
            free(matrices);
            free(rows_arr);
            free(cols_arr);
            free(input_buffer);
            return 1;
        }

        // Read r*c integers.
        for (int j = 0; j < r * c; j++) {
            while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t')
                p++;
            mat[j] = (int) strtol(p, &endptr, 10);
            p = endptr;
        }
        matrices[i] = mat;
    }
    free(input_buffer); // no longer needed

    // Perform the chain multiplication.
    int* result = chain_matrix_multiplication(matrices, rows_arr, cols_arr, count);
    if (!result) {
        // Free the allocated matrices and arrays.
        for (int i = 0; i < count; i++)
            free(matrices[i]);
        free(matrices);
        free(rows_arr);
        free(cols_arr);
        return 1;
    }
    // The dimensions of the final result are:
    //   rows = rows_arr[0]  and  cols = cols_arr[count-1]
    int final_rows = rows_arr[0];
    int final_cols = cols_arr[count - 1];

    // Open the output file for writing.
    int out_fd = open("/workspace/output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0) {
        free(result);
        for (int i = 0; i < count; i++)
            free(matrices[i]);
        free(matrices);
        free(rows_arr);
        free(cols_arr);
        return 1;
    }

    // Additionally, explicitly truncate the file to zero length.
    if (ftruncate(out_fd, 0) < 0) {
        close(out_fd);
        free(result);
        for (int i = 0; i < count; i++)
            free(matrices[i]);
        free(matrices);
        free(rows_arr);
        free(cols_arr);
        return 1;
    }

    // Write the final matrix to the output file.
    // Each row is formatted using snprintf and written with write.
    char out_line[256];
    for (int i = 0; i < final_rows; i++) {
        int pos = 0;
        for (int j = 0; j < final_cols; j++) {
            int n = snprintf(out_line + pos, sizeof(out_line) - pos, "%d", result[i * final_cols + j]);
            pos += n;
            if (j < final_cols - 1) {
                if (pos < (int) sizeof(out_line) - 1) {
                    out_line[pos] = ' ';
                    pos++;
                    out_line[pos] = '\0';
                }
            }
        }
        if (pos < (int) sizeof(out_line) - 1) {
            out_line[pos] = '\n';
            pos++;
            out_line[pos] = '\0';
        }
        write(out_fd, out_line, pos);
    }
    close(out_fd);

    // Free all allocated memory.
    free(result);
    for (int i = 0; i < count; i++) {
        free(matrices[i]);
    }
    free(matrices);
    free(rows_arr);
    free(cols_arr);

    return 0;
}
