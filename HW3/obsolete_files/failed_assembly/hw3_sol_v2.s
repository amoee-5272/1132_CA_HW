	.option nopic
	.attribute arch, "rv64i2p1_m2p0_a2p1_f2p2_d2p2_c2p0_zicsr2p0_zifencei2p0"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	1
	.globl	matrix_chain_multiplication
	.type	matrix_chain_multiplication, @function
matrix_chain_multiplication:
.LFB2010:
	.cfi_startproc
	# Allocate 144 bytes of stack space.
	addi	sp,sp,-144
	.cfi_def_cfa_offset 144
	sd	ra,136(sp)
	sd	s0,128(sp)
	.cfi_offset 1, -8
	.cfi_offset 8, -16
	# Set up frame pointer.
	addi	s0,sp,144
	.cfi_def_cfa 8, 0

	# Function arguments (RISC-V calling convention):
	#   a0 = N
	#   a1 = matrix_info_addr
	#   a2 = buffer1_addr
	#   a3 = buffer2_addr

	# Save N and the three pointer arguments.
	mv	a5,a0                # a5 := N
	sd	a1,-128(s0)          # [s0-128] := matrix_info_addr
	sd	a2,-136(s0)          # [s0-136] := buffer1_addr
	sd	a3,-144(s0)          # [s0-144] := buffer2_addr
	sw	a5,-116(s0)          # [s0-116] := N

	# Convert addresses to pointers:
	ld	a5,-128(s0)          # load matrix_info_addr
	sd	a5,-64(s0)           # [s0-64] := matrix_info (uintptr_t* matrix_info)
	ld	a5,-136(s0)          # load buffer1_addr
	sd	a5,-72(s0)           # [s0-72] := buffer1 (uint64_t* buffer1)
	ld	a5,-144(s0)          # load buffer2_addr
	sd	a5,-80(s0)           # [s0-80] := buffer2 (uint64_t* buffer2)

	# current_matrix = reinterpret_cast<uint64_t*>(matrix_info[0]);
	ld	a5,-64(s0)           # load matrix_info pointer
	ld	a5,0(a5)             # load matrix_info[0]
	sd	a5,-24(s0)           # [s0-24] := current_matrix

	# current_rows = matrix_info[1];
	ld	a5,-64(s0)           # load matrix_info pointer
	addi	a5,a5,8          # address of matrix_info[1] (each element 8 bytes)
	ld	a5,0(a5)             # load matrix_info[1]
	sw	a5,-84(s0)           # [s0-84] := current_rows

	# current_cols = matrix_info[2];
	ld	a5,-64(s0)           # load matrix_info pointer
	addi	a5,a5,16         # address of matrix_info[2]
	ld	a5,0(a5)             # load matrix_info[2]
	sw	a5,-28(s0)           # [s0-28] := current_cols

	# Set step = 1 (the first multiplication step).
	li	a5,1
	sw	a5,-32(s0)           # [s0-32] := step
	j	.L2

