section .data
	num1 dw 75
	num2 dw 5

section .text
	global _start

_start: 
	mov ax, [num1]
	mov bx, [num2]
	gcd:
		cmp bx, 0
		je exit
		xor dx, dx
		div bx
		cmp dx, 0
		je lcm
		mov ax, bx
		mov bx, dx
		jmp gcd
	lcm:
		mov r8, rbx
		mov ax, [num1]
		mov bx, [num2]
		mul bx
		xor dx, dx
		div r8w
		jmp exit
exit:
	mov ebx, 0
	mov eax, 1
	int 80h
