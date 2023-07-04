section .data
    format db 'Hello, Holberton', 0
    newline db 10, 0

section .text
    global main
    extern printf

main:
    sub rsp, 8      ; Align stack to 16-byte boundary

    mov rdi, format ; Load format string address into rdi
    xor eax, eax    ; Clear eax (optional, since it's already zero-initialized)
    call printf     ; Call printf to print the format string

    mov rdi, newline ; Load newline string address into rdi
    xor eax, eax    ; Clear eax (optional, since it's already zero-initialized)
    call printf     ; Call printf to print the newline

    add rsp, 8      ; Restore stack pointer
    mov eax, 0      ; Set return value to 0
    ret             ; Return from main
