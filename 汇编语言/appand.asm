.model tiny;
.code;
.startup;

          mov ah,3dh          ;打开文件
          mov al,03
          mov dx,offset fName
          int 21h
          push ax        ;保存文件句柄
        
         mov bx,ax

         mov ah,42h      ;移动指针

          mov al,2
          mov dx,0  ;        文件末尾
          mov cx,0
          int 21H

          mov cx, 13
          mov dx,offset fBuffer
          mov ah,40h
          int 21h             ;写文件

          pop bx              ;弹出文件句柄
    
          mov ah,3eh          ;关闭文件
          int 21h
          
          .exit 0;           ;退出程序

fName db 'd:\asm.txt',0h
fBuffer db 'Added message!';
end;