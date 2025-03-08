[org 0x0100]

mov ax, 0
mov bx, fib
mov cx, 8
add bx, 4

code:
	mov ax, 0
	add ax, [bx - 2]
	add ax, [bx - 4]
	mov [bx], ax
	add bx, 2
	sub cx, 1
	jnz code

mov ax, 0x4c00
int 0x21

fib: dw 0, 1, 0, 0, 0, 0, 0, 0, 0, 0
