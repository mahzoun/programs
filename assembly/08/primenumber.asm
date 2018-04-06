section .data
	number dq 5

section .text
	global _start

_start: 
    xor r9, r9
    xor r10, r10
    mov r9, [number]
    xor r8, r8
    mov r10, r9
    dec r10
    mov rcx, r10
    nop
    do:
        xor rdx, rdx
        mov rax, r9
        cmp rcx, 1
        je fin
        div rcx
        mov r10, rcx
        cmp edx, 0
        je fin
        loop do
    fin:
        mov r11, 1 ;number is prime :)

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
