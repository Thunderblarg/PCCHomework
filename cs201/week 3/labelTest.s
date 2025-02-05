        .section .rodata

msg1:   .asciz "In the first sublabel\n"
msg1len = . - msg1

msg2:   .asciz "In the second sublabel\n"
msg2len = . - msg2

        .section .text
        .global _start

_start:
        call    bigLabel2
        call    bigLabel1

        ## exit
1:
        mov     $60,                %rax
        xor     %rdi,               %rdi
        syscall

bigLabel1:
        jmp 1f

1:
        lea     msg1(%rip),         %rsi
        mov     $msg1len,           %rdx
        mov     $1,                 %rax
        mov     $0,                 %rdi
        syscall
        ret

bigLabel2:
        jmp 1f
        
1:
        lea     msg2(%rip),         %rsi
        mov     msg2len,            %rdx
        mov     $1,                 %rax
        mov     $0,                 %rdi
        syscall
        ret
