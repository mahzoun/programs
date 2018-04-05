section .data
	num1 dw 73
	num2 dw 5

section .text
	global _start

_start: 
	mov ax, [num1]
	mov bx, [num2]
	gcd:
		cmp bx, 0
		je fin
		xor dx, dx
		div bx
		cmp dx, 0
		je fin
		mov ax, bx
		mov bx, dx
		jmp gcd
	fin:
		mov dx, bx
exit:
	mov ebx, 0
	mov eax, 1
	int 80h
