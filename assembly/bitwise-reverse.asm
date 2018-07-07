section .data
     num dq 0x888888
section .text
    global _start
_start:
    
    mov rax, [num]
    mov r8, rax   
    mov r9, rcx
    mov r10, rbx

    mov rdx, rdx 
    xor rcx, rcx

    main_loop:

    mov rbx, 63

    bsf rcx, rax 
    jz return   
    sub rbx, rcx
    bts rdx, rbx
    btc rax, rcx

    jmp main_loop 

    return:
    mov rax, r8  
    mov rcx, r9
    mov rbx, r10

exit:
    mov ebx, 0
    mov eax, 1
    int 80h

