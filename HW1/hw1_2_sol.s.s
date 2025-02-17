.data
nums:   .word 4, 5, 1, 8, 3, 6, 9 ,2    # input sequence
n:      .word 8                        # sequence length
dp:     .word 0, 0, 0, 0, 0, 0, 0, 0, 0   # dp array


.text
.globl main

# This is 1132 CA Homework 1 Problem 2
# Implement Longest Increasing Subsequence Algorithm
# Input: 
#       sequence length (n) store in a0
#       address of sequence store in a1
#       address of dp array with length n store in a2 (we can decide to use or not)        
# Output: Length of Longest Increasing Subsequenc in a0(x10)

# DO NOT MODIFY "main" FUNCTION !!!

main:

    lw a0, n          # a0 = n
    la a1, nums       # a1 = &nums[0]
    la a2, dp         # a2 = &dp[0] 
      
    jal LIS         # Jump to LIS algorithm
    
    # Exit program
    # System id for exit is 10 in Ripes, 93 in GEM5 
    li a7, 10
    ecall

LIS:
    mv t5, a2         # t5 = &dp[0]
    mv t4, a1         # t4 = &nums[0]
    li t3, 0          # i = 0
    li t2, 1          # constant 1 (to initialize)
    
init_dp:
    # initialize dp[i] = 1
    slli a3, t3, 2    # offset = i * 4
    add a3, t5, a3    # dp[i] address
    sw t2, 0(a3)      # update dp[i]
    addi t3, t3, 1   # i++
    bne t3, a0, init_dp  # if (i!=n) continue initialize

    # start LIS calculation 
    li t3, 0          # i = 0

outer_loop:
    beq t3, a0, find_max_dp # if i == n, go to find_max_dp
    li t6, 0          # j = 0

inner_loop:
    beq t6, t3, next_i  # if j == i, increment i

    # read nums[i] to a2 
    slli a3, t3,2     # offset = i * 4
    add a3, t4, a3    # nums[i] address
    lw a2, 0(a3)      # a2 = nums[i]

    # read nums[j] to a4
    slli a5, t6, 2    # offset = j * 4
    add a5, t4, a5    # nums[j] address
    lw a4, 0(a5)      # a4 = nums[j]

    # check nums[i] > nums[j]
    ble a2, a4, skip_dp_update # if nums[i] <= nums[j], skip

    # read dp[j] to a6
    slli a5, t6, 2    # offset = j * 4
    add a5, t5, a5    # dp[j] address
    lw a6, 0(a5)      # a6 = dp[j]

    # calculate dp[i] = max(dp[i], dp[j] + 1)
    addi a6, a6, 1    # a6 = dp[j] + 1
    slli a3, t3,2     # offset = i * 4
    add a3, t5, a3    # dp[i] address
    lw a7, 0(a3)      # a7 = dp[i]
    blt a7, a6, update_dp # if dp[i] < dp[j] + 1, update dp[i]

skip_dp_update:
    addi t6, t6, 1    # j++  
    j inner_loop      

update_dp:
    sw a6, 0(a3)      # update dp[i]
    j skip_dp_update  

next_i:
    addi t3, t3, 1    # i++  
    j outer_loop      

find_max_dp:
    li t3, 0          # i = 0
    mv t6, a0         # t6 = n
    lw a0, 0(t5)      # max_value = dp[0]

find_max_loop:
    beq t3, t6, exit  # if i == n, end
    slli a3, t3, 2    # offset = i * 4
    add a3, t5, a3    # dp[i] address
    lw a4, 0(a3)      # a4 = dp[i]
    blt a0, a4, update_max # if dp[i] > max_value, update max_value
    addi t3, t3, 1    # i++
    j find_max_loop   

update_max:
    mv a0, a4         # max_value = dp[i]
    j find_max_loop   

exit:
    ret
