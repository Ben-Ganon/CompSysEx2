.file	"main.c"
	.text
	.section	.rodata
.LC0:
	.string	"this is you answer: %d"
	.text
	.globl	main
	.type	main, @function
go:
    mov $0, %rax #defining sum
    mov $0, %rsi #defining iterator
    .while:
        mov $0, %rbx #clearing rbx for usage
        leaq (%rdi, %rsi,4), %rbx #loading the adrress of 4*rsi into rbx
        movl (%rbx), %ebp
        test $1, %ebp #checking if the contents of ebx are even 
        jne .if1
        .if1:
            
        
        
        inc %rsi #incrementing the iterator
        cmp $10, %rsi
        jne .while
        
even: 
    mov %sil, %cl
    sal %cl, %rsi
    mov %rsi, %rax
    
main:
    movq %rsp, %rbp #for correct debugging
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$2, -48(%rbp)
	movl	$1, -44(%rbp)
	movl	$2, -40(%rbp)
	movl	$1, -36(%rbp)
	movl	$1, -32(%rbp)
	movl	$1, -28(%rbp)
	movl	$1, -24(%rbp)
	movl	$1, -20(%rbp)
	movl	$1, -16(%rbp)
	movl	$1, -12(%rbp)
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	go@PLT
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:

