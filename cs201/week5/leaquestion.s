        .section .data
arr1:    .long 1,2,3,4  ## this is actually an int array
        
        .section .text
        .global _start

fun1:
        # this is setting up the stack to hold local variables
        push    %rbp
        mov     %rsp,       %rbp
        sub     $16,        %rsp
    
        #put 10 in local variable slot
        movl     $3,    -16(%rbp)   

        # start of the loop
        # let's null out the array with 0s
        mov     -16(%rbp),  %rcx

1:
        cmp     $0,          %rcx
        jl      2f
        lea     arr1(%rip),  %rbx
        movl    $0,         (%rbx, %rcx, 4)
        dec     %rcx
        jmp     1b

2:

        leave
        ret


_start:
        call    fun1
        mov     $60,            %rax
        mov     arr1(%rip),     %rdi
        syscall