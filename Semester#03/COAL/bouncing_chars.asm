
[org 0x0100]


; es:0 is start, es:158 is end
; 0x741 = A , 0x742 = B
    jmp start


clrscr:
    push es
    push ax
    push cx
    push di
    
    mov ax, 0xb800  
    mov es, ax
    xor di, di       
    mov ax, 0x0720   
    mov cx, 2000     
    cld             
    rep stosw        
    
    pop di
    pop cx
    pop ax
    pop es
    ret


sleep:
    push cx
    mov cx, 0xFFFF   
delay:
    loop delay       
    pop cx
    ret


printing:
    push ax
    push bx
    push cx
    push di
    push si
    push es
    
    mov ax, 0xb800   
    
    mov es, ax
    mov di, 0         ; Left position start (A)
    mov si, 158       ; Right position start (B)
    mov ax, -2        ; Previous left position for clearing
    mov cx, 160       ; Previous right position for clearing


prin:
    mov word [es:si], 0x0942    
    mov word [es:di], 0x0941   
    mov bx, ax
    mov word [es:bx], 0x0720  
    mov bx, cx
    mov word [es:bx], 0x0720   
    
    add di, 2        
    sub si, 2         
    add ax, 2       
    sub cx, 2         
    
    call sleep        
    
    cmp di, 78       
    jle prin
    cmp si, 78       
    jge prin


reverse:
    mov word [es:di], 0x0720    
    mov word [es:si], 0x0720   
    
    sub di, 2
    add si, 2        
    
    mov word [es:di], 0x0841   
    mov word [es:si], 0x0842   
    
    call sleep    
    
    cmp di, 0         ; Check if left char back to start
    jg reverse
    cmp si, 158       ; Check if right char back to start
    jl reverse
    

    mov word [es:0], 0x0741     
    mov word [es:158], 0x0742 
    
    pop es
    pop si
    pop di
    pop cx
    pop bx
    pop ax
    
    call printing     
    ret


start:
    call clrscr    
    call printing    
    
    mov ax, 0x4c00   
    int 0x21
