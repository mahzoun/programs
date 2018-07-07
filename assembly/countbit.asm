section .data
     num dq 0x9999898888

section .text
    global _start
_start:
    
    mov rax, [num]
    mov r8, rax
    mov r9, rcx
    mov r10, rdx
    
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx

    mainloop:
        bsf rcx, rax
        jz return  
        btc rax, rcx 
        inc bl

    jmp mainloop

    return:
    mov rax, r8             ;restore previous values
    mov rcx, r9
    mov rdx, r10

exit:
    mov ebx, 0
    mov eax, 1
    int 80h
