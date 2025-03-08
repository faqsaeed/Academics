[org 0x0100]

jmp Start

count : dw 0

rand: dw 0
randnum: dw 0

;notice how everything is six times, it is bcz there will be 6 charcters on screen at max ;)

var1: db 0x4E ;current value
pos1: dw 60 ; current position
flag1: dw 0 ; No of lines
tick1: dw 8 ; to vary the speed

var2: db 0x49
pos2: dw 70
flag2: dw 0
tick2: dw 8

var3: db 0x47
pos3: dw 80
flag3: dw 0
tick3: dw 7

var4: db 0x45
pos4: dw 90
flag4: dw 0
tick4: dw 4

var5: db 0x52
pos5: dw 100
flag5: dw 0
tick5: dw 5

var6: db 0x51
pos6: dw 110
flag6: dw 0
tick6: dw 15

lives: dw 11
points : dw 0

msg1: db 'Points:'
msg2: db 'Lives:'
msg3: db 'GAME OVER!!'
msg4: db 'Game Developed by Faiq Saeed'
msg5: db 'Your Score'
box: dw 3920
kbflag: dw 0
oldkb: dd 0

;;;;;;;;;;
RandG:  ; j to generate a random number
	push bp
 	mov bp, sp
   	pusha
   	cmp word [rand], 0
   	jne Next

  	MOV AH, 00h
  	INT 1AH
  	inc word [rand]
  	mov [randnum], dx
  	jmp Next1

Next:
  	mov ax, 25173
  	mul word  [randnum]
  	add ax, 13849
  	mov [randnum], ax

Next1:
	xor dx, dx
	mov ax, [randnum]
	mov cx, [bp+4]
 	inc cx
 	div cx
 
 	mov [bp+6], dx
 	popa
 	pop bp
 	ret 2

;;;;;;;;;;
Terminate:
	push ax

	call Clr

	mov bx, 0
	mov ax, 0xb800
	mov es, ax
	mov di, 1990
	mov cx, 11
	mov ah, 0x07

GameOver:
;printing, gae over in the center lol
	mov al, [cs : msg3 + bx]
	mov [es : di], ax
	add di, 2
	inc bx
	loop GameOver

	mov bx, 0
	mov ax, 0xb800
	mov es, ax
	mov di, 2150
	mov cx, 10
	mov ah, 0x07

mand:
;printing, gae over in the center lol
	mov al, [cs : msg5 + bx]
	mov [es : di], ax
	add di, 2
	inc bx
	loop mand:
	mov [es : di], [Score]

	mov bx, 0
	mov ax, 0xb800
	mov es, ax
	mov di, 2150
	mov cx, 28
	mov ah, 0x07

Credits:
;printing, gae over in the center lol
	mov al, [cs : msg4 + bx]
	mov [es : di], ax
	add di, 2
	inc bx
	loop Credits:

; restoring the ols isrs
	xor ax, ax
	mov es, ax
	mov ax, [cs : oldkb]
	mov bx, [cs : oldkb + 2]
	cli
	mov [es : 9 * 4], ax
	mov [es : 9 * 4 + 2], bx
	mov [es : 8 * 4], ax
	mov [es : 8 * 4 + 2], bx
	sti
;The END
	mov ax, 0x4c00
	int 21h
	pop ax
	ret

;;;;;;;;;;
Clr:
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

;;;;;;;;;;
Background:
	push es
	push ax
	push cx
	push dx
	push di
	push si

	mov ax, 0xb800
	mov es, ax
	mov di, 40
	mov dx, 26

Again1:
	mov cx, 40

Again2:
	mov word [es : di], 0x3320 ; background
	add di, 2
	loop Again2

	add di, 80
	dec dx
	cmp dx, 0
	jne Again1

	pop si
	pop di
	pop dx
	pop cx
	pop ax
	pop es
	ret

;;;;;;;;;;
Points:
	push bp
	mov bp, sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di

	mov bx, 0
	mov ax, 0xb800
	mov es, ax
	mov di, 608 ; starting position of "points"
	mov cx, 7
	mov ah, 0x07

