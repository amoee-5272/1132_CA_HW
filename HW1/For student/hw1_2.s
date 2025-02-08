.data
nums:   .word 4, 10, 4, 3, 8, 9, 6, 2   # input sequence
n:      .word 8                        # sequence length
dp:     .word 0, 0, 0, 0, 0, 0, 0, 0   # dp array


.text
.globl main

# This is 1132 CA Homework 1 Problem 2
# Implement Longest Increasing Subsequence Algorithm
# Output: Length of Longest Increasing Subsequenc in a0(x10)


main:

    lw a0, n          # a0 = n 
    la t5, dp         # t3 = &dp[0]
    la t4, nums       # t4 = &nums[0]
    
    
init_dp:
    # Initialize dp[i] = 1 

Calculate_dp:
    # Write a loop to calculate dp[i] 

find_max:
    # Write a loop to find max(dp[i]), and store the answer in a0 

exit:
	# Exit program
    # System id for exit is 10 in Ripes, 93 in GEM5 !
    li a7, 10
    ecall


