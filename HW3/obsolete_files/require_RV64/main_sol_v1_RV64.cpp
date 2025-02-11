#include <cstdint>
#include <sys/mman.h>  // For mmap
#include <unistd.h>    // For write(), close()
#include <cstring>     // For memcpy(), strlen()
#include <fcntl.h>     // For open() and O_* flags
#include <cstdio>      // For snprintf()
#include <cstdlib>     // For exit()

// The assembly routine (implemented elsewhere) remains unchanged.
extern "C" {
    uint64_t* matrix_chain_multiplication(int N, uintptr_t matrix_info_addr,
                                            uintptr_t buffer1_addr, uintptr_t buffer2_addr);
}

int main() {
    // Open the output file for writing.
    int out_fd = open("/workspace/hw3/output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0) {
        perror("open");
        return 1;
    }
    char buf[256];  // Buffer for formatted messages

    int N = 3;  // Total number of matrices

    // Set a base address within GEM5 allowed range.
    uintptr_t base_addr = 0x80000000;

    // Allocate memory for matrix_data.
    uint64_t* matrix_data = (uint64_t*) mmap((void*)(base_addr + 0x300000), 4096,
                                              PROT_READ | PROT_WRITE,
                                              MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                                              -1, 0);
    if (matrix_data == MAP_FAILED) {
        snprintf(buf, sizeof(buf), "Memory allocation for matrix_data failed!\n");
        write(out_fd, buf, strlen(buf));
        close(out_fd);
        return 1;
    }

    // Write the matrix data (three matrices) into matrix_data.
    uint64_t tmp_data[] = {
        // Matrix 1 (2x3)
        1, 2, 3,
        4, 5, 6,
        // Matrix 2 (3x4)
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        // Matrix 3 (4x2)
        1, 2,
        3, 4,
        5, 6,
        7, 8
    };
    memcpy(matrix_data, tmp_data, sizeof(tmp_data));

    // Allocate memory for matrix_info.
    uintptr_t* matrix_info = (uintptr_t*) mmap((void*)(base_addr + 0x200000), 4096,
                                                 PROT_READ | PROT_WRITE,
                                                 MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                                                 -1, 0);
    if (matrix_info == MAP_FAILED) {
        snprintf(buf, sizeof(buf), "Memory allocation for matrix_info failed!\n");
        write(out_fd, buf, strlen(buf));
        close(out_fd);
        return 1;
    }

    // Set up matrix_info (each matrix is described by its data address, row count, and column count)
    matrix_info[0] = (uintptr_t) &matrix_data[0];   matrix_info[1] = 2;  matrix_info[2] = 3;
    matrix_info[3] = (uintptr_t) &matrix_data[6];   matrix_info[4] = 3;  matrix_info[5] = 4;
    matrix_info[6] = (uintptr_t) &matrix_data[18];  matrix_info[7] = 4;  matrix_info[8] = 2;

    // Allocate two buffers (to be used alternately during multiplication)
    uint64_t* buffer1 = (uint64_t*) mmap((void*) base_addr, 65536,
                                          PROT_READ | PROT_WRITE,
                                          MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                                          -1, 0);
    uint64_t* buffer2 = (uint64_t*) mmap((void*)(base_addr + 0x100000), 65536,
                                          PROT_READ | PROT_WRITE,
                                          MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                                          -1, 0);
    if (buffer1 == MAP_FAILED || buffer2 == MAP_FAILED) {
        snprintf(buf, sizeof(buf), "Memory allocation failed in GEM5 valid range!\n");
        write(out_fd, buf, strlen(buf));
        close(out_fd);
        return 1;
    }

    // Write diagnostic information about the allocated memory.
    snprintf(buf, sizeof(buf), "Matrix Data Address: %lx\n", (uintptr_t)matrix_data);
    write(out_fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Matrix Info Address: %lx\n", (uintptr_t)matrix_info);
    write(out_fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Allocated Buffer1 at: %lx\n", (uintptr_t)buffer1);
    write(out_fd, buf, strlen(buf));
    snprintf(buf, sizeof(buf), "Allocated Buffer2 at: %lx\n", (uintptr_t)buffer2);
    write(out_fd, buf, strlen(buf));

    // Call the assembly routine to perform the matrix chain multiplication.
    uint64_t* result_matrix = matrix_chain_multiplication(N,
                                       (uintptr_t)matrix_info,
                                       (uintptr_t)buffer1,
                                       (uintptr_t)buffer2);

    // Check for errors from matrix_chain_multiplication.
    if (result_matrix == nullptr) {
        snprintf(buf, sizeof(buf), "Error: matrix_chain_multiplication returned NULL!\n");
        write(out_fd, buf, strlen(buf));
        close(out_fd);
        return 1;
    } else {
        snprintf(buf, sizeof(buf), "Final Matrix Address: %lx\n", (uintptr_t)result_matrix);
        write(out_fd, buf, strlen(buf));
    }

    // Determine the dimensions of the final result.
    int final_rows = matrix_info[1];  // The first matrix’s row count
    int final_cols = matrix_info[8];  // The last matrix’s column count

    // Write the header for the final matrix.
    snprintf(buf, sizeof(buf), "Final Matrix (%dx%d):\n", final_rows, final_cols);
    write(out_fd, buf, strlen(buf));

    // Output the final matrix elements.
    for (int i = 0; i < final_rows; i++) {
        char line[1024];
        int pos = 0;
        for (int j = 0; j < final_cols; j++) {
            pos += snprintf(line + pos, sizeof(line) - pos, "%llu ", 
                            (unsigned long long) result_matrix[i * final_cols + j]);
        }
        pos += snprintf(line + pos, sizeof(line) - pos, "\n");
        write(out_fd, line, strlen(line));
    }

    close(out_fd);
    return 0;
}
