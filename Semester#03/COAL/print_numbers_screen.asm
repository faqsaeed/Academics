[org 0x0100]
jmp Start

array1: dw 6, 7, 3, 9, 100, 5, 1, 50
len: dw 8


printnum:
    push bp
    mov bp, sp
    push es
    push ax
    push bx
    push cx
    push dx
    push di

    mov ax, 0xb800            
    mov es, ax
    mov ax, [bp + 6]          
    mov bx, 10
    mov cx, 0                 ; Clear counter for digit stack
    
nextdigit:
    mov dx, 0                 ; Clear DX for division
    div bx                    ; AX / 10, remainder in DX
    add dl, 0x30              ; Convert digit to ASCII
    push dx                   ; Push the digit on the stack
    inc cx                    ; Count how many digits we have
    
    cmp ax, 0                 ; If AX is 0, we're done
    jnz nextdigit

    mov di, [bp + 4]          ; DI points to the current cursor position

nextpos:
    pop dx                    ; Pop digits from the stack
    mov dh, 0x07              ; Set attribute (white text)
    mov [es:di], dx           ; Write the character to video memory
    add di, 2                 ; Move to the next position on the screen
    loop nextpos              ; Repeat until all digits are printed

             ; Save the updated DI (cursor position) back

    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    pop es
    pop bp
    ret 4                     ; Return, clean up 4 bytes from the stack

; Clear the screen
clrscr:
    push es
    push ax
    push cx
    push di

    mov ax, 0xb800            ; Set video segment to 0xb800
    mov es, ax
    xor di, di                ; Start at the top-left corner (0x0000)
    mov ax, 0x0720            ; Blank space with attribute 07 (white on black)
    mov cx, 2000              ; Clear the whole screen (80x25 = 2000 characters)

    cld
    rep stosw                

    pop di
    pop cx
    pop ax
    pop es
    ret

; Main routine to print multiple numbers
printNumbers:
    push bp
    mov bp, sp

    mov cx, [bp + 4]            ; Total number of numbers to print (in CX)
    mov si, bp                ; SI for stack pointer tracking
    mov di, 0    
	add si, 4             ; si is now pointng at the number of print i.e. si + 2 is the last number to be printed


printLoop:
    
	
	mov bx, cx
	add bx, cx                
    mov ax, [si + bx] ; si + cx * 2 = desired number to print yeahh!!!!!!!!
    push ax    
	push di           
    call printnum         
	dec cx
	add di, 160  

    cmp cx, 0 
    jnz printLoop         

    pop bp
    ret 2                

Start:
    call clrscr               

  
    push 134                 
    push 189                 
    push 156   
	push 2048               
    push 4                

    call printNumbers         ; Call printNumbers function

    ; Program termination
    mov ax, 0x4c00
    int 21h
