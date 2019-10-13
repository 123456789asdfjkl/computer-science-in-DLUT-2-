.model tiny
.stack
.data
	string1 db 'input:','$'
	string2 db 'desecret:','$'
	desecret db 81
	db 0
	db 81 dup(0)
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
	int 10h
	int 21h

	mov bx,offset buffer
	mov cx,0
	count:
	cmp byte ptr ds:[bx],0
	je finish
	inc cx
	inc bx
	jmp count
	finish:
		dec cx
			
	mov si,offset buffer
	mov di,offset desecret
	again:	mov al,[si]
			inc al
			mov  [di],al
			inc si
			inc di
			dec cx
			jnz again

	mov [di],'$'
	MOV	DL,0AH			;Êä³ö»»ÐÐ
	MOV	AH,02H
	INT	21H
	mov dx,offset string2
	mov ah,09h
	int 21h
	mov dx,offset desecret+2
	mov ah,09h
	int 21h
	mov ah,4ch
	int 21h
.exit 0
end