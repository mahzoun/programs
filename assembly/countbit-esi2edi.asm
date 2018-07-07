section .data
    byte_array db 0xff, 0xef, 0xff, 0xef, 0x1, 0xcd
    byte_array_length equ $ - byte_array

section .text
    global _start

_start:

    mov esi, byte_array 
    lea edi, [esi + byte_array_length - 1]
    mov r11d, esi         
    xor r12, r12 
    cmp esi, edi 
    jg main_return

    loop1:

        xor rax, rax
        mov al, [esi]     
        call bitcount   
        add r12b, bl
        inc esi
        cmp esi, edi
        jg main_return

    jmp loop1

    main_return:

    mov eax, r12d
    mov esi, r11d  

 
exit:
    mov ebx, 0
    mov eax, 1
    int 80h

bitcount:    

    mov r8, rax 
    mov r9, rcx
    mov r10, rdx
    
    xor rbx, rbx
    xor rcx, rcx
    xor rdx, rdx

    loop2:

        bsf cx, ax 
        jz return 
        btc ax, cx
        inc bx

    jmp loop2

    return:
    mov rax, r8  
    mov rcx, r9
    mov rdx, r10

    ret
