
.data
input: .word   7
str1:  .string "n = "
str2:  .string "\nResult is "

.text
main:        
        lw  a0, input   # Load input into a0
        jal ra, fact       # Jump to fact

        # Print the result 
        jal ra, printResult

        # Exit program
        li a7, 10
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

# --- printResult ---
# DO NOT MODIFY THIS PART
# t0: Result

printResult:
        
        la a0, str1
        li a7, 4
        ecall
        
        lw  a0, input
        li a7, 1
        ecall
        
        la a0, str2
        li a7, 4
        ecall
        
        addi a0, t0, 0
        li a7, 1
        ecall
        jalr ra

