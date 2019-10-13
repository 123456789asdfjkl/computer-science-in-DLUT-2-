.model tiny
.code
.startup
	mov dx,offset buffer
	mov ah,0ah
	int 21h
   .exit 0
buffer	db 81 ;定义缓冲区
;第1个字节填入可能输入的最大字符数
	db 0	;存放实际输入的字符数
	db 81 dup(0)	;存放输入的字符串
end