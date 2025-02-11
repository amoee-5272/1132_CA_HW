	# .file	"main.cpp"
	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
#APP
	.globl _ZSt21ios_base_library_initv
	.section	.rodata
	.align	3
.LC0:
	.string	"Error: Matrix dimensions mismatch!"
#NO_APP
	.text
	.align	1
	.globl	matrix_chain_multiplication
	.type	matrix_chain_multiplication, @function
matrix_chain_multiplication:
.LFB2010:
	.cfi_startproc
	addi	sp,sp,-144
	.cfi_def_cfa_offset 144
	sd	ra,136(sp)
	sd	s0,128(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	addi	s0,sp,144
	.cfi_def_cfa 8, 0
	mv	a5,a0
	sd	a1,-128(s0)
	sd	a2,-136(s0)
	sd	a3,-144(s0)
	sw	a5,-116(s0)
	ld	a5,-128(s0)
	sd	a5,-64(s0)
	ld	a5,-136(s0)
	sd	a5,-72(s0)
	ld	a5,-144(s0)
	sd	a5,-80(s0)
	ld	a5,-64(s0)
	ld	a5,0(a5)
	sd	a5,-24(s0)
	ld	a5,-64(s0)
	addi	a5,a5,8
	ld	a5,0(a5)
	sw	a5,-84(s0)
	ld	a5,-64(s0)
	addi	a5,a5,16
	ld	a5,0(a5)
	sw	a5,-28(s0)
	li	a5,1
	sw	a5,-32(s0)
	j	.L2
.L13:
	lw	a5,-32(s0)
	mv	a4,a5
	mv	a5,a4
	slliw	a5,a5,1
	addw	a5,a5,a4
	sext.w	a5,a5
	slli	a5,a5,3
	ld	a4,-64(s0)
	add	a5,a4,a5
	ld	a5,0(a5)
	sd	a5,-96(s0)
	lw	a5,-32(s0)
	mv	a4,a5
	mv	a5,a4
	slliw	a5,a5,1
	addw	a5,a5,a4
	sext.w	a5,a5
	addi	a5,a5,1
	slli	a5,a5,3
	ld	a4,-64(s0)
	add	a5,a4,a5
	ld	a5,0(a5)
	sw	a5,-100(s0)
	lw	a5,-32(s0)
	mv	a4,a5
	mv	a5,a4
	slliw	a5,a5,1
	addw	a5,a5,a4
	sext.w	a5,a5
	addi	a5,a5,2
	slli	a5,a5,3
	ld	a4,-64(s0)
	add	a5,a4,a5
	ld	a5,0(a5)
	sw	a5,-104(s0)
	lw	a5,-28(s0)
	mv	a4,a5
	lw	a5,-100(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	beq	a4,a5,.L3
	lui	a5,%hi(.LC0)
	addi	a1,a5,%lo(.LC0)
	lui	a5,%hi(_ZSt4cerr)
	addi	a0,a5,%lo(_ZSt4cerr)
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	mv	a4,a0
	lui	a5,%hi(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
	addi	a1,a5,%lo(_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_)
	mv	a0,a4
	call	_ZNSolsEPFRSoS_E
	li	a5,0
	j	.L4
.L3:
	lw	a5,-32(s0)
	mv	a4,a5
	sraiw	a5,a4,31
	srliw	a5,a5,31
	addw	a4,a4,a5
	andi	a4,a4,1
	subw	a5,a4,a5
	sext.w	a4,a5
	li	a5,1
	bne	a4,a5,.L5
	ld	a5,-72(s0)
	j	.L6
.L5:
	ld	a5,-80(s0)
.L6:
	sd	a5,-112(s0)
	sw	zero,-36(s0)
	j	.L7
.L12:
	sw	zero,-40(s0)
	j	.L8
.L11:
	sd	zero,-48(s0)
	sw	zero,-52(s0)
	j	.L9
.L10:
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-28(s0)
	mulw	a5,a4,a5
	sext.w	a5,a5
	lw	a4,-52(s0)
	addw	a5,a4,a5
	sext.w	a5,a5
	slli	a5,a5,3
	ld	a4,-24(s0)
	add	a5,a4,a5
	ld	a4,0(a5)
	lw	a5,-52(s0)
	mv	a3,a5
	lw	a5,-104(s0)
	mulw	a5,a3,a5
	sext.w	a5,a5
	lw	a3,-40(s0)
	addw	a5,a3,a5
	sext.w	a5,a5
	slli	a5,a5,3
	ld	a3,-96(s0)
	add	a5,a3,a5
	ld	a5,0(a5)
	mul	a5,a4,a5
	ld	a4,-48(s0)
	add	a5,a4,a5
	sd	a5,-48(s0)
	lw	a5,-52(s0)
	addiw	a5,a5,1
	sw	a5,-52(s0)
.L9:
	lw	a5,-52(s0)
	mv	a4,a5
	lw	a5,-28(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L10
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-104(s0)
	mulw	a5,a4,a5
	sext.w	a5,a5
	lw	a4,-40(s0)
	addw	a5,a4,a5
	sext.w	a5,a5
	slli	a5,a5,3
	ld	a4,-112(s0)
	add	a5,a4,a5
	ld	a4,-48(s0)
	sd	a4,0(a5)
	lw	a5,-40(s0)
	addiw	a5,a5,1
	sw	a5,-40(s0)
.L8:
	lw	a5,-40(s0)
	mv	a4,a5
	lw	a5,-104(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L11
	lw	a5,-36(s0)
	addiw	a5,a5,1
	sw	a5,-36(s0)
.L7:
	lw	a5,-36(s0)
	mv	a4,a5
	lw	a5,-84(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L12
	ld	a5,-112(s0)
	sd	a5,-24(s0)
	lw	a5,-104(s0)
	sw	a5,-28(s0)
	lw	a5,-32(s0)
	addiw	a5,a5,1
	sw	a5,-32(s0)
.L2:
	lw	a5,-32(s0)
	mv	a4,a5
	lw	a5,-116(s0)
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L13
	ld	a5,-24(s0)
.L4:
	mv	a0,a5
	ld	ra,136(sp)
	.cfi_restore 1
	ld	s0,128(sp)
	.cfi_restore 8
	.cfi_def_cfa 2, 144
	addi	sp,sp,144
	.cfi_def_cfa_offset 0
	jr	ra
	.cfi_endproc
.LFE2010:
	.size	matrix_chain_multiplication, .-matrix_chain_multiplication
	.section	.srodata,"a"
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIjEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedImEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedImEE:
	.byte	1
	.type	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, @object
	.size	_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE, 1
_ZNSt8__detail30__integer_to_chars_is_unsignedIyEE:
	.byte	1
	.ident	"GCC: () 14.2.0"
	.section	.note.GNU-stack,"",@progbits
