[org 0x0100]
jmp start


oldisr: dd 0
tick_counter : dw 0

custom_int08_handler:
    inc word [tick_counter]     
    pushf                       
    
    iret                        

start:
    xor ax, ax
    mov es, ax
    mov ax, [es:8*4]
    mov [oldisr], ax
    mov ax, [es:8*4+2]
    mov [oldisr+2], ax
    cli
    mov word [es:8*4], custom_int08_handler
 ; store offset at n*4
   mov [es:8*4+2], cs
    sti

   
    mov dx, msg_installed
    mov ah, 09h                      
    int 21h


    mov ax, [oldisr]
    mov bx, [oldisr+2]
    cli
    mov [es:8*4], ax
    mov [es:8*4+2], bx
    sti

    mov dx, msg_uninstalled
    mov ah, 09h                      
    int 21h

    
    mov ah, 4Ch                       
    int 21h

msg_installed db 'Custom INT 08h handler installed.$'
msg_uninstalled db 'Custom INT 08h handler uninstalled.$'
