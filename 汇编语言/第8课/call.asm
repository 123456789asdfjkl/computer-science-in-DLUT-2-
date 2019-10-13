.model tiny   		; 1 .model 存储模式伪指令
.code			; 2 .code 段定义伪指令
.startup			; 3 .程序开发伪指令
   mov al,0fh	;提供参数AL
	call htoasc	;调用子程序
.exit 0			 ; 7 .exit 程序结束伪指令

htoasc proc
and al,0fh	;只取al的低4位
	or al,30h	;al高4位变成3
	cmp al,39h	;是0～9，还是0Ah～0Fh
	jbe htoend
	add al,7	;是0Ah～0Fh，加上7
htoend:ret
htoasc endp

string db  'Hello,World!',0dh,0ah,'$' ; 8. 定义字符串
end         			 ; 汇编结束
