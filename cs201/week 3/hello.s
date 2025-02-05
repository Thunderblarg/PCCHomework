        .section .rodata

msg:    .asciz  "Hello World!\n"
hellolen = . - msg


        .section .text
        .global _start

_start:
        ## number of the syscall in rax
        ## after that, you can pass arguments like normal in the argument registers
        ## call the write syscall and exit appropriately

        mov     $1,         %rax        ## this says call write
        mov     $0,         %rdi        ## 0 is stdout, 2 is stderr
        lea     msg(%rip),  %rsi        ## loads the address of the message into the second argument register
        mov     $hellolen,  %rdx        ## 

        syscall

        xor     %rdi,       %rdi    ##same as mov $0, %rdi
        mov     $60,        %rax
        syscall


