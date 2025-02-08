
.data
input: .word 7

.text
.global main

# This is 1132 CA Homework 1 Problem 1
# Implement F(x) = 4*F(floor(n-1)/2) + 8n + 3 , where F(0)=4
# Input: n in t0(x5)
# Output: F(n) in a0(x10)

main:        
	# Load input into t0
	lw x5, input
	
	# Jump to fact, your need to jump back to main after finishing the function 
	jal t2, fact       

	# Exit program
    # System id for exit is 10 in Ripes, 93 in GEM5 !
    li a7, 10
    ecall

fact:
	#=========== Write Your Function Here ==========#