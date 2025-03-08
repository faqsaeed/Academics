[org 0x0100]

mov ax, 10
mov bx, 20
mov cx, 30

mov [temp1], ax
mov [temp2], bx
mov [temp3], cx

mov ax, [temp3]
mov bx, [temp1]
mov cx, [temp2]

mov ax, [temp2]
mov bx, [temp1]
mov cx, [temp3]

mov ax, 0x4c00
int 0x21

temp1: dw 0
temp2: dw 0
temp3: dw 0

