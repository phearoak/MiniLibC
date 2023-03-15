BITS        64
SECTION     .text
GLOBAL      strrchr

strrchr:
	xor		rax, rax
loop:	
	cmp	    [rdi], byte 0
	jz	    strrchr_null
	cmp	    [rdi], sil
	jz	    occurence
	inc	    rdi
	jmp	    loop
occurence:
	mov     rax, rdi
	inc     rdi
    jmp     loop
strrchr_null:
	cmp	    sil, byte 0
	jz		strrchr_end
	ret

strrchr_end:
	mov		rax, rdi
	ret