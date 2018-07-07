section .data
    x dq 50 
    n dq 5

section .text
    global _start                                          
_start:
    push qword [x]
    push qword [n]
    fldz
    fld qword [rbp + 24]
    fld1
    fld1
    fldz

    mov r8, 1
    mov [rbp - 8], r8
    main_loop:

        fild qword [rbp - 8]
        fmul st2
        fstp st2

        fld st2
        fmul st4
        fstp st3

        fld st2
        fdiv st2
        faddp st5, st0

        inc qword [rbp - 8]
        mov r8, [rbp - 8]
        cmp r8, [rbp + 16]
    jle main_loop
exit:
    mov ebx, 0
    mov eax, 1
    int 80h
