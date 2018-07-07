section .data
    source dq 1.e0, 2.e0, 3.e0, 4.e0, 5.e0, 6.e0, 7.e0, 8.e0, 0.e0, 0.e0
    len equ ($ - source)/8

section .text
    global _start                                          

_start:
    push qword source
    push qword len
    fild qword [rbp + 16]
    fldz

    mov rcx, [rbp + 16]
    
    mov rdi, [rbp + 24]
    xor r8, r8

    main_loop:
        fadd qword [rdi + r8]
        add r8, 8
    loop main_loop

    fdiv ST1



exit:
    mov ebx, 0
    mov eax, 1
    int 80h
