[org 0x0100]
jmp start

array1: dw 6, 7, 3, 9, 100, 5, 1, 50, 22
lenArray1: dw 9 

BubbleSort:

	push bp 
 	mov bp, sp	
	sub sp, 2
	push ax
	push bx
	push cx
	push si; 

	mov bx, [bp + 6]
	mov cx, [bp + 4]
	dec cx
	shl cx, 1

mainloop:

	mov si, 0
	mov word [bp - 2], 0
	
innerloop:
	mov ax, [bx + si ] 
	cmp ax, [bx + si + 2]
	jle noswap

	xchg ax, [bx + si + 2]
	mov [bx + si], ax
	mov word [bp - 2], 1

noswap:

	add si, 2
	cmp si, cx
	jne innerloop

	cmp word [bp - 2], 1
	je mainloop

	pop si
	pop cx
	pop bx
	pop ax
	mov sp, bp 
 	pop bp 
 	ret 4

statOfArray:

    push bp 
    mov bp , sp

    push word [bp + 4]
    push word [bp + 6]        
    call BubbleSort    ; Sort the array

    mov si, [bp + 4]     
    mov ax, [si]       ; First element is the minimum
    mov [bp + 8], ax            ; Push min on stack

    mov cx, [bp + 6]     ; Load array length
    dec cx
    shl cx, 1          ; Multiply by 2 
    add si, cx         ; Point to last element
    mov ax, [si]       ; Last element is the maximum
    mov [bp + 10], ax            ; Push max on stack

    mov cx, [bp + 6]     ; Get array length
    shr cx, 1          ; Divide length by 2 to get middle index
    shl cx, 1          ; Multiply index by 2 (each element is 2 bytes)
    mov si, [bp + 4]     ; Load array pointer
    add si, cx         
    mov ax, [si]       
    mov [bp + 12], ax             

    pop bp 
    ret 4

start:

    mov ax, 0
    push ax
    push ax
    push ax    
    push word [lenArray1]    
    mov ax,  array1        
    push ax

    call statOfArray
    
    pop ax
    pop bx
    pop cx

    mov ax, 0x4c00
    int 21h

