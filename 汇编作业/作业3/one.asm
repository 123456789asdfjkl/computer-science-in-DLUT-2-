.model tiny
.stack
.data
string1 db 'Name:changjunlin',0dh,0ah,'$'
string2 db 'Number:201785085',0dh,0ah,'$'
string3 db 'Phone:18340896933',0dh,0ah,'$'
string4 db 'Email:chang13579@mail.dlut.edu.cn',0dh,0ah,'$'
.code
.startup
	mov ah,00h
	mov al,01h
	int 10h
	mov dx,offset string1
	mov ah,09h
	mov bl,09h
	mov cx,10h
	int 10h
	int 21h
	mov dx,offset string2
	mov ah,09h
	mov bl,04h
	mov cx,10h
	int 10h
	int 21h
	mov dx,offset string3
	mov ah,09h
	mov bl,02h
	mov cx,11h
	int 10h
	int 21h
	mov dx,offset string4
	mov ah,09h
	mov bl,0dh
	mov cx,21h 
	int 10h
	int 21h
.exit 0
end