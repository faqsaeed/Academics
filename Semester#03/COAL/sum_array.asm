[org 0x0100]

mov ax, [num]
add ax, [num + 2]
add ax, [num + 4]
add ax, [num + 6]
add ax, [num + 8]

mov ax, 0x4c00
int 0x21

num: dw 3, 6, 9, 12, 15

