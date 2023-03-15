BITS        64
SECTION     .text
GLOBAL      memset

memset:
	mov 	r8, 0
loop:
	cmp		rdx, r8
	je		end_loop
	mov		[rdi + r8], rsi
	inc		r8
	jmp		loop

end_loop:
	mov		rax, rdi
	ret