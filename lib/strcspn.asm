BITS        64
SECTION     .text
GLOBAL      strcspn

strcspn:
    mov     r8, 0
	mov		r9,	0
loop_string:
	mov		al, [rdi]
	inc		rdi
	cmp		al, byte 0
	jz		end_loop
	jmp		loop_accept
loop_accept:
	mov		bl, [rsi + r8]
	cmp		bl,	byte 0
	jz		inc_r9
	cmp		al, bl
	je		end_loop
	inc		r8
	jmp 	loop_accept

inc_r9:
	inc		r9
	xor		r8, r8
	jmp		loop_string
end_loop:
	mov		rax, r9
	ret
