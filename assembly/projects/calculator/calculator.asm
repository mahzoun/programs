section .data
	input_max_size equ 25
	operator db 0
	first_operand dw 0
	second_operand dw 0
	input_size dw 0
	output_size dw 0
section .bss
	input resb input_max_size
	output resb input_max_size
	temp_array resb input_max_size

section .text
	global _start

_start:
	call INPUT
	call CALCULATE
	call OUTPUT

exit:
	mov ebx, 0
	mov eax, 1
	int 80h

INPUT:
	;clean input buffer
	mov cx, input_max_size
	mov r9d, esi
	mov esi, input
	clean:
		xor r8, r8
		mov [esi], r8d
		inc esi
		loop clean
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
 	mov [second_operand], r9w	
	;calculate the result and start over
	call CAL_RESULT
	ret

CAL_FIRST_OPERAND:
	xor rsi, rsi ;esi is the pointer to current char in input
	mov esi, input
	xor r9, r9
	xor r10, r10
	mov r10, 10
	cal_first_op:	
		cmp byte [esi], byte 43 ;r8d is +
		je fin1
		cmp byte [esi], byte 45 ;r8d is -
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
		inc esi
		loop cal_first_op
	fin1:
		xor r8, r8
		mov r8b, byte [esi]
		mov [operator], r8b
		mov [first_operand], r9w
		ret
	
CAL_SECOND_OPERAND:
	xor r9, r9
	xor r10, r10
	mov r10, 10
	xor rax, rax
	inc esi
	cal_second_op:	
		cmp byte [esi], byte 10 ;r8d is \n 
		je fin2
		xchg r9, rax
		mul r10d
		xchg rax, r9
		add r9b, byte [esi]
		sub r9d, 48
		inc esi
		loop cal_second_op
	fin2:
		mov [second_operand], r9w
		ret
	
CAL_RESULT:
	xor r8, r8 ;first operand
	xor r9, r9 ; second operand
	xor r10, r10 ; operator
	mov r8w, [first_operand]
	mov r9w, [second_operand]
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
		xor rax, rax
		mov rax, r8
		mul r9
		jmp finilize
	division:
		xor rax, rax
		mov rax, r8
		div r9
		jmp finilize
	
	finilize:
		xor rsi, rsi
		mov esi, temp_array
		xor rbx, rbx
		mov bx, 10
		xor r10, r10; size of output
		create_output:
			div bx
			mov [esi], dx
			inc esi
			cmp ax, 0
			jne create_output
		print_output:
			inc r10
			mov [output_size], r10w
			xor edi, edi
			mov edi, output
			mov cl, [esi]
			mov [edi], cl
			dec esi
			inc edi
			cmp esi, temp_array
			jne print_output
	finilize2:
		ret



























