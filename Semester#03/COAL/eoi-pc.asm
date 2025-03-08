[org 0x0100]
start:
    mov al, 0x20            
    mov dx, 0x20              
    out dx, al                

    mov dx, msg              
    mov ah, 09h               
    int 21h                   
    
    mov ah, 4Ch               
    int 21h

msg db 'EOI command sent to PIC successfully.$' 
