BITS        64
SECTION     .text
GLOBAL      strcasecmp

strcasecmp:
	push    rcx
    xor     rcx, rcx
loop:
	mov		al, [rdi + rcx]
	mov		bl, [rsi + rcx]
	cmp		al, byte 0
	je		end_loop
	cmp		bl, byte 0
	je		end_loop
	inc		rcx
	cmp		al, bl
	jne		compare
	jmp		loop
compare:
	cmp		al, 'Z'
	jl 		lowercasefst
	cmp		bl, 'Z'
	jl 		lowercasesnd
	jmp		end_loop
lowercasefst:
	cmp		al, 'A'
	jl		end_loop
	add		al, 32
	cmp		bl, 'Z'
	jl 		lowercasesnd
	cmp 	al, bl
	jne		end_loop
	jmp 	loop
lowercasesnd:
	cmp		bl, 'A'
	jl		end_loop
	add		bl, 32
	cmp 	al, bl
	jne		end_loop
	jmp 	loop
end_loop:
	pop		rcx
	sub		al, bl
	movsx	rax, al
	ret