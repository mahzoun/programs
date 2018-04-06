section .data
	numbers dw 5, 11, 12, 7, 13, 11, 24
	len equ ($-numbers)/2

section .bss
	arr resw len

section .text
	global _start

_start: 
	mov cx, len
	mov edi, numbers
	mov esi, arr

	do:
		mov ax, [edi]
		mov [esi], ax
		inc edi
		inc	edi
		inc esi
		inc esi
		loop do
	
	mov cx, len
	dec cx
	mov r9w, len
	cmp r9w, 1
	je fin

	outerloop:                                               
		mov esi, arr
		xor r9, r9
	innerloop:
		inc r9
		xor r10, r10
		xor r11, r11 
		mov r10w, [esi]
		mov r11w, [esi + 2]
		cmp r10w, r11w
		jle continue
		mov [esi], r11w
		mov [esi + 2], r10w

	continue:
		add esi,2
		cmp	r9w, cx
		jne innerloop

	loop outerloop

fin:
	ret

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
