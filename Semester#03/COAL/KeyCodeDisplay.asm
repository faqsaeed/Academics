[org 0x0100]

jmp start
msg db "The ASCII code of the entered key is: $"

print_decimal:
    pusha                   ; Save registers
    mov cx, 10              ; Base 10
    xor dx, dx              ; Clear DX
    mov bx, ax              ; Copy value into BX

    mov si, 0               ; Index for storing digits

store_digits:
    xor dx, dx              ; Clear DX for division
    div cx                  ; AX / 10, remainder in DX, quotient in AX
    add dl, '0'             ; Convert to ASCII
    push dx                 ; Store digit on stack
    inc si                  ; Increment digit count
    test ax, ax             ; If AX == 0, stop
    jnz store_digits

print_digits:
    pop dx                  ; Retrieve last stored digit
    call print_char         ; Print it
    dec si                  ; Decrease count
    jnz print_digits        ; If there are more digits, continue

    popa                    ; Restore registers
    ret

print_char:
    mov ah, 02h             
    int 21h
    ret

start:
    mov ah, 00h             ; Wait for keypress
    int 16h
    mov bl, al              ; Store ASCII value

    mov ah, 09h             ; Print message
    mov dx, msg
    int 21h

    mov ax, bx              ; Load ASCII value for conversion
    call print_decimal      ; Convert and print

    mov ah, 4Ch             ; Exit program
    int 21h
