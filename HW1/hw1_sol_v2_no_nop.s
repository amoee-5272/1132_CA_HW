
.data
input: .word 7
str1:  .string "n = "
str2:  .string "\nResult is "

.text

# This is 1132 CA Homework 1
# Implement F(x) = 4*F(floor(n-1)/2) + 8n + 3 , where F(0)=4
# You MUST store the result in t0(x5) register
# DO NOT MOTIFY "main" function

main:        
        # Load input into a0
        auipc x10 0x10000
        nop
        nop
        lw x10 0 x10   
        
        # Jump to fact   
        jal ra, fact       

        # Exit program
        li a7, 10
        nop
        nop
        nop
        ecall

fact:
        addi sp, sp, -16
        sw   ra, 8(sp) # store jump address
        sw   a0, 0(sp) # store n
        bne  a0, x0, nfact # if n!= 0 jump to nfact(recursive core)
        addi t0, x0, 4 # when n == 0 set return value=4 
        addi sp, sp, 16
        jalr ra

nfact:
        addi a0,a0,-1 #n=n-1
        srli a0,a0,1 #n=(n-1)/2
        jal ra,fact
        addi x6,t0,0 # x6:= fact(n/2)
        slli x6,x6,2 # x6:= fact(n/2)*4
        lw ra,8(sp)
        lw a0,0(sp)
        addi sp,sp,16
        slli a2,a0,3 # a2=8n
        add t0,a2,x6 # t0=8n+4f(n/2)
        addi t0,t0,3 # t0=8n+4f(n/2)+3
        jalr ra






