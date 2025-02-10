			.section .text
			.extern readInt
			.extern write_int
			.global _start

req1:	.ascii "User, I require a number: "
req1Len	= . - req1

req2:	.ascii "User, I require another number: "
req2Len	= . - req2

req3:	.ascii "User, if you can believe it, I require YET ANOTHER number: "
req3Len	= . - req3

printSum:	.ascii "USER, the numbers provided accumulate to A SUM OF: "
printSumLen = . - printSum

#season1:	.ascii	"1. Spring"
#season1Len = . - season1

#season2:	.ascii "2. Summer"
#season2Len = . - season2

#season3:	.ascii "3. Fall"
#season3Len = . - season3

#season4 = 	.ascii "4. Winter"
#season4Len = . - season4

#weather1:	.ascii "It's very rainy"
#weather1Len = . - weather1

#weather2:	.ascii "The air feels like it's on fire"
#weather2Len = . - weather2

#weather3:	.ascii "It's so windy"
#weather3Len = . - weather3

#weather4:	.ascii "Why does the air hurt?"
#weather4Len = . - weather4

_start:

	push %rbp					# setting up memory for our variables (the array)
	mov %rsp, %rbp
	sub $64, %rsp


	mov 	$1, 		%rax	#printing out first request
	mov 	$0, 		%rdi
	lea 	req1(%rip), %rsi
	mov 	$req1Len,	%rdx
	syscall

	call readInt              	# Call external function to read an integer from the user; result in %rax
	mov 	%rax, -8(%rbp)      # Move the value read from %rax to -8 from our base pointer (first argument for fib)

	mov 	$1, 		%rax	#printing out second request
	mov 	$0, 		%rdi
	lea 	req2(%rip), %rsi
	mov 	$req2Len,	%rdx
	syscall

	call 	readInt
	mov 	%rax, 		-16(%rbp)

	mov 	$1, 		%rax	#printing out third request
	mov 	$0, 		%rdi
	lea 	req3(%rip), %rsi
	mov 	$req3Len,	%rdx
	syscall

	call 	readInt
	mov 	%rax, 		-24(%rbp)

	lea		-24(%rbp),	%rsi	# we put the address of our last array element into rsi
								# and traverse upwards when we go through the loop
	mov 	$0, 		%rdi	# loop counter
	mov		$0,			%rax	# set rax to 0 and start accumulation in the loop

loopin:

	cmp		$3,			%rdi	# if (counter >= 3)
	jge		wrapUp				# jump out

	lea		(%rsi, %rdi, 8), 	%rdx
	add		%rdx,		%rax
	add		$1,			%rdi	# add 1 to the loop counter
	jmp		loopin				# and jump back up


wrapUp:

	mov		%rax,		%r10

	mov 	$1, 		%rax	#printing out sum
	mov 	$0, 		%rdi
	lea 	printSum(%rip), %rsi
	mov 	$printSumLen,	%rdx
	syscall

	mov		%r10,	%rdi	
	call write_int

	mov $0, %rdi
	mov $60, %rax
	syscall





