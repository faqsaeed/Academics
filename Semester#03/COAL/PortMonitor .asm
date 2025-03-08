start:
    mov dx, 0x20               
    in al, dx             

    mov ah, al                

    mov dl, al
    shr dl, 4                 
    call display_hex_digit

    mov dl, ah
    and dl, 0Fh                
    call display_hex_digit


    mov ah, 4Ch              
    int 21h

display_hex_digit:
    add dl, '0'          
    cmp dl, '9'
    jbe display          

    add dl, 7              

display:
    mov ah, 02h             
    int 21h
    ret
