BITS        64
SECTION     .text
GLOBAL      strlen

strlen:
    push    rcx
    xor     rcx, rcx
loop:
    cmp     [rdi], byte 0
    jz      strlen_null
    inc     rcx
    inc     rdi
    jmp     loop
strlen_null:
    mov     rax, rcx
    pop     rcx
    ret