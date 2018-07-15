section .data
;first operand = op11.op22
	op11 dq 0 
    op12 dq 0
;second operand = op21.op22
    op21 dq 0
    op22 dq 0
;operator = {+, -, /, *}
    operator db 0
	input_size db 0
	output_size db 0
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
    mov [op21], qword 0
    mov [op22], qword 0
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
 	mov [second_operand], r9w	
	;calculate the result and start over
	call CAL_RESULT
	ret

CAL_FIRST_OPERAND:
	xor rsi, rsi ;esi is the pointer to current char in input
	mov esi, input
	xor r9, r9 ;r9 will calculate number
	xor r10, r10
    xor r12, r12 ; r12 = len(r9)
	mov r10, 10 
    mov r11, 1
    ; check if input is negative (first char is -)
    cmp byte [esi], byte 45 ;-
    je negativate
	cal_first_op:	
		cmp byte [esi], byte 43 ;+
		je fin1
        cmp byte [esi], byte 45 ;-
		je fin1
		cmp byte [esi], byte 42 ;*
		je fin1
		cmp byte [esi], byte 47 ;/
		je fin1
        cmp byte [esi], byte 56 ;. 
        je cal_rest
		xchg r9, rax
		mul r10d
		xchg rax, r9
		add r9b, byte [esi]
		sub r9d, 48
        inc r10
		inc esi
		loop cal_first_op
    ; if code gets here, something is wrong :)
    jmp err
    cal_rest:
        ; first r9 should change to float, the number will be r9.xxxx
        fild r9
        xor r9, r9
        xor r10, r10
        jmp cal_first_op

    negativate:
        mov r11, -1
	
    fin1: ;st0 = st0 + r9 * 10 ^ (-r12)
        fild r9
        xchg r12, rcx
        calc_op1_float:
            fmul 0.1
            loop calc_op1_float
        xchg rcx, r12
        fadd st0, st1
        fmul r11
		xor r8, r8
		mov r8b, byte [esi]
		mov [operator], r8b
        cmp r9w, 0
        je not_first
        fstp op11
        not_first:
		ret
    err:
        jmp exit


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
        mov [first_operand], ax
		create_output:
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
        
