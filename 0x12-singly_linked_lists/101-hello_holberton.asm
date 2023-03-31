section .data
    msg db "Hello, Holberton", 0Ah ; message to print followed by a new line

section .text
    global main
    extern printf

main:
    push rbp
    mov rbp, rsp

    ; Call printf to print the message
    mov edi, msg
    xor eax, eax
    call printf

    ; Clean up the stack and return
    mov rsp, rbp
    pop rbp
    xor eax, eax
    ret
