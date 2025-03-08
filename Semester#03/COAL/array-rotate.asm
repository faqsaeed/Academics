[org 0x0100]

jmp START

    arr1 dw 1, 2, 3, 4
    size dw 4
    direction dw 0
    rotations dw 1

START:
    mov ax, 0
    mov ds, ax

    LEA si, arr1
    push si
    push size
    push direction
    push rotations

    call RotateArray

    mov ax, 0x4C00
    int 0x21

RotateArray:
    push bp
    mov bp, sp

    mov si, [bp + 10]
    mov cx, [bp + 8]
    mov dx, [bp + 6]
    mov bx, [bp + 4]

    xor dx, dx
    mov ax, bx
    div cx
    mov bx, dx

    cmp dx, 0
    jz RotateLeft
    jmp RotateRight

RotateLeft:
    mov dx, cx
    RotateLeftLoop:
        mov ax, [si]
        mov di, si
        add di, 2

        mov cx, dx
    RotateLeftShiftLoop:
        mov bx, [di]
        mov [si], bx
        add si, 2
        add di, 2
        loop RotateLeftShiftLoop

        mov [si], ax
        mov si, [bp + 10]
        dec bx
        jnz RotateLeftLoop
    jmp Done

RotateRight:
    mov dx, cx
    RotateRightLoop:
        mov di, si
        shl cx, 1           ; CX = CX * 2
        sub cx, 2           ; CX = CX - 2
        add di, cx          ; DI = SI + CX
        mov ax, [di]
        mov cx, dx

    RotateRightShiftLoop:
        std
        mov bx, [di]
        mov [di + 2], bx
        sub di, 2
        loop RotateRightShiftLoop
        cld

        mov [si], ax
        mov si, [bp + 10]
        dec bx
        jnz RotateRightLoop
    jmp Done

Done:
    pop bp
    ret 8
