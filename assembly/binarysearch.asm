section .data
    source dw  1, 2, 3, 4, 5, 6
    len equ ($ - source)/2
    item dw 2    

section .text
    global _start                                          

_start:

    push word [item]             
    mov ax, len
    dec ax
    push ax                             
    push word 0                         
    push qword source                   
    call binary_search             
    
exit:
    mov ebx, 0
    mov eax, 1
    int 80h

binary_search:   

    enter 14, 0
    mov r8w, [rbp + 24]
    mov [rbp - 2], r8w                  
    mov r8w, [rbp + 26]
    mov [rbp - 4], r8w                  
    mov r8w, [rbp + 28]
    mov [rbp - 6], r8w                 
    mov r8, [rbp + 16]
    mov [rbp - 14], r8                
    mov r8w, [rbp - 4]                 
    mov r9w, [rbp - 2]
    cmp r8w, r9w

    jge end_not_less_than_start

        mov ax, -1
        leave    
        ret 14
   
 end_not_less_than_start:
   
    xor r8, r8      
    mov r8w, [rbp - 4]
    sub r8w, [rbp - 2]
    sar r8, 1
    xor r9, r9
    mov r9w, [rbp - 2]
    add r8, r9 
    mov r9, [rbp - 14] 
    add r9, r8
    add r9, r8
    mov r10w, [r9]
    mov r9w, [rbp - 6]
    cmp r9w, r10w
    jne not_equal
        mov ax, r8w
        leave    
        ret 14
    not_equal:

    cmp r9w, r10w

    jnl not_lower
        push word [rbp - 6]   
        mov ax, r8w
        dec ax
        push ax 
        push word [rbp - 2]
        push qword [rbp - 14]
        call binary_search
        leave    
        ret 14
    
    not_lower:

    push word [rbp - 6]

    push word [rbp - 4]

    mov ax, r8w
    inc ax
    push ax           

    push qword [rbp - 14]  

    call binary_search

    leave    
    ret 14
