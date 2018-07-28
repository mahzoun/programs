section .data	
	operator dq 0
	X dq 0
	X2 dq 0
	Y dq 0
    Y2 dq 0
	input_size dd 0
	output_size dd 0
    input_max_size equ word 100

section .bss
	input resb input_max_size
	output resb input_max_size
	temp_array resb input_max_size

section .text
	global _start

_start:
    run:
    xor esi, esi
    xor r9, r9
    mov [Y], word 0
    mov [operator], byte 0
    debug1:
	call INPUT
	debug2:
    call CALCULATE
	debug3:
    call OUTPUT
    jmp run

exit:
	mov ebx, 0
	mov eax, 1
	int 80h

INPUT:
	;clean input buffer
    xor rcx, rcx
	mov cx, input_max_size
	mov r9d, esi
	mov esi, input
	clean:
		xor r8, r8
		mov [esi], r8d
		inc esi
		loop clean
    debug:
	mov esi, r9d
	mov eax, 3                              
	mov ebx, 0                              
	mov ecx, input                           
	mov rdx, input_max_size
	int 80h
	mov [input_size], ax
    ret

OUTPUT:
	mov eax, 4
	mov ebx, 1
	mov ecx, output
	mov edx, [output_size]
	int 80h
	ret

CALCULATE:
	;calculate operand
	call CAL_FIRST_OPERAND
	call CAL_SECOND_OPERAND
 	mov [Y], r9	
	;calculate the result and start over
	call CAL_RESULT
	ret

CAL_FIRST_OPERAND:
	xor rsi, rsi ;esi is the pointer to current char in input
	mov esi, input
	xor r9, r9
	xor r10, r10
	mov r10, 10
    mov [X2], r15
    xor r15, r15 ; to save number of digits after first oprenad
    xor r14, r14
	cal_first_op:
        cmp byte [esi], byte 46 ;r8d is .
        je floater1
		cmp byte [esi], byte 43 ;r8d is +
		je fin1
        cmp byte [esi], byte 45 ;r8d is +
		je fin1
		cmp byte [esi], byte 42 ;r8d is *
		je fin1
		cmp byte [esi], byte 47 ;r8d is /
		je fin1
		xchg r9, rax
		mul r10d
		xchg rax, r9
		add r9b, byte [esi]
		sub r9d, 48
        cont:
		inc esi
        add r15, r14
		loop cal_first_op
	fin1:
		xor r8, r8
		mov r8b, byte [esi]
		mov [operator], r8b
        cmp r9w, 0
        je not_first
		mov [X], r9w
        jmp ender
        not_first:
        mov r15, [X2]
        ender:
		ret
    floater1:
        inc r14
        jmp cont
	
CAL_SECOND_OPERAND:
	xor r9, r9
	xor r10, r10
	mov r10, 10
	xor rax, rax
	inc esi
    xor r12, r12
    xor r13, r13
	cal_second_op:	
		cmp byte [esi], byte 10 ;r8d is \n 
		je fin2
        cmp byte [esi], byte 46 ;r8d is .
        je floater2    
		xchg r9, rax
		mul r10d
		xchg rax, r9
		add r9b, byte [esi]
		sub r9d, 48
        cont2:
		inc esi
        add r13, r12
		loop cal_second_op
	fin2:
		mov [Y], r9w
		ret
    floater2:
    inc r12
    jmp cont2
	
CAL_RESULT:
	xor r8, r8 ;first operand
	xor r9, r9 ; second operand
	xor r10, r10 ; operator
	mov r8, [X]
	mov r9, [Y]
	mov r10b, [operator]
	cmp r10b, 43
	je sum
	cmp r10b, 45
	je subtract
	cmp r10b, 42
	je multiplication
	cmp r10b, 47
	je division
	
	;TODO add jump failure

	sum:
		xor rax, rax
		add r8, r9
		mov rax, r8
		jmp finilize
	subtract:
		xor rax, rax
		sub r8, r9
		mov rax, r8
		jmp finilize
	multiplication:
        add r15, r14
		xor rax, rax
		mov rax, r8
		mul r9
		jmp finilize
	division:
        cdq
        xor r15, r13
        sub r15, r13
		xor rax, rax
		mov rax, r8
		div r9
		jmp finilize
	
	finilize:
		xor rsi, rsi
		mov esi, temp_array
		xor rbx, rbx
        xor r14, r14 ;count poistions 
		mov bx, 10
		xor r10, r10; size of output
        mov [X], ax
        ;dec r15 
		create_output:
            inc r14
            cmp r14, r15
            je put_dot
            contoutput:
			xor dx, dx
            div bx
			mov [esi], dx
			inc esi
			cmp ax, 0
			jne create_output
        xor edi, edi
        mov edi, output
		print_output:
            dec esi
			inc r10
			mov [output_size], r10w
			mov cl, [esi]
            add cl, 48
			mov [edi], cl
			inc edi
			cmp esi, temp_array
			jne print_output
        ret
        put_dot:
            mov [esi], dword -2
            inc esi
            jmp contoutput
        
