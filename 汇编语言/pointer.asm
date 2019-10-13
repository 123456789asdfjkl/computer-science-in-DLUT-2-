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

         mov al,1        ;读取第六个字节
         mov dx,6
         mov cx,0
     

;         mov al,2
;         mov dx,0ffffh  ;倒数第一个字节
;         mov cx,0ffffh


;          mov al,2
;          mov dx,0h     ;得到文件大小
;          mov cx,0h

          int 21H

          mov cx, 1
          mov dx,offset fBuffer
          mov ah,3fh
          int 21h             ;读文件

          pop bx              ;弹出文件句柄
    
          mov ah,3eh          ;关闭文件
          int 21h
          
          .exit 0;           ;退出程序

fName db 'd:\asm.txt',0h
fBuffer db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;
end;