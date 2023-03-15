BITS        64
SECTION     .text
GLOBAL      strpbrk

strpbrk:
    mov     r8, 0
	xor		rax, rax
loop_string:
	mov		al, [rdi]
	cmp		al, byte 0
	je		not_found
	jmp		loop_accept

loop_accept:
	mov		bl, [rsi + r8]
	cmp		bl,	byte 0
	je		reset_accept
	cmp		al, bl
	je		end_loop
	inc		r8
	jmp 	loop_accept
reset_accept:
	mov		r8, 0
	inc		rdi
	jmp		loop_string
end_loop:
	mov		rax, rdi
	ret
not_found:
	ret