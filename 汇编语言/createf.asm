.model tiny;
.code;
.startup;

mov dx,offset fName ; 创建文件
mov cx,0
mov ah,3ch
int 21h        
.exit 0           ;退出程序

fName db 'd:\asm.txt',0h
fBuffer db 'Hello,world!'
end