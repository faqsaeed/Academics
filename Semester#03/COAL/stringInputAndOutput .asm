[org 0x0100]
jmp start

    buffer db 50            
    db 0                 


start:


   
    mov ah, 0Ah             
    mov dx, buffer          
    int 21h                

   
    mov ah, 09h             
    lea dx, [buffer+2]      
    int 21h               

    ; End program
    mov ah, 4Ch           
    int 21h
