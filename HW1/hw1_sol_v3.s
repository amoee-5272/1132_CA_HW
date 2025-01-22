
.data
input: .word 7
str1:  .string "n = "
str2:  .string "\nResult is "

.text
.global main

# This is 1132 CA Homework 1
# Implement F(x) = 4*F(floor(n-1)/2) + 8n + 3 , where F(0)=4
# You MUST store the result in t0(x5) register
# DO NOT MOTIFY "main" function

main:        
	# Load input into a0
	# auipc x10 0x10000
	lw x10, input
	
	# Jump to fact   
	jal t2, fact       

	# Exit program
	ret

fact:
	addi sp, sp, -16

	sw   t2, 8(sp) # store jump address
	sw   a0, 0(sp) # store n
	bne  a0, x0, nfact # if n != 0 jump to nfact(recursive core)
	addi t0, x0, 4 # when n == 0 set return value=4 
	addi sp, sp, 16
	jalr t2, t2, 0

nfact:
	addi a0, a0, -1 # n = n - 1
	
	
	srli a0, a0, 1 # n = (n - 1) / 2
	jal t2, fact
	addi t1, t0, 0 # t1 := fact(n / 2)
	
	
	slli t1, t1, 2 # t1 := fact(n / 2) * 4
	lw t2, 8(sp)
	lw a0, 0(sp)
	addi sp, sp, 16
	
	slli a2, a0, 3 # a2 = 8n
	
	
	add t0, a2, t1 # t0 = 8n + 4f(n / 2)
	
	
	addi t0, t0, 3 # t0 = 8n + 4f(n / 2) + 3
	jalr t2, t2, 0
