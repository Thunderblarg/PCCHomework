.text
.global _start
    ## q - quad sized (64 bits)
    ## l - long sized (32 bits)
    ## w - word sized (16 bits)
    ## b - byte sized ( 8 bits)
    ## add/sub source arg, destination arg
    ## source can be a value or a register
    ## destination has to be a register or a memory location
_start:
    mov $1, %rax
    mov $2, %rdx
    sub %rax, %rdx      ## sub s, d -> d = d - s
                        ## we stored our computattioin in rdx 
                        ## BUT the syscall to exit needs the exit code value passed in via rdi
    mov %rdx, %rdi

    mov $60, %rax
    syscall