# === Outer loop: for (step = 1; step < N; step++) ===
.L13:
	# Compute: index = step * 3, then byte offset = index * 8.
	lw	a5,-32(s0)           # load step
	mv	a4,a5                # a4 := step
	mv	a5,a4
	slliw	a5,a5,1          # a5 = step << 1   (step * 2)
	addw	a5,a5,a4          # a5 = (step * 2) + step = 3*step
	sext.w	a5,a5
	slli	a5,a5,3           # a5 = (3*step) * 8 (byte offset)
	ld	a4,-64(s0)           # load matrix_info pointer
	add	a5,a4,a5           # address of matrix_info[step*3]
	ld	a5,0(a5)             # load matrix_info[step*3] -> next_matrix address
	sd	a5,-96(s0)           # [s0-96] := next_matrix

	# next_rows = matrix_info[step*3 + 1];
	lw	a5,-32(s0)           # load step
	mv	a4,a5                # a4 := step
	mv	a5,a4
	slliw	a5,a5,1          # a5 = step*2
	addw	a5,a5,a4          # a5 = 3*step
	sext.w	a5,a5
	addi	a5,a5,1           # index = 3*step + 1
	slli	a5,a5,3           # multiply by 8 for byte offset
	ld	a4,-64(s0)           # load matrix_info pointer
	add	a5,a4,a5           # address of matrix_info[3*step+1]
	ld	a5,0(a5)             # load matrix_info[3*step+1] -> next_rows
	sw	a5,-100(s0)          # [s0-100] := next_rows

	# next_cols = matrix_info[step*3 + 2];
	lw	a5,-32(s0)           # load step
	mv	a4,a5                # a4 := step
	mv	a5,a4
	slliw	a5,a5,1          # a5 = step*2
	addw	a5,a5,a4          # a5 = 3*step
	sext.w	a5,a5
	addi	a5,a5,2           # index = 3*step + 2
	slli	a5,a5,3           # multiply index by 8
	ld	a4,-64(s0)           # load matrix_info pointer
	add	a5,a4,a5           # address of matrix_info[3*step+2]
	ld	a5,0(a5)             # load matrix_info[3*step+2] -> next_cols
	sw	a5,-104(s0)          # [s0-104] := next_cols

	# Check if (current_cols != next_rows). If not equal, print error.
	lw	a5,-28(s0)           # load current_cols
	mv	a4,a5                # a4 := current_cols
	lw	a5,-100(s0)          # load next_rows
	sext.w	a4,a4
	sext.w	a5,a5
	beq	a4,a5,.L3          # if (current_cols == next_rows) jump to .L3

.L3:
	# Select output_buffer = (step % 2 == 1) ? buffer1 : buffer2.
	lw	a5,-32(s0)           # load step
	mv	a4,a5                # a4 := step
	sraiw	a5,a4,31          # arithmetic shift right by 31
	srliw	a5,a5,31          # logical shift right by 31 (yielding 0 for positive numbers)
	addw	a4,a4,a5          # a4 remains step (since step is positive)
	andi	a4,a4,1           # a4 = step & 1
	subw	a5,a4,a5          # a5 = (step & 1) - (0) == (step & 1)
	sext.w	a4,a5            # now a4 holds (step & 1)
	li	a5,1
	bne	a4,a5,.L5          # if (step & 1 != 1) then jump to .L5
	ld	a5,-72(s0)          # output_buffer = buffer1 (if step is odd)
	j	.L6
.L5:
	ld	a5,-80(s0)          # output_buffer = buffer2 (if step is even)
.L6:
	sd	a5,-112(s0)         # [s0-112] := output_buffer

	# --- Begin matrix multiplication inner loops ---
	# Outer inner loop: for (i = 0; i < current_rows; i++)
	sw	zero,-36(s0)        # [s0-36] := i = 0
	j	.L7

.L12:
	# Inner loop: for (j = 0; j < next_cols; j++)
	sw	zero,-40(s0)        # [s0-40] := j = 0
	j	.L8

.L11:
	# Initialize dot-product: sum = 0; k = 0.
	sd	zero,-48(s0)        # [s0-48] := sum = 0
	sw	zero,-52(s0)        # [s0-52] := k = 0
	j	.L9

