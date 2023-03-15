BITS        64
SECTION     .text
GLOBAL      strcmp

strcmp:
    xor     rcx, rcx
	xor 	r8, r8

loop:
	mov		al, [rdi + rcx]
	mov		bl, [rsi + rcx]
	cmp		al, byte 0
	je		compare
	cmp		bl, byte 0
	je		compare
	cmp		al, bl
	jne		compare
	inc		rcx
	jmp		loop
compare:
	sub		al, bl
	cmp 	al, byte 0
	jg 		greater
	cmp 	al, byte 0
	jl 		lower
	mov		rax, 0x00
	ret

lower:
	mov		rax, -1
	ret

greater:
	mov		rax, 1
	ret