section .data
	number dq 6

section .text
	global _start

sum:
    add r8, r10
    dec rcx
    cmp rcx, 0
    jz fin
    jmp do

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
        div rcx
        mov r10, rcx
        cmp edx, 0
        jz sum
        loop do
    fin:
        cmp r9, r8

exit:
	mov ebx, 0
	mov eax, 1
	int 80h
