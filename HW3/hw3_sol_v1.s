.section .text
.global matrix_chain_multiplication

# matrix_chain_multiplication:
# 這個函數執行矩陣鏈乘，返回計算結果的記憶體地址。
# 參數:
#   a0 = N (矩陣總數)
#   a1 = matrix_info (矩陣資訊地址)
#   a2 = buffer1 (暫存區1)
#   a3 = buffer2 (暫存區2)
# 返回:
#   a0 = 計算結果存放的記憶體地址

matrix_chain_multiplication:
    addi sp, sp, -40         # 分配 stack 空間 (-40 以對齊 -8)
    sd ra, 32(sp)            # 存回 ra (返回地址)
    sd a0, 24(sp)            # 存回 N (矩陣總數)
    sd a1, 16(sp)            # 存回 matrix_info 地址
    sd a2, 8(sp)             # 存回 buffer1
    sd a3, 0(sp)             # 存回 buffer2

    beqz a1, return_null     # 如果 matrix_info = NULL，則返回 NULL

    mv t1, a0                # t1 = N (矩陣數量)
    mv t0, a1                # t0 = matrix_info 地址
    mv s1, a2                # s1 = buffer1
    mv s2, a3                # s2 = buffer2

    # 讀取 matrix1 資訊
    ld s3, 0(t0)             # matrix1 的起始地址
    beqz s3, return_null     # 若地址為 NULL，則返回 NULL

    ld s4, 8(t0)             # matrix1 行數
    ld s5, 16(t0)            # matrix1 列數
    addi t0, t0, 24          # 移動到 matrix2 的資訊地址
    mv s6, s1                # 初始計算結果存入 buffer1

    jal ra, copy_matrix      # 複製 matrix1 到 buffer1

# 矩陣相乘主迴圈
matrix_multiply_loop:
    addi t1, t1, -1          # N = N - 1，檢查是否計算完所有矩陣
    beqz t1, finalize_result # 若矩陣數量為 0，則完成計算並返回

    # 讀取下一個矩陣的資訊
    ld s3, 0(t0)             # matrixX 的地址
    beqz s3, return_null     # 若地址為 NULL，則返回 NULL

    ld s4, 8(t0)             # matrixX 行數
    ld s5, 16(t0)            # matrixX 列數
    addi t0, t0, 24          # 移動到下一個矩陣資訊

    # 交替使用 buffer1 和 buffer2
    beq s6, s1, use_buffer2  # 如果 s6 是 buffer1，則切換到 buffer2
    mv s7, s1                # 暫存結果存入 buffer1
    mv s6, s2                # 下一輪暫存區為 buffer2
    jal ra, matrix_multiply  # 執行矩陣乘法
    j matrix_multiply_loop   # 繼續下一輪相乘

use_buffer2:
    mv s7, s2                # 暫存結果存入 buffer2
    mv s6, s1                # 下一輪暫存區為 buffer1
    jal ra, matrix_multiply  # 執行矩陣乘法
    j matrix_multiply_loop   # 繼續下一輪相乘

# 計算結束，返回結果地址
finalize_result:
    mv a0, s6                # 設定 a0 為最終結果存放的記憶體地址
    ld ra, 32(sp)            # 取回返回地址
    addi sp, sp, 40          # 釋放 stack 空間
    ret                      # 返回至 C++ 主程式

# 若 matrix_info 為 NULL，則返回 NULL
return_null:
    li a0, 0                 # 設定返回值為 NULL
    ld ra, 32(sp)            # 取回返回地址
    addi sp, sp, 40          # 釋放 stack 空間
    ret                      # 返回至 C++ 主程式

# 矩陣複製函數
# 複製 s3 指向的矩陣到 s6 指向的位置
# s3 = 原始矩陣地址
# s4 = 行數
# s5 = 列數
# s6 = 目標地址
copy_matrix:
    mv s8, s4                # 設定行數
copy_row:
    beqz s8, copy_done       # 若行數為 0，則結束複製
    mv s9, s5                # 設定列數
copy_column:
    beqz s9, copy_next_row   # 若列數為 0，則進入下一行
    ld s10, 0(s3)            # 載入數據
    sd s10, 0(s6)            # 存入目標地址
    addi s3, s3, 8           # 移動原始矩陣地址 (8-byte 因為 64-bit)
    addi s6, s6, 8           # 移動目標地址 (8-byte)
    addi s9, s9, -1          # 列數減 1
    j copy_column            # 繼續複製下一個元素
copy_next_row:
    addi s8, s8, -1          # 行數減 1
    j copy_row               # 繼續複製下一行
copy_done:
    ret                      # 返回

# 矩陣相乘函數
# s3 = 矩陣 A 的地址
# s4 = 矩陣 A 的行數
# s5 = 矩陣 A 的列數 / 矩陣 B 的行數
# s6 = 矩陣 B 的地址
# s7 = 暫存區地址 (存結果)
matrix_multiply:
    mv s8, s4                # 設定矩陣 A 的行數
multiply_row:
    beqz s8, multiply_done   # 若行數為 0，則結束計算
    mv s9, s5                # 設定矩陣 B 的列數
multiply_column:
    beqz s9, next_row        # 若列數為 0，則進入下一行
    mv s10, zero             # 初始化結果值
    mv s11, s5               # 設定矩陣 A 的列數 / 矩陣 B 的行數
multiply_element:
    beqz s11, next_column    # 若計算完該元素，則進入下一列
    ld t0, 0(s3)             # 讀取 A 的元素
    ld t1, 0(s6)             # 讀取 B 的元素
    mul t2, t0, t1           # 相乘
    add s10, s10, t2         # 加到結果
    addi s3, s3, 8           # 移動 A 的指標
    addi s6, s6, 8           # 移動 B 的指標
    addi s11, s11, -1        # 迴圈計數減 1
    j multiply_element       # 繼續計算下一個元素
next_column:
    sd s10, 0(s7)            # 存入結果
    addi s7, s7, 8           # 移動到下一列
    addi s9, s9, -1          # 列數減 1
    j multiply_column        # 繼續計算列
next_row:
    addi s8, s8, -1          # 行數減 1
    j multiply_row           # 繼續計算行
multiply_done:
    ret                      # 返回
