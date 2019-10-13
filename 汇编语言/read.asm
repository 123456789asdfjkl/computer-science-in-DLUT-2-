.model tiny;
.code;
.startup;

          mov ah,3dh          ;打开文件
          mov al,03
          mov dx,offset fName
          int 21h
          push ax             ;保存文件句柄

          mov bx,ax
          mov cx, 12
          mov dx,offset fBuffer
          mov ah,3fh
          int 21h             ;读文件

          pop bx              ;弹出文件句柄

          mov ah,3eh          ;关闭文件
          int 21h
          
          .exit 0;           ;退出程序

fName db 'd:\data.txt',0h
fBuffer db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
end;