Points1:
;printing messge
	mov al, [cs : msg1 + bx]
	mov [es : di], ax
	add di, 2
	inc bx
	loop Points1

;checking collision
	mov ax, [bp + 4]
	sub ax, 160 ;80*2
	cmp ax, [cs : box]
	jne NoPoint ; if no collision, ending the subroutine

	inc word [cs : points]

	mov word [es : 624], 0x0720
	mov word [es : 626], 0x0720
	mov word [es : 628], 0x0720

	mov bx, 10
	mov cx, 0
	mov ax, [cs : points]
	mov di, 624

NextDigit: ;printing number ka code from book
	mov dx, 0
	div bx
	add dl, 0x30
	push dx
	inc cx
	cmp ax, 0
	jnz NextDigit

NextPos:
	pop dx
	mov dh, 0x07
	mov [es : di], dx
	add di, 2
	loop NextPos
	jmp lol
	;inc word [cs : lives]

NoPoint:
	dec word [cs : lives]
lol:
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop es
	pop bp
	ret 2

;;;;;;;;;;
Lives:
	push bp
	mov bp, sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di

	mov bx, 0
	mov ax, 0xb800
	mov es, ax
	mov di, 486 ; starting position of prnting "lives:"
	mov cx, 6
	mov ah, 0x07

Lives1:
; printing the message
	mov al, [cs : msg2 + bx]
	mov [es : di], ax
	add di, 2
	inc bx
	loop Lives1

;checking for collision
	mov ax, [bp + 4]
	sub ax, 160 ;80*2
	cmp ax, [cs : box]
	je NoLive ; if no collision, go to ten end of subroutine

	mov word [es : 500], 0x0720
	mov word [es : 502], 0x0720
	mov word [es : 504], 0x0720

	mov bx, 10
	mov cx, 0
	mov ax, [cs : lives]
	mov di, 500

NextDigit1:
	mov dx, 0
	div bx
	add dl, 0x30
	push dx
	inc cx
	cmp ax, 0
	jnz NextDigit1

NextPos1:
	pop dx
	mov dh, 0x07
	mov [es : di], dx
	add di, 2
	loop NextPos1

NoLive:
	cmp word  [cs: lives], 0
	jle Terminate
	pop di
	pop dx
	pop cx
	pop bx
	pop ax
	pop es
	pop bp
	ret

;;;;;;;;;;
Print:
	push bp
	mov bp, sp
	push ax
	push bx
	push dx
	push es
	push di

	mov ax, 0xb800
	mov es, ax
;to vary the speed of the falling charcter 
	mov ax, [cs : count]
	mov bx, [bp + 12]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Print1 ;only works if the reminder == 0


;code below, changes the position of charcter to the ne position
	mov di, [cs : pos1]
	mov word [es : di], 0x3020
	add word [cs : pos1], 160
	mov ax, [cs : var1]
	mov ah, 0x30
	mov di, [cs : pos1]
	mov word [es : di], ax
	inc word [cs : flag1]
	
Print1:
	mov ax, [cs : count]
	mov bx, [bp + 10]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Print2

	mov di, [cs : pos2]
	mov word [es : di], 0x3020
	add word [cs : pos2], 160
	mov ax, [cs : var2]
	mov ah, 0x30
	mov di, [cs : pos2]
	mov word [es : di], ax
	inc word [cs : flag2]

Print2:
	mov ax, [cs : count]
	mov bx, [bp + 8]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Print3

	mov di, [cs : pos3]
	mov word [es : di], 0x3020
	add word [cs : pos3], 160
	mov ax, [cs : var3]
	mov ah, 0x30
	mov di, [cs : pos3]
	mov word [es : di], ax
	inc word [cs : flag3]

Print3:
	mov ax, [cs : count]
	mov bx, [bp + 6]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Print4

	mov di, [cs : pos4]
	mov word [es : di], 0x3020
	add word [cs : pos4], 160
	mov ax, [cs : var4]
	mov ah, 0x30
	mov di, [cs : pos4]
	mov word [es : di], ax
	inc word [cs : flag4]

Print4:
	mov ax, [cs : count]
	mov bx, [bp + 4]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Finish

	mov di, [cs : pos5]
	mov word [es : di], 0x3020
	add word [cs : pos5], 160
	mov ax, [cs : var5]
	mov ah, 0x30
	mov di, [cs : pos5]
	mov word [es : di], ax
	inc word [cs : flag5]

Print5:
	mov ax, [cs : count]
	mov bx, [bp + 14]
	mov dx, 0
	div bx
	cmp dl, 0
	jnz Finish

	mov di, [cs : pos6]
	mov word [es : di], 0x3020
	add word [cs : pos6], 160
	mov ax, [cs : var6]
	mov ah, 0x30
	mov di, [cs : pos6]
	mov word [es : di], ax
	inc word [cs : flag6]

Finish:
	pop di
	pop es
	pop dx
	pop bx
	pop ax
	pop bp
	ret 12

;;;;;;;;;;
Box:
	push bp
	mov bp, sp
	push es
	push ax
	push di

	mov ax, 0xb800
	mov es, ax
;if box goes out of the bound(ehich it will not), the following 4 lines will force it to return it to the center
	cmp word [cs : box], 3882
	jl Centre
	cmp word [cs : box], 3956
	ja Centre

	mov di, [bp + 4]
	mov word [es : di], 0x11DC

	cmp word [cs : kbflag], 1
	jne Right

;move left
	mov word [es : di], 0x3020 ; clearing the previous posiion
	sub word [cs : box], 2
	mov di, [cs : box] ; new position
	mov word [es : di], 0x11DC ; moving box
	jmp Return

Right:
	cmp word [cs : kbflag], 2
	jne Return

;move right
	mov word [es : di], 0x3020
	add word [cs : box], 2
	mov di, [cs : box]
	mov word [es : di], 0x11DC
	jmp Return

Centre:
	mov di, [cs : box]
	mov word [es : di], 0x3020
	mov word [es : 3920], 0x11DC
	mov word [cs : box], 3920

Return:
	mov word [cs : kbflag], 0
	pop di
	pop ax
	pop es
	pop bp
	ret 2

;;;;;;;;;
Kbisr:
	push ax
;takes input
	in al, 0x60
;check for left arrow, if trye set kb flag as 1
	cmp al, 0x4B
	jne NextCmp

	mov word [cs : kbflag], 1
	je Exit

NextCmp:
; check for right arrow and set, if true set kb flad as 2
	cmp al, 0x4D
	jne NoMatch

	mov word [cs : kbflag], 2
	je Exit

; if no match, go back to orgisna keyboard handler
NoMatch:
	pop ax
	jmp far [cs : oldkb]

Exit:
;sending End of Interupt signal
	mov al, 0x20
	out 0x20, al
	pop ax
	iret

;;;;;;;;;;
Timer:
	push ax

	push word [cs : box]
	call Box

	cmp word [cs: lives], 11
	jge Terminate

	cmp word [cs : lives], 0x0000 ;check for lives, if equals 0, terminates and shows the game over screen
	jne CheckPos0

	call Terminate

CheckPos0: 
	cmp word [cs : flag1], 25 ; check if it hits the bottom
	jne CheckPos ; skips checking for collisoion if it is not at bottom

	push word [cs : pos1] ;if it hits the ground, it will check for collision in "Points" and "Lives"
	call Points
	call Lives
; rpeats the process for all 6 characters on screen
CheckPos:
	cmp word [cs : flag2], 25 
	jne CheckPos1

	push word [cs : pos2]
	call Points
	call Lives

CheckPos1:
	cmp word [cs : flag3], 25
	jne CheckPos2

	push word [cs : pos3]
	call Points
	call Lives

CheckPos2:
	cmp word [cs : flag4], 25
	jne CheckPos3

	push word [cs : pos4]
	call Points
	call Lives

CheckPos3:
	cmp word [cs : flag5], 25
	jne Reset1

	push word [cs : pos5]
	call Points
	call Lives

