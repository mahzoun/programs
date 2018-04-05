section .data
	number dw 1234

section .text
	global _start

addeven:
	add r12, rdx
	jmp do

_start: 
	mov ax, [number]
	xor r8, r8 ;result will be in r8
	xor r9, r9
	xor r12, r12
	mov cx, 10
	do:
		inc r9
		xor rdx, rdx
		div cx   ; smallest digit is in cx
		and r9, 1
		cmp r9, 0
		je addeven
		add r8, rdx
		cmp ax, 0
		jne do
	
	fin:
		mov rax, r8
		mov rbx, r12
		jmp exit

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
