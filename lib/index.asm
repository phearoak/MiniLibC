BITS		64
SECTION 	.text
GLOBAL 		index

index:
loop:	
	cmp		[rdi], sil
	jz		occurence
	cmp		[rdi], byte 0
	jz		strchr_null
	inc		rdi
	jmp		loop
occurence:
	lea		rax, [rdi]
	ret
strchr_null:
	mov		rax, 0x00
	ret