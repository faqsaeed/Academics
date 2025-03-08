[org 0x0100]

mov bx, 0

.find:

    mov ax, [Max]
    cmp ax, [Array1 + bx]
    jl .change

.dec:

    add bx, 2
    cmp bx, 18
    jnz .find
    jmp .terminate

.change:
    mov cx, [Array1 + bx]
    mov [Max], cx
    jmp .dec

.terminate:
    mov ax, 0x4c00
    int 0x21

Array1: dw 0, 1, 2, 3, 4, 5, 6, 9, 8
;Array1: dw -3, -5, 7, 4, -9, 2, 10, 12, -16
Max: dw 0



