[org 0x0100]

jmp start
message: db 'My name is Faiq'
db 0
change: db 'name'
db 0

strlen:
    push bp
    mov bp, sp
    push es
    push cx
    push di

    les di, [bp+4]
    mov cx, 0xffff
    xor al, al

    cld

count:

    cmp byte [di], 0x00
    je ter
    inc di
    loop count
   
ter: 
    mov ax, 0xffff
    sub ax, cx

    pop di
    pop cx
    pop es  
    pop bp
    ret 2


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

printstr:
    push bp
    mov bp, sp
    push es
    push ax
    push cx
    push si
    push di

    mov ax, message
    push ax
    call strlen               ; Calculate the length of the message
    mov cx, ax                ; Length of the message
    mov ax, 0xb800            ; Video memory segment
    mov es, ax
    
    mov si, message           ; Point to the message
    xor di, di                ; Start at the beginning of video memory
    mov ah, 0x07              ; Set default attribute (white on black)

   
    call find_substring
    mov bx, ax      
    dec bx          

    cld
nextchar:
    lodsb                    
    cmp di, bx               
    je Check      

    mov ah, 0x07
    stosw                     
    loop nextchar
    jmp pops

Check:
    sub cx, 4
    push cx
    mov cx, 4  

red: 
    
    mov ah, 0x47   
           
    stosw   
    lodsb              
    loop red

    pop cx
    loop nextchar

pops:
    pop di
    pop si
    pop cx
    pop ax
    pop es
    pop bp
    ret




find_substring:
    push bp
    mov bp, sp
    push si
    push di
    push cx

    mov si, message     
    mov di, change           
    mov cx, 0xffff
    xor ax, ax    
            
find:
    mov al, [di]              
    cmp al, [si]           
    jne none

    add si, 1
    add di, 1
    cmp byte [di], 0          
    je match_found

    loop find
    jmp end_find            

none:
    inc si
    mov di, change        
    loop find

match_found:
    sub si, message         
    mov ax, si

end_find:
    pop cx
    pop di
    pop si
    pop bp
    ret



start:
    call clrscr               ; Clear the screen
    call printstr             ; Display the message

    mov ax, 0x4c00            ; Exit program
    int 0x21

