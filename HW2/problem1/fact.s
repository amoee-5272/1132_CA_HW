
.text
.global fact

fact:
    mv t0, a0
recursive:
	addi sp, sp, -16
	sw   ra, 8(sp) # store jump address
	sw   t0, 0(sp) # store n
	bne  t0, x0, nfact # if n != 0 jump to nfact(recursive core)
	addi a0, x0, 4 # when n == 0 set return value=4 
	addi sp, sp, 16
	# jalr t2, t2, 0
    ret

nfact:
	addi t0, t0, -1 # n = n - 1	
	srli t0, t0, 1 # n = (n - 1) / 2
	jal ra, recursive
	addi t1, a0, 0 # t1 := fact(n / 2)
	slli t1, t1, 2 # t1 := fact(n / 2) * 4
	lw ra, 8(sp)
	lw t0, 0(sp)
	addi sp, sp, 16	
	slli a2, t0, 3 # a2 = 8n
	add a0, a2, t1 # a0 = 8n + 4f(n / 2) 	
	addi a0, a0, 3 # a0 = 8n + 4f(n / 2) + 3
	# jalr t2, t2, 0
    ret




