BITS        64
SECTION     .text
GLOBAL      strncmp

strncmp:
    xor     rcx, rcx
	xor 	r8, r8
loop:
	mov		al, [rdi + rcx]
	mov		bl, [rsi + rcx]
	inc		rcx
	cmp		al, byte 0
	je		compare
	cmp		bl, byte 0
	je		compare
	cmp		rdx, rcx
	je 		compare
	cmp		al, bl
	jne		compare
	jmp		loop
compare:
	sub		al, bl
	movsx	rax, al
	ret