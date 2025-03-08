[org 0x0100]  ; Code starts at offset 0x100 (COM file)

section .text
start:
    ; Set video mode 13h (320x200, 256 colors)
    mov ax, 0x13
    int 0x10

    ; Define the top-left and bottom-right coordinates
    mov cx, 10   ; X1 (Top-left corner)
    mov dx, 2    ; Y1 (Top-left corner)
    mov si, 60   ; X2 (Bottom-right corner)
    mov di, 20   ; Y2 (Bottom-right corner)

    ; Define color: Red (color index 4)
    mov bh, 4

    ; Call to draw the rectangle
    call DrawRectangle

    ; Wait for a key press before exiting
    mov ah, 0
    int 0x16

    ; Restore text mode (03h)
    mov ax, 0x03
    int 0x10

    ; Terminate the program
    mov ax, 0x4C00
    int 0x21

; Procedure to draw a rectangle on the screen
DrawRectangle:
    ; Draw the top horizontal line
    mov bx, cx
DrawTop:
    mov ax, dx  ; Set Y1
    call PlotPixel
    inc bx
    cmp bx, si
    jle DrawTop

    ; Draw the bottom horizontal line
    mov bx, cx
    mov ax, di  ; Set Y2
DrawBottom:
    call PlotPixel
    inc bx
    cmp bx, si
    jle DrawBottom

    ; Draw the left vertical line
    mov bx, dx
    mov ax, cx  ; Set X1
DrawLeft:
    call PlotPixel
    inc bx
    cmp bx, di
    jle DrawLeft

    ; Draw the right vertical line
    mov bx, dx
    mov ax, si  ; Set X2
DrawRight:
    call PlotPixel
    inc bx
    cmp bx, di
    jle DrawRight

    ret

; Function to plot a pixel at (X, Y) using the color in BH
PlotPixel:
    ; Calculate pixel position: y * 320 + x
    mov es, 0xA000   ; Set video memory segment
    mov di, ax       ; y-coordinate in DI
    mov ax, 320      ; Multiply y by 320 (width of the screen)
    mul di
    add di, bx       ; Add x-coordinate to DI
    mov al, bh       ; Set color (Red in this case)
    stosb            ; Store AL in memory (plot the pixel)
    ret
