.model tiny
.code
.startup
    mov ah,02
    mov dl,'?'
	int 21h
   .exit 0
end