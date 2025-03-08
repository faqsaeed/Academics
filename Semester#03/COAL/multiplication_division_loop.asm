[org 0x0100]

mov ax, [num]
mov bx, 4
mov cx, 3

l1:	
	add ax, [num]
	sub cx, 1
	jnz l1
mov [mresult], ax

l2:
	add cx, 1
	sub ax, 3
	jnz l2

mov [dresult], cx
mov ax, 0x4c00
int 0x21
num: dw 6
mresult: dw 0
dresult: dw 0

