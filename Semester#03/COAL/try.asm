[org 0x0100]

jmp start

message: db 'Hello_World'
length: dw 11

clrscr:
	push es	
	push ax
	push di

	mov ax, 0xb800
	mov es, ax
	mov di, 0

nextloc: 
	mov word [es:di], 0x0720
	add di, 2
	jne nextloc

	pop di
	pop ax
	pop es
	ret

printscr:
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di

	mov ax, 0xb800
	mov es, ax
	mov di, 0
	mov si, [bp + 6]
	mov cx, [bp + 4]
	mov ah, 0x07

nextchar:
	
	mov al, [si]
	mov [es:di], ax
	mov di, 2
	mov si, 1
	loop nextchar

	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 4

start:
	call clrscr
	mov ax, message
	push ax
	push word [length]
	call printscr

	mov ax, 0x4c00
	int 0x21
