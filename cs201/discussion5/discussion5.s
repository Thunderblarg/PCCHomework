	.file	"discussion5.c"
	.text
	.section	.rodata
	.align 8
.LC0:
	.string	"Give me a number to start spitting out squares: "
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"The sum of the squares is: %lld\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp				# subtracting from the stack for our variables
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)			# int n	
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax				# clearing eax
	call	printf@PLT				# calling print
	leaq	-20(%rbp), %rax			# this is where user input goes
									# switched this so that user input goes straight here instead of using n as a middleman 
	movq	%rax, %rsi				
	leaq	.LC1(%rip), %rax		# loading the address of our request prompt
									# into rax
	movq	%rax, %rdi				# move that address into rdi
	movl	$0, %eax				# clearing eax
	call	__isoc99_scanf@PLT		# call scanf
	movq	$0, -16(%rbp)			# I think this is sum

	#movl	$1, -20(%rbp)			# I think this is idx
	#movl	-24(%rbp), %eax
	#movl	%eax, -20
	jmp	.L2
.L3:
	movl	-20(%rbp), %eax
	imull	%eax, %eax
	cltq
	addq	%rax, -16(%rbp)
	subl	$1, -20(%rbp)			
.L2:
	#movl	-24(%rbp), %eax			# moving n into eax
	#cmpl	%eax, -20(%rbp)			# comparing n with idx
	#movl	-24(%rbp), %eax	
	#movl	%eax, -20(%rbp)
	cmpl	$0,	%eax
	jg	.L3
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L5
	call	__stack_chk_fail@PLT
.L5:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
