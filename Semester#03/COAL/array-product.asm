[org 0x0100]

mov bx, 0

.array: 
	mov ax, 0              
	mov cx, [Array1 + bx]  
	cmp cx, 0               
	je .update              

.multiply:
	add ax, [Array1 + bx]  
	sub cx, 1               
	jnz .multiply           

.update:
	mov [Array2 + bx], ax 
	add bx, 2               
	cmp bx, 20              
	jnz .array              

	mov ax, 0x4c00          
	int 0x21                

Array1: dw 1, 5, 7, 4, 9, 2, 1, 0, 12, 16  
Array2: dw 0, 0, 0, 0, 0, 0, 0, 0, 0, 0    
;answer = 9, 19, 31, 10, 51, 4, 1, 0, 90, 0100