Reset1:
	cmp word [cs : flag1], 25
	jne Reset2 ;if the var1 hits the bottom we need new character to fell down the screen

; this is to check the random variable genrated is between A and Z, inclucive
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41 ; 0x41 == A
	jl Reset1
	cmp dl, 0x5A ; 0x 5A = Z
	ja Reset1
	mov [cs : var1], dx

Loop1:
; this is to generate a random number between 15 and 25
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop1
	cmp dl, 25
	ja Loop1
	;multiply the obtained number with 4 
	mov al, 4
	mul dl
;the obtained value is te new position of the charaxcter
	mov word [cs : pos1], ax
	mov word [cs : flag1], 0

Reset2:
	cmp word [cs : flag2], 25
	jne Reset3

	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41
	jl Reset2
	cmp dl, 0x5A
	ja Reset2

	mov [cs : var2], dx

Loop2:
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop2
	cmp dl, 25
	ja Loop2
	
	mov al, 4
	mul dl
	mov word [cs : pos2], ax
	mov word [cs : flag2], 0

Reset3:
	cmp word [cs : flag3], 25
	jne Reset4

	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41
	jl Reset3
	cmp dl, 0x5A
	ja Reset3

	mov [cs : var3], dx

Loop3:
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop3
	cmp dl, 25
	ja Loop3
	
	mov al, 4
	mul dl
	mov word [cs : pos3], ax
	mov word [cs : flag3], 0


Reset4:
	cmp word [cs : flag4], 25
	jne Reset5

	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41
	jl Reset4
	cmp dl, 0x5A
	ja Reset4

	mov [cs : var4], dx

Loop4:
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop4
	cmp dl, 25
	ja Loop4
	
	mov al, 4
	mul dl
	mov word [cs : pos4], ax
	mov word [cs : flag4], 0

Reset5:
	cmp word [cs : flag5], 25
	jne Reset6

	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41
	jl Reset5
	cmp dl, 0x5A
	ja Reset5

	mov [cs : var5], dx

Loop5:
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop5
	cmp dl, 25
	ja Loop5
	
	mov al, 4
	mul dl
	mov word [cs : pos5], ax
	mov word [cs : flag5], 0

Reset6:
	cmp word [cs : flag5], 25
	jne Doit

	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 0x41
	jl Reset6
	cmp dl, 0x5A
	ja Reset6

	mov [cs : var6], dx

Loop6:
	sub sp, 2
	push 79
	call RandG
	pop dx
	cmp dl, 15
	jl Loop6
	cmp dl, 25
	ja Loop6
	
	mov al, 4
	mul dl
	mov word [cs : pos6], ax
	mov word [cs : flag6], 0

Doit:
	inc word [cs : count]
	push word [cs : tick6]
	push word [cs : tick1]
	push word [cs : tick2]
	push word [cs : tick3]
	push word [cs : tick4]
	push word [cs : tick5]
	call Print

End:
;EOI call
	mov al, 0x20
	out 0x20, al

	pop ax
	iret

;;;;;;;;;;
Start:
;function calls
	call Clr
	call Background
	call Points
	call Lives

;initialising variables
	mov byte [cs : var1], 'F'
	mov byte [cs : var2], 'A';0x41
	mov byte [cs : var3], 'I';0x49
	mov byte [cs : var4], 'Q';0x51
	mov byte [cs : var5], 'S';0x55
    mov byte [cs : var6], 'D';0x4D


; saving original keyboard handlers 
	xor ax, ax
	mov es, ax
	mov ax, [es : 9 * 4]
	mov [oldkb], ax
	mov ax, [ es : 9 * 4 + 2]
	mov [oldkb + 2], ax

;hooking customised interupt handlers
	cli
	mov word [es : 9 * 4], Kbisr
	mov [es : 9 * 4 + 2], cs
	mov word [es : 8 * 4], Timer
	mov [es : 8 * 4 + 2], cs
	sti

; setting up the memory space for game
	mov dx, Start
	add dx, 15
	mov cl, 4
	shr dx, cl
	mov ax, 0x3100
	int 0x12
