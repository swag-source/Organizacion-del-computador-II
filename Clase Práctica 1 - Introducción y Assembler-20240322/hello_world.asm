section .data
    msg db "Ramiro Seltzer + 715/22 + 'Dividir y Conquistar'.", 0ah 
    ; 0ah es un carácter de nueva línea
    
    len equ $ - msg
    ; calcula 

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1 
    mov rsi, msg
    mov rdx, len
    syscall
    mov rax, 60
    mov rdi, 0
    syscall
