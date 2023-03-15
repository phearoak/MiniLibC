BITS        64
SECTION     .text
GLOBAL      rindex

rindex:
	xor		rax, rax
	mov		r8, 0
	mov		r9, 0
loop:	
	cmp	    [rdi + r8], byte 0
	jz	    strrchr_null
	cmp	    [rdi + r8], sil
	jz	    occurence
	inc		r8
	jmp	    loop
occurence:
	lea     rax, [rdi + r8]
	inc		r8
    jmp     loop
strrchr_null:
	cmp	    sil, byte 0
	jz		strrchr_end
	ret

strrchr_end:
	lea		rax, [rdi + r8]
	ret