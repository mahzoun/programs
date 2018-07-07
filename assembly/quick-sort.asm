section .data
    ;array to sort
    source dw -6, 4, -7, 3, -8, 2, -9, 1, -10, 1, 1, -1, -1

    ;array length 
    len equ ($ - source)/2

section .text
    global _start                                          

_start:
    mov ax, len
    dec ax
    push ax   

    mov ax, 0
    push ax  

    mov rax, source                     
    push rax

    call sort                    

    mov ebx, 0
    mov eax, 1
    int 80h

sort:

    enter 12, 0     

    mov r8w, [rbp + 24]
    mov [rbp - 2], r8w 

    mov r8w, [rbp + 26]
    mov [rbp - 4], r8w

    mov r8, [rbp + 16]
    mov [rbp - 12], r8
    
    mov r8w, [rbp - 4]
    mov r9w, [rbp - 2]
    cmp r8w, r9w
    jg size_greater_than_zero
        leave
        ret 12
    size_greater_than_zero:

    mov ax, [rbp - 4]
    push ax          

    mov ax, [rbp - 2]
    push ax         

    mov rax, [rbp - 12]                     
    push rax       
 
    call partition

    dec ax

    push ax

    push ax       

    mov bx, [rbp - 2]
    push bx      

    mov rbx, [rbp - 12]                     
    push rbx    

    call sort

    pop ax

    add ax, 2

    mov bx, [rbp - 4]
    push bx    

    push ax   

    mov rbx, [rbp - 12]                     
    push rbx 

    call sort

    leave

    ret 12

partition:

    enter 12, 0   

    mov r8w, [rbp + 24]
    mov [rbp - 2], r8w    

    mov r8w, [rbp + 26]
    mov [rbp - 4], r8w   

    mov r8, [rbp + 16]
    mov [rbp - 12], r8  

    xor r8, r8         
    add r8w, [rbp - 4]
    add r8w, [rbp - 4]
    add r8, [rbp - 12]
    mov r8w, [r8]     

    xor r9, r9
    mov r9w, [rbp - 2]
    dec r9w          

    xor r10, r10
    mov r10w, [rbp - 2]
    
    xor r11, r11
    mov r11w, [rbp - 4]
    dec r11w

    partition_main_loop:

        cmp r10w, r11w
        jg partition_out_of_loop

        mov r12, [rbp - 12]
        add r12, r10
        add r12, r10
        mov ax, [r12] 

        cmp ax, r8w
        jg not_greater
            inc r9w   
            
            mov r13, [rbp - 12]
            add r13, r9
            add r13, r9

            mov bx, [r13]   
            mov cx, [r12]
            mov [r13], cx
            mov [r12], bx

        not_greater:

        inc r10w

    jmp partition_main_loop

    partition_out_of_loop:

    inc r9w
    
    mov r14, [rbp - 12]
    add r14, r9
    add r14, r9

    mov r15, [rbp - 12]
    inc r11w
    add r15, r11
    add r15, r11
    
    mov ax, [r15]
    mov bx, [r14]
    mov [r15], bx
    mov [r14], ax

    mov ax, r9w

    leave

    ret 12

