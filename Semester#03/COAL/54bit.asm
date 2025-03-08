[org 0x0100] 
 jmp start 
multiplicand: dq 0xABCDD4E1
multiplier: dd 0xAB5C32 
result: dd 0, 0

start: 
    mov cx, 32
    mov dx, [multiplier] 
checkbit: 
    shr dx, 1 
    jnc skip 
    mov ax, [multiplicand] 
    add [result], ax 
    mov ax, [multiplicand+2] 
    adc [result+2], ax 
skip: 
    shl word [multiplicand], 1 
    rcl word [multiplicand+2], 1
    dec cx
    jnz checkbit 

 mov ax, 0x4c00 
 int 0x21 
