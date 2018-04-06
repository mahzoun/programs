section .data
	number dw 1234

section .text
	global _start

_start: 
	mov ax, [number]
	xor r8, r8 ;result will be in r8
	mov cx, 10
	do:
		xor rdx, rdx
		div cx
		add r8, rdx
		cmp ax, 0
		jne do

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
