        .section .bss
buff:   .skip 128

        .section .rodata
msg1:   .asciz "Was Zero\n"
msg1len = . - msg1

msg2:   .asciz "Not Zero\n"
msg2len = . - msg2

        .section .text
        .global _start


_start:
        lea     buff(%rip),     %rbx
        cmpb     $0,             (%rbx)
        ## mov     $128,           %rdx
        ## syscall

        ## set up the right
        ## the number of bytes is in %rax Here

        ## mov     %rax,           %rdx        ## move the number of bytes to %rdx
        ## mov     $1,             %rax
        ## lea     buff(%rip),     %rsi
        ## mov     $0,             %rdi
        ## syscall

        ## to start, let's just print out what read puts in %rax

writeLabel:
        mov     $1,             %rax

    ##  mov     %rax,           %rdi
        xor     %rdi,           %rdi
        mov     $60,            %rax
        syscall

isZero:
        ## set %rsi and %rdx
        ## the number of bytes is in %rax Here
        lea     msg1(%rip),     %rsi
        mov     msg1len,        %rdx
        jmp writeLabel

notZero:
        lea     msg2(%rip),     %rsi
        mov     $msg2len,       %rdx


