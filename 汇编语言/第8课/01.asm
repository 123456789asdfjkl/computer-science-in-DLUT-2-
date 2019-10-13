.model tiny   		; 1 .model 存储模式伪指令
.code			; 2 .code 段定义伪指令
.startup			; 3 .程序开发伪指令
getkey:	
    mov ah,01h	;功能号：ah←01h
	int 21h	;功能调用
	cmp al,'Y'	;处理出口参数al
	je yeskey	;是“Y”
	cmp al,'N'
	je nokey	;是“N”
	jne getkey
yeskey:  mov dx,offset str1
         jmp show
nokey:	  mov dx,offset str2
show:    mov ah,9
         int 21h

.exit 0			 ; 7 .exit 程序结束伪指令
str1 db  'Pressed Y',0dh,0ah,'$' ; 8. 定义字符串
str2 db  'Pressed N',0dh,0ah,'$' ; 8. 定义字符串
end         			 ; 汇编结束