.L10:
	# Dot product inner loop:
	# Calculate address for current_matrix[i * current_cols + k]:
	lw	a5,-36(s0)          # load i
	mv	a4,a5               # a4 := i
	lw	a5,-28(s0)          # load current_cols
	mulw	a5,a4,a5         # a5 := i * current_cols
	sext.w	a5,a5
	lw	a4,-52(s0)          # load k
	addw	a5,a4,a5         # a5 := i * current_cols + k
	sext.w	a5,a5
	slli	a5,a5,3          # multiply index by 8 (each element is 8 bytes)
	ld	a4,-24(s0)          # load current_matrix pointer
	add	a5,a4,a5          # address of current_matrix[i*current_cols + k]
	ld	a4,0(a5)            # load current_matrix[i*current_cols + k]

	# Calculate address for next_matrix[k * next_cols + j]:
	lw	a5,-52(s0)          # load k
	mv	a3,a5               # a3 := k
	lw	a5,-104(s0)         # load next_cols
	mulw	a5,a3,a5         # a5 := k * next_cols
	sext.w	a5,a5
	lw	a3,-40(s0)          # load j
	addw	a5,a3,a5         # a5 := k * next_cols + j
	sext.w	a5,a5
	slli	a5,a5,3          # multiply index by 8
	ld	a3,-96(s0)          # load next_matrix pointer
	add	a5,a3,a5          # address of next_matrix[k*next_cols + j]
	ld	a5,0(a5)            # load next_matrix[k*next_cols + j]

	# Multiply and add into sum:
	mul	a5,a4,a5          # product = current_matrix[...] * next_matrix[...]
	ld	a4,-48(s0)          # load current sum
	add	a5,a4,a5          # new sum = old sum + product
	sd	a5,-48(s0)          # store updated sum
	lw	a5,-52(s0)          # load k
	addiw	a5,a5,1         # k++
	sw	a5,-52(s0)          # store k
.L9:
	lw	a5,-52(s0)          # load k
	mv	a4,a5               # a4 := k
	lw	a5,-28(s0)          # load current_cols
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L10        # if (k < current_cols) continue dot-product loop

	# After dot-product, store sum into output_buffer[i*next_cols + j]:
	lw	a5,-36(s0)          # load i
	mv	a4,a5               # a4 := i
	lw	a5,-104(s0)         # load next_cols
	mulw	a5,a4,a5         # a5 := i * next_cols
	sext.w	a5,a5
	lw	a4,-40(s0)          # load j
	addw	a5,a4,a5         # a5 := i * next_cols + j
	sext.w	a5,a5
	slli	a5,a5,3          # multiply by 8
	ld	a4,-112(s0)         # load output_buffer pointer
	add	a5,a4,a5          # address of output_buffer[i*next_cols + j]
	ld	a4,-48(s0)          # load sum
	sd	a4,0(a5)            # store sum into output_buffer
	lw	a5,-40(s0)          # load j
	addiw	a5,a5,1         # j++
	sw	a5,-40(s0)          # store j
.L8:
	lw	a5,-40(s0)          # load j
	mv	a4,a5               # a4 := j
	lw	a5,-104(s0)         # load next_cols
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L11        # if (j < next_cols) restart dot-product loop (.L11)
	lw	a5,-36(s0)          # load i
	addiw	a5,a5,1         # i++
	sw	a5,-36(s0)          # store i
.L7:
	lw	a5,-36(s0)          # load i
	mv	a4,a5               # a4 := i
	lw	a5,-84(s0)          # load current_rows
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L12        # if (i < current_rows) restart inner loop (j loop) at .L12

	# After finishing i-loop:
	# Update current_matrix = output_buffer and current_cols = next_cols.
	ld	a5,-112(s0)         # load output_buffer pointer
	sd	a5,-24(s0)          # current_matrix := output_buffer
	lw	a5,-104(s0)         # load next_cols
	sw	a5,-28(s0)          # current_cols := next_cols

	# Increment step.
	lw	a5,-32(s0)
	addiw	a5,a5,1         # step++
	sw	a5,-32(s0)

.L2:
	lw	a5,-32(s0)          # load step
	mv	a4,a5               # a4 := step
	lw	a5,-116(s0)         # load N
	sext.w	a4,a4
	sext.w	a5,a5
	blt	a4,a5,.L13        # if (step < N) go to next multiplication step (.L13)
	ld	a5,-24(s0)          # load current_matrix (final result)
.L4:
	# Return current_matrix in a0.
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
