BITS        64
SECTION     .text
GLOBAL      strstr

strstr:
    mov		r8b, [rsi]
    xor		rcx, rcx
loop:
    cmp		rdi, byte 0
    je		not_found
    cmp		rsi, byte 0
    je		not_found
    mov		r8b, [rdi + rcx]
    mov		r9b, [rsi + rcx]
    cmp		r9b, byte 0
    je		end_loop
    cmp		r8b, r9b
    jne		reset_loop
    inc		rcx
    jmp		loop
reset_loop:
    cmp		r8b, byte 0
    je		not_found
    inc		rdi
    mov		r8b, [rsi]
    xor		rcx, rcx
    jmp		loop
not_found:
    mov     rax, 0x00
	ret
end_loop:
    mov     rax, rdi
	ret