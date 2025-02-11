	.option nopic
	.attribute arch, "rv32i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_v1p0_zicsr2p0_zifencei2p0_zve32f1p0_zve32x1p0_zve64d1p0_zve64f1p0_zve64x1p0_zvl128b1p0_zvl32b1p0_zvl64b1p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	chain_matrix_multiplication
	.type	chain_matrix_multiplication, @function
chain_matrix_multiplication:
.LFB16:
	.cfi_startproc
	addi	sp,sp,-80
	.cfi_def_cfa_offset 80
	sw	ra,76(sp)
	sw	s0,72(sp)
	.cfi_offset 1, -4
	.cfi_offset 8, -8
	addi	s0,sp,80
	.cfi_def_cfa 8, 0
	sw	a0,-68(s0)
	sw	a1,-72(s0)
	sw	a2,-76(s0)
	sw	a3,-80(s0)
	lw	a5,-72(s0)
	lw	a5,0(a5)
	sw	a5,-48(s0)
	lw	a5,-76(s0)
	lw	a5,0(a5)
	sw	a5,-20(s0)
	lw	a4,-48(s0)
	lw	a5,-20(s0)
	mul	a5,a4,a5
	slli	a5,a5,2
	mv	a0,a5
	call	malloc
	mv	a5,a0
	sw	a5,-24(s0)
	lw	a5,-24(s0)
	bne	a5,zero,.L2
	li	a5,0
	j	.L3
.L2:
	lw	a5,-68(s0)
	lw	a3,0(a5)
	lw	a4,-48(s0)
	lw	a5,-20(s0)
	mul	a5,a4,a5
	slli	a5,a5,2
	mv	a2,a5
	mv	a1,a3
	lw	a0,-24(s0)
	call	memcpy
	li	a5,1
	sw	a5,-28(s0)
	j	.L4
.L13:
	lw	a5,-28(s0)
	slli	a5,a5,2
	lw	a4,-72(s0)
	add	a5,a4,a5
	lw	a5,0(a5)
	sw	a5,-52(s0)
	lw	a5,-28(s0)
	slli	a5,a5,2
	lw	a4,-76(s0)
	add	a5,a4,a5
	lw	a5,0(a5)
	sw	a5,-56(s0)
	lw	a4,-20(s0)
	lw	a5,-52(s0)
	beq	a4,a5,.L5
	lw	a0,-24(s0)
	call	free
	li	a5,0
	j	.L3
.L5:
	lw	a4,-48(s0)
	lw	a5,-56(s0)
	mul	a5,a4,a5
	slli	a5,a5,2
	mv	a0,a5
	call	malloc
	mv	a5,a0
	sw	a5,-60(s0)
	lw	a5,-60(s0)
	bne	a5,zero,.L6
	lw	a0,-24(s0)
	call	free
	li	a5,0
	j	.L3
.L6:
	sw	zero,-32(s0)
	j	.L7
.L12:
	sw	zero,-36(s0)
	j	.L8
.L11:
	sw	zero,-40(s0)
	sw	zero,-44(s0)
	j	.L9
.L10:
	lw	a4,-32(s0)
	lw	a5,-20(s0)
	mul	a4,a4,a5
	lw	a5,-44(s0)
	add	a5,a4,a5
	slli	a5,a5,2
	lw	a4,-24(s0)
	add	a5,a4,a5
	lw	a4,0(a5)
	lw	a5,-28(s0)
	slli	a5,a5,2
	lw	a3,-68(s0)
	add	a5,a3,a5
	lw	a3,0(a5)
	lw	a2,-44(s0)
	lw	a5,-56(s0)
	mul	a2,a2,a5
	lw	a5,-36(s0)
	add	a5,a2,a5
	slli	a5,a5,2
	add	a5,a3,a5
	lw	a5,0(a5)
	mul	a5,a4,a5
	lw	a4,-40(s0)
	add	a5,a4,a5
	sw	a5,-40(s0)
	lw	a5,-44(s0)
	addi	a5,a5,1
	sw	a5,-44(s0)
.L9:
	lw	a4,-44(s0)
	lw	a5,-20(s0)
	blt	a4,a5,.L10
	lw	a4,-32(s0)
	lw	a5,-56(s0)
	mul	a4,a4,a5
	lw	a5,-36(s0)
	add	a5,a4,a5
	slli	a5,a5,2
	lw	a4,-60(s0)
	add	a5,a4,a5
	lw	a4,-40(s0)
	sw	a4,0(a5)
	lw	a5,-36(s0)
	addi	a5,a5,1
	sw	a5,-36(s0)
.L8:
	lw	a4,-36(s0)
	lw	a5,-56(s0)
	blt	a4,a5,.L11
	lw	a5,-32(s0)
	addi	a5,a5,1
	sw	a5,-32(s0)
.L7:
	lw	a4,-32(s0)
	lw	a5,-48(s0)
	blt	a4,a5,.L12
	lw	a0,-24(s0)
	call	free
	lw	a5,-60(s0)
	sw	a5,-24(s0)
	lw	a5,-56(s0)
	sw	a5,-20(s0)
	lw	a5,-28(s0)
	addi	a5,a5,1
	sw	a5,-28(s0)
.L4:
	lw	a4,-28(s0)
	lw	a5,-80(s0)
	blt	a4,a5,.L13
	lw	a5,-24(s0)
.L3:
	mv	a0,a5
	lw	ra,76(sp)
	.cfi_restore 1
	lw	s0,72(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 80
	addi	sp,sp,80
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
	