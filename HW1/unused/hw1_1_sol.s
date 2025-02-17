
.data
input: .word 7

.text
.global main

# This is 1132 CA Homework 1
# Implement F(x) = 4*F(floor(n-1)/2) + 8n + 3 , where F(0)=4
# Input: n in t0(x5)
# Output: F(n) in a0(x10)
# DO NOT MOTIFY "main" function

main:        
	# Load input into t0
	lw x5, input
	
	# Jump to fact   
	jal t2, fact       

	# Exit program
    # System id for exit is 10 in Ripes, 93 in GEM5 !
    li a7, 10
    ecall

fact:
	addi sp, sp, -16
	sw   t2, 8(sp) # store jump address
	sw   t0, 0(sp) # store n
	bne  t0, x0, nfact # if n != 0 jump to nfact(recursive core)
	addi a0, x0, 4 # when n == 0 set return value=4 
	addi sp, sp, 16
	jalr t2, t2, 0

nfact:
	addi t0, t0, -1 # n = n - 1	
	srli t0, t0, 1 # n = (n - 1) / 2
	jal t2, fact
	addi t1, a0, 0 # t1 := fact(n / 2)
	slli t1, t1, 2 # t1 := fact(n / 2) * 4
	lw t2, 8(sp)
	lw t0, 0(sp)
	addi sp, sp, 16	
	slli a2, t0, 3 # a2 = 8n
	add a0, a2, t1 # a0 = 8n + 4f(n / 2) 	
	addi a0, a0, 3 # a0 = 8n + 4f(n / 2) + 3
	jalr t2, t2, 0