section .data
	number dw 0x245

section .text
	global _start

_start: 
	mov ax, [number]
	mov cx, 3
	mov bx, 16
	xor rdx, rdx
	do:
	div bx
	mov r8, 10
	mov r9, rax
	mov rax, rdx
	mul r8
	mov r10, rax
	mov rax, r9
	add r10, rdx
	loop do

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
