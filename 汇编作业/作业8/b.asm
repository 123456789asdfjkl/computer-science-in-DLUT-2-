.model tiny
.stack
.data
	string1 db 'please input:',0dh,0ah,'$'
	fName db 'd:\data.txt',0h
	buffer db 81
	db 0
	db 81 dup(0)
.code
.startup
	mov dx,offset string1
	mov ah,09h
	int 21h
	mov dx,offset buffer
	mov ah,0ah
	int 21h

	mov dx,offset fName ; 创建文件
	mov cx,0
	mov ah,3ch
	int 21h 

	mov ah,3dh          ;打开文件
    mov al,03
    mov dx,offset fName
    int 21h
    push ax             ;保存文件句柄

    mov bx,ax
    mov cx, 12
    lea dx,buffer+2
    mov ah,40h
    int 21h             ;写文件

    pop bx              ;弹出文件句柄

    mov ah,3eh          ;关闭文件
    int 21h

.exit 0
end