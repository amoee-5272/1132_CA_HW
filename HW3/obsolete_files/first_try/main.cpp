#include <iostream>
#include <cstdint>
#include <sys/mman.h>  // mmap 用來分配記憶體
#include <unistd.h>
#include <cstring>  // 🔹 確保 memcpy() 被正確識別

extern "C" {
    uint64_t* matrix_chain_multiplication(int N, uintptr_t matrix_info_addr, uintptr_t buffer1_addr, uintptr_t buffer2_addr);
}

// extern "C" {
//     uint64_t* matrix_chain_multiplication(int N, uintptr_t matrix_info_addr, uintptr_t buffer1_addr, uintptr_t buffer2_addr) {
//         uintptr_t* matrix_info = reinterpret_cast<uintptr_t*>(matrix_info_addr);
//         uint64_t* buffer1 = reinterpret_cast<uint64_t*>(buffer1_addr);
//         uint64_t* buffer2 = reinterpret_cast<uint64_t*>(buffer2_addr);

//         // **初始狀態: 第一個矩陣**
//         uint64_t* current_matrix = reinterpret_cast<uint64_t*>(matrix_info[0]);
//         int current_rows = matrix_info[1];
//         int current_cols = matrix_info[2];

//         // **進行矩陣連乘**
//         for (int step = 1; step < N; step++) {
//             uint64_t* next_matrix = reinterpret_cast<uint64_t*>(matrix_info[step * 3]);
//             int next_rows = matrix_info[step * 3 + 1];
//             int next_cols = matrix_info[step * 3 + 2];

//             if (current_cols != next_rows) {
//                 std::cerr << "Error: Matrix dimensions mismatch!" << std::endl;
//                 return nullptr;
//             }

//             // **選擇緩衝區 (交替使用 buffer1 和 buffer2)**
//             uint64_t* output_buffer = (step % 2 == 1) ? buffer1 : buffer2;

//             // **執行矩陣相乘**
//             for (int i = 0; i < current_rows; i++) {
//                 for (int j = 0; j < next_cols; j++) {
//                     uint64_t sum = 0;
//                     for (int k = 0; k < current_cols; k++) {
//                         sum += current_matrix[i * current_cols + k] * next_matrix[k * next_cols + j];
//                     }
//                     output_buffer[i * next_cols + j] = sum;
//                 }
//             }

//             // **更新狀態: 目前矩陣資訊**
//             current_matrix = output_buffer;
//             current_cols = next_cols;
//         }

//         return current_matrix;
//     }
// }



int main() {
    int N = 3;  // 矩陣總數

    // **確保 GEM5 允許的記憶體範圍**
    uintptr_t base_addr = 0x80000000;

    // **使用 mmap 分配 memory-safe `matrix_data`**
    uint64_t* matrix_data = (uint64_t*) mmap((void*)(base_addr + 0x300000), 4096,
                                             PROT_READ | PROT_WRITE,
                                             MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (matrix_data == MAP_FAILED) {
        std::cerr << "Memory allocation for matrix_data failed!" << std::endl;
        return 1;
    }

    // **寫入 matrix_data**
    uint64_t tmp_data[] = {
        // matrix1 (2x3)
        1, 2, 3,
        4, 5, 6,
        // matrix2 (3x4)
        1, 2, 3, 4,
        5, 6, 7, 8,
        9, 10, 11, 12,
        // matrix3 (4x2)
        1, 2,
        3, 4,
        5, 6,
        7, 8
    };
    memcpy(matrix_data, tmp_data, sizeof(tmp_data));

    // **使用 mmap 分配 memory-safe `matrix_info`**
    uintptr_t* matrix_info = (uintptr_t*) mmap((void*)(base_addr + 0x200000), 4096,
                                               PROT_READ | PROT_WRITE,
                                               MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (matrix_info == MAP_FAILED) {
        std::cerr << "Memory allocation for matrix_info failed!" << std::endl;
        return 1;
    }

    // **設定 matrix_info**
    matrix_info[0] = (uintptr_t) &matrix_data[0];  matrix_info[1] = 2;  matrix_info[2] = 3;
    matrix_info[3] = (uintptr_t) &matrix_data[6];  matrix_info[4] = 3;  matrix_info[5] = 4;
    matrix_info[6] = (uintptr_t) &matrix_data[18]; matrix_info[7] = 4;  matrix_info[8] = 2;

    // **使用 mmap 分配可用的緩衝區**
    uint64_t* buffer1 = (uint64_t*) mmap((void*) base_addr, 65536,
                                         PROT_READ | PROT_WRITE,
                                         MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);

    uint64_t* buffer2 = (uint64_t*) mmap((void*)(base_addr + 0x100000), 65536,
                                         PROT_READ | PROT_WRITE,
                                         MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);

    // **檢查分配是否成功**
    if (buffer1 == MAP_FAILED || buffer2 == MAP_FAILED) {
        std::cerr << "Memory allocation failed in GEM5 valid range!" << std::endl;
        return 1;
    }

    std::cout << "Matrix Data Address: " << std::hex << (uintptr_t)matrix_data << std::endl;
    std::cout << "Matrix Info Address: " << std::hex << (uintptr_t)matrix_info << std::endl;
    std::cout << "Allocated Buffer1 at: " << std::hex << (uintptr_t)buffer1 << std::endl;
    std::cout << "Allocated Buffer2 at: " << std::hex << (uintptr_t)buffer2 << std::endl;

    // **呼叫 `assembly` 函數**
    uint64_t* result_matrix = matrix_chain_multiplication(N, (uintptr_t)matrix_info, (uintptr_t)buffer1, (uintptr_t)buffer2);

    // **檢查返回值是否為 NULL**
    if (result_matrix == nullptr) {
        std::cerr << "Error: matrix_chain_multiplication returned NULL!" << std::endl;
        return 1;
    } else {
        std::cout << "Final Matrix Address: " << std::hex << (uintptr_t)result_matrix << std::endl;
    }

    // **計算最終矩陣大小**
    int final_rows = matrix_info[1];   // 第一個矩陣的行數
    int final_cols = matrix_info[8];   // 最後一個矩陣的列數

    // **輸出最終矩陣**
    std::cout << "Final Matrix (" << final_rows << "x" << final_cols << "):" << std::endl;
    for (int i = 0; i < final_rows; i++) {
        for (int j = 0; j < final_cols; j++) {
            std::cout << std::dec << result_matrix[i * final_cols + j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
