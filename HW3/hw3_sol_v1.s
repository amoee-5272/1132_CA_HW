    .section .data
N:      .word 3                 # 矩陣總數 N
matrix_info: 
    .word 0x0000, 2, 3          # matrix1: 地址=0000, 大小=2x3
    .word 0x0018, 3, 4          # matrix2: 地址=0018, 大小=3x4
    .word 0x0050, 4, 2          # matrix3: 地址=0050, 大小=4x2

result_address: 
    .word 0xf000                # 最終結果存放地址

buffer1: 
    .space 65536                # 緩衝區1 (128x128)

buffer2: 
    .space 65536                # 緩衝區2 (128x128)

    .section .text
    .globl _start

_start:
    # 初始化
    la t0, matrix_info          # 獲取矩陣資訊地址
    lw t1, N                    # 加載矩陣總數
    la t3, buffer1              # 暫存區1的地址
    la t4, buffer2              # 暫存區2的地址
    lw t5, result_address       # 最終結果地址

    # 初始矩陣載入到 buffer1
    lw t6, 0(t0)                # matrix1 地址
    lw t7, 4(t0)                # matrix1 行數
    lw t8, 8(t0)                # matrix1 列數
    addi t0, t0, 12             # 更新到 matrix2
    jal ra, copy_matrix         # 複製 matrix1 到 buffer1

    # 矩陣連乘
    mv t9, t3                   # 暫存區 (計算結果的讀寫切換)
matrix_multiply_loop:
    addi t1, t1, -1             # 矩陣數量減1
    beqz t1, finalize_result    # 如果矩陣數量為0，跳到結果處理

    # 加載下一矩陣
    lw t6, 0(t0)                # matrixX 地址
    lw t7, 4(t0)                # matrixX 行數
    lw t8, 8(t0)                # matrixX 列數
    addi t0, t0, 12             # 更新到下一個矩陣

    # 切換緩衝區 (交替使用)
    beq t9, t3, use_buffer2
    mv t10, t3                  # 暫存結果存到 buffer1
    mv t9, t4                   # 下一輪暫存地址切換到 buffer2
    jal ra, matrix_multiply     # 矩陣相乘
    j matrix_multiply_loop

use_buffer2:
    mv t10, t4                  # 暫存結果存到 buffer2
    mv t9, t3                   # 下一輪暫存地址切換到 buffer1
    jal ra, matrix_multiply     # 矩陣相乘
    j matrix_multiply_loop

finalize_result:
    # 將最終結果從暫存區複製到 result_address
    mv t6, t9                   # 暫存區地址
    lw t7, 4(t0)                # 最終行數
    lw t8, 8(t0)                # 最終列數
    jal ra, copy_matrix_to_result

    # 結束
    li a7, 10                   # Exit syscall
    ecall

# 矩陣複製程式
copy_matrix:
    # t6: 原始矩陣地址
    # t7: 行數
    # t8: 列數
    # t9: 目標地址
    mv t11, t7                  # 複製的行數
copy_row:
    beqz t11, copy_done          # 如果行數為0，結束
    mv t12, t8                  # 複製的列數
    copy_column:
        beqz t12, next_row       # 如果列數為0，進入下一行
        lw t13, 0(t6)           # 載入數據
        sw t13, 0(t9)           # 存入目標地址
        addi t6, t6, 4          # 移動原始地址
        addi t9, t9, 4          # 移動目標地址
        addi t12, t12, -1       # 列數減1
        j copy_column           # 繼續複製列
    next_row:
        addi t11, t11, -1       # 行數減1
        j copy_row              # 繼續複製行
copy_done:
    ret

# 矩陣相乘程式
matrix_multiply:
    # t6: 矩陣A地址
    # t7: 矩陣A行數
    # t8: 矩陣A列數 / 矩陣B行數
    # t9: 矩陣B地址
    # t10: 暫存區地址
    mv t11, t7                  # 矩陣A的行數
multiply_row:
    beqz t11, multiply_done     # 如果行數為0，結束
    mv t12, t8                  # 矩陣B的列數
    multiply_column:
        beqz t12, next_row      # 如果列數為0，進入下一行
        mv t13, zero            # 初始化結果值
        mv t14, t8              # 矩陣A的列數 / 矩陣B的行數
        multiply_element:
            beqz t14, next_column # 如果結束，進入下一列
            lw t15, 0(t6)       # 載入A的值
            lw t16, 0(t9)       # 載入B的值
            mul t17, t15, t16   # 相乘
            add t13, t13, t17   # 加到結果
            addi t6, t6, 4      # 移動到A的下一個元素
            addi t9, t9, 4      # 移動到B的下一個元素
            addi t14, t14, -1   # 減少計數器
            j multiply_element  # 繼續運算
        next_column:
            sw t13, 0(t10)      # 存入結果
            addi t10, t10, 4    # 移動到下一列
            addi t12, t12, -1   # 列數減1
            j multiply_column   # 繼續計算列
    next_row:
        addi t11, t11, -1       # 行數減1
        j multiply_row          # 繼續計算行
multiply_done:
    ret
