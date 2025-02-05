        .section .bss
buff:   .skip 128

        .section .text
        .global _start


_start:
        ## setting up read
        mov     $0,             %rax
        mov     $1,             %rdi
        lea     buff(%rip),     %rsi ## pass the pointer

        mov     $128,           %rdx
        syscall

        ## set up the right
        ## the number of bytes is in %rax Here

        mov     %rax,           %rdx        ## move the number of bytes to %rdx
        mov     $1,             %rax
        lea     buff(%rip),     %rsi
        mov     $0,             %rdi
        syscall

        ## to start, let's just print out what read puts in %rax

    ##  mov     %rax,           %rdi
        xor     %rdi,           %rdi
        mov     $60,            %rax
        syscall