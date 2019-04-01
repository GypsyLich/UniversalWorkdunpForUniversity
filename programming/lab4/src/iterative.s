	.file	"iterative.c"
	.text
	.globl	febo
	.type	febo, @function
febo:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movl	-12(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	.L2
	movl	-8(%rbp), %eax
	jmp	.L3
.L2:
	movl	-12(%rbp), %eax
	leal	1(%rax), %edi
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	leal	(%rdx,%rax), %esi
	movl	-16(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%edx, %ecx
	movl	%edi, %edx
	movl	%eax, %edi
	call	febo
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	febo, .-febo
	.globl	febo_iterative
	.type	febo_iterative, @function
febo_iterative:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %ecx
	movl	$2, %edx
	movl	$1, %esi
	movl	$1, %edi
	call	febo
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	febo_iterative, .-febo_iterative
	.globl	sum_array
	.type	sum_array, @function
sum_array:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	%edx, -16(%rbp)
	cmpl	$0, -12(%rbp)
	jne	.L7
	movl	-16(%rbp), %eax
	jmp	.L8
.L7:
	movl	-12(%rbp), %eax
	cltq
	salq	$2, %rax
	leaq	-4(%rax), %rdx
	movq	-8(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-16(%rbp), %eax
	addl	%eax, %edx
	movl	-12(%rbp), %eax
	leal	-1(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	sum_array
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sum_array, .-sum_array
	.globl	sum_array_iterative
	.type	sum_array_iterative, @function
sum_array_iterative:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %ecx
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	sum_array
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	sum_array_iterative, .-sum_array_iterative
	.ident	"GCC: (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0"
	.section	.note.GNU-stack,"",@progbits
