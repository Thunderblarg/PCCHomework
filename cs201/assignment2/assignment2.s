			.section .data
array: .quad 0,0,0
			
			.section .rodata 

req1:	.ascii "User, I require a positive number: "
req1Len	= . - req1

req2:	.ascii "User, I require another number of positivity: "
req2Len	= . - req2

req3:	.ascii "User, if you can believe it, I require YET ANOTHER non-negative number: "
req3Len	= . - req3

printSum:	.ascii "USER, the numbers provided accumulate to A SUM OF: "
printSumLen = . - printSum

newLine:	.ascii	"\n"
newLineLen = . - newLine

			.section .text
			.extern readInt
			.extern write_int
			.global _start

sumArray: 
	# Takes two arguments, pointer to an array, length of the array
	# Returns the sum of the array
	push %rbp
	mov %rsp, %rbp

	mov 	$0, 	%rax
	mov 	$0,		%rcx
	
sumLoop:
	lea		(%rdi, %rcx, 8), 	%rdx
	addq	(%rdx),		%rax
	add		$1,			%rcx	# add 1 to the loop counter
	cmp		%rcx,		%rsi
	jg		sumLoop				# and jump back up
	
	mov %rbp, %rsp
	pop %rbp

	ret

_start:

	push %rbp					# setting up memory for our variables (the array)
	mov %rsp, %rbp
	sub $16, %rsp


	mov 	$1, 		%rax	#printing out first request
	mov 	$0, 		%rdi
	lea 	req1(%rip), %rsi
	mov 	$req1Len,	%rdx
	syscall

	call readInt             	# Call external function to read an integer from the user; result in %rax
	
	
	lea		array(%rip), %rbx
	movq	%rax,		(%rbx)

	mov 	$1, 		%rax	#printing out second request
	mov 	$0, 		%rdi
	lea 	req2(%rip), %rsi
	mov 	$req2Len,	%rdx
	syscall

	call 	readInt

	lea		array(%rip), %rbx
	movq	%rax,		8(%rbx,1)

	mov 	$1, 		%rax	#printing out third request
	mov 	$0, 		%rdi
	lea 	req3(%rip), %rsi
	mov 	$req3Len,	%rdx
	syscall

	call 	readInt

	lea		array(%rip), %rbx
	movq	%rax,		16(%rbx)

	lea		-24(%rbp),	%rsi	# we put the address of our last array element into rsi
								# and traverse upwards when we go through the loop


	mov %rbx, %rdi 	# moves array pointer into first argument
	mov $3, %rsi # moves len of array to second argument
	
	call sumArray

	movq		%rax,		-16(%rbp)

	mov 	$1, 		%rax	#printing out sum
	mov 	$0, 		%rdi
	lea 	printSum(%rip), %rsi
	mov 	$printSumLen,	%rdx
	syscall

	movq		-16(%rbp),	%rdi	
	call write_int

	mov 	$1, 		%rax	#printing out sum
	mov 	$0, 		%rdi
	lea 	newLine(%rip), %rsi
	mov 	$newLineLen,	%rdx
	syscall

	mov $0, %rdi
	mov $60, %rax
	syscall




