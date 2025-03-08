section .data
    filename db "output.txt", 0    ; File name with null terminator
    filehandle dw ?                ; File handle will be stored here after creating/opening the file
    message db "Hello, this is a test message.$" ; Message to write into the file

section .text
    org 0x100                      ; Set origin for .COM program

start:
    ; Step 1: Create a new file
    mov ah, 3Ch                    ; Function 3Ch - Create file
    mov cx, 0                      ; File attribute (0 = normal)
    mov dx, filename               ; DS:DX points to filename
    int 21h
    jc error                       ; Jump if error (carry flag set)
    mov [filehandle], ax           ; Store file handle

    ; Step 2: Write a message to the file
    mov ah, 40h                    ; Function 40h - Write to file
    mov bx, [filehandle]           ; Load file handle
    mov dx, message                ; DS:DX points to the message
    mov cx, 27                     ; Length of message to write (in bytes)
    int 21h
    jc error                       ; Jump if error

    ; Step 3: Close the file
    mov ah, 3Eh                    ; Function 3Eh - Close file
    mov bx, [filehandle]           ; Load file handle
    int 21h
    jc error                       ; Jump if error

    ; Optional Step 4: Reopen the file to display its contents
    mov ah, 3Dh                    ; Function 3Dh - Open file
    mov al, 00h                    ; Read-only mode
    mov dx, filename               ; DS:DX points to filename
    int 21h
    jc error                       ; Jump if error
    mov [filehandle], ax           ; Store new file handle

    ; Read and display file contents
    mov ah, 3Fh                    ; Function 3Fh - Read from file
    mov bx, [filehandle]           ; Load file handle
    mov dx, message                ; DS:DX points to buffer to read into
    mov cx, 27                     ; Number of bytes to read
    int 21h
    jc error                       ; Jump if error

    ; Display the read message
    mov ah, 09h                    ; Function 09h - Display string
    mov dx, message                ; DS:DX points to the message buffer
    int 21h

    ; Close the file after reading
    mov ah, 3Eh                    ; Function 3Eh - Close file
    mov bx, [filehandle]           ; Load file handle
    int 21h

    ; End the program
    mov ah, 4Ch                    ; Function 4Ch - Terminate program
    int 21h

error:
    ; Error handling (optional)
    mov ah, 09h
    mov dx, errorMsg
    int 21h
    mov ah, 4Ch                    ; Exit program on error
    int 21h

section .data
    errorMsg db "An error occurred.$"
