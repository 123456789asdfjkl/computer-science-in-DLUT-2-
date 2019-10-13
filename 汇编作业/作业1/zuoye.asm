.model tiny   		; 1 .model 存储模式伪指令
.code			; 2 .code 段定义伪指令
.startup			; 3 .程序开发伪指令
           mov     dx,offset string   ; 4.指定字符串的偏移
            mov    ah,9                    ; 5.
            int       21h                     ; 6.利用功能调用显示信息   
            mov ah,2
            mov dl,24h
            int 21h
.exit 0			 ; 7 .exit 程序结束伪指令
string db  'Name: changjunlin',0dh,0ah,'Number: 201785085',0dh,0ah,'Phone: 18340896933',0dh,0ah,'Email:chang13579@mail.dlut.edu.cn',0dh,0ah,'$' ; 8. 定义字符串
end         			 ; 汇编结束
