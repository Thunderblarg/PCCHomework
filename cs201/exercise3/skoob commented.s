	.file	"skoob.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "give number: \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "give another number: \0"
.LC3:
	.ascii "result: %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp				# Here we push our base pointer onto the stack
	.seh_pushreg	%rbp		# idk what this is
	movq	%rsp, %rbp			# we move our stack pointer into our base pointer
								# now rbp (our base) is pointing at the unbottom of the stack
	.seh_setframe	%rbp, 0		# idk what this is, something with the base pointer we just set
	subq	$48, %rsp			I THINK what this is doing is subtracting 48 from the current stack pointer, 
								# so it's 48 bytes away from our base pointer, and I'm pretty sure that
								# that's to make room for everything that's going to be tossed into stuff
								# relative to the base pointer
	.seh_stackalloc	48			# something something stack allocation, that makes sense
	.seh_endprologue			# "end prologue" kinda gives the above context
	call	__main				# why isn't this _start? I googled this, and it apparently has to do with intel vs 
	leaq	.LC0(%rip), %rax	# loading address for the instruction pointer into %rax to point at .LC0
	movq	%rax, 		%rcx	# move what's in %rax (the .LC0 address) into rcx
	call	printf				# call printf();
								# from this, I'm extrapolating (hopefully correctly)
								# that printf is using rcx for it's argument,
								# which is the .LC0 address
								# and since that's where the instruction pointer is pointing,
								# that's where printf is going?

	leaq	-4(%rbp), 	%rax	# we load the address of base pointer minus 4 into rax (our "a" variable);
	movq	%rax, 		%rdx	# then move that address into rdx
	leaq	.LC1(%rip), %rax	# we load the address of .LC1 into rax
	movq	%rax, 		%rcx	# then we move what's in rax (the .LC1 address) into rcx
	call	scanf				# scanf gets called, and at this point I'm assuming that it's using the rdx address to hold whatever it's about to get
	leaq	.LC2(%rip), %rax	# we've scanned, now we're loading the .LC2 address into rax
	movq	%rax, 		%rcx	# we move rax into rcx
	call	printf				# print it out
	leaq	-8(%rbp), 	%rax	# now we load -8 from base pointer 
	movq	%rax, 		%rdx	# we load that address into rdx again
	leaq	.LC1(%rip), %rax	# now we load our %d format specifier string into rax
	movq	%rax, 		%rcx	# we move the address for that format specifier into 
								# so now, like above, we have the .LC1 (format specifier string) in rcx, and -8(rip) (the pointer to where the number is going) in rdx
	call	scanf				# now we call scanf again
								# scanf at this point moved the two things we scanned into our stack, -4 and -8 bytes from the base pointer we saved up on top up there
	movl	-4(%rbp), 	%edx	# our first number that's currently stored in base-4 goes into edx
	movl	-8(%rbp), 	%eax	# our second number in base-8 goes into eax HEY LOOK IT'S THAT RETURN REGISTER 32 BIT EDITION THAT LOOKS FAMILIAR
	imul	%edx, 		%eax	# now we add (now multiply) the two numbers in edx and eax together, the result is put in eax
	movl	%eax, 		%edx	# now we shift eax back into edx
	leaq	.LC3(%rip), %rax	# we load the address for .LC3 into rax
	movq	%rax, %rcx			# .LC3 address is moved into rcx
	call	printf				# now we're printing again hey I bet printf is using that handy dandy return register
								# to use that number we just made and stored in eax
	movl	$0, %eax			# We're moving 0 into eax, I initially thought this was to clear it out, but our program returns 0, and it'd make sense that that's this
	addq	$48, %rsp			# we rewing the stack pointer
	popq	%rbp				# our old base pointer gets popped off the stack
	ret							# now we return
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (MinGW-W64 x86_64-ucrt-posix-seh, built by Brecht Sanders, r2) 14.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
