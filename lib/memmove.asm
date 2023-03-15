BITS        64
SECTION     .text
GLOBAL      memmove

memmove:
	mov 	r8, 0
loop:
	cmp		rdx, r8
	je		end_loop
	mov 	al, [rsi + r8]
	mov		[rdi + r8], al
	inc		r8
	jmp		loop

end_loop:
	mov		rax, rdi
	ret