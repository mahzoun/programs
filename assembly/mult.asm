section .data
    op1 dd -23647
    op2 dd 23647

section .text
    global _start                                          
_start:

    xor rax, rax
    mov eax, [op1]

    xor rbx, rbx
    mov ebx, [op2] 
    mov r9, rax 

    xor r8, r8 

    cmp eax, 0
    jge op1_not_negative
        inc r8
        neg eax
    op1_not_negative:

    cmp ebx, 0
    jge op2_not_negative
        inc r8
        neg ebx
    op2_not_negative:

    xor r10, r10
    mov r10d, ebx

    xor rdx, rdx

    main_loop:
        cmp eax, 0
        je return 

        dec eax
        add rdx, r10
    jmp main_loop

    return:
    cmp r8, 1                           
    jne result_not_negative   
        neg rdx
    result_not_negative:
    mov rax, r9              
 
exit:
    mov ebx, 0
    mov eax, 1
    int 80h
