.model tiny;
.code;
.startup;

          mov ah,3dh          ;打开文件
          mov al,02           ;读写
          mov dx,offset fName
          int 21h
          push ax        ;保存文件句柄
        
          mov bx,ax
          mov cx,82
          mov dx,offset fBuffer2
          mov ah,3fh
          int 21h   ;读文件
          push ax ;保存读入的字节数

        ;  mov ah,41
        ;  mov dx
       ;   int 21;删除文件

         mov ah,42h      ;移动指针
         mov al,0
         mov dx,0  ;        文件末尾
         mov cx,0
         int 21H

        
          pop ax ;取得长度
          push ax;
          ;add ax,30 ;ascii码  
          ;lea si,fBuffer
          ;mov cl,al
          ;shr cl,4
          ;add cl,30
         ; mov [si+9],cl
          ;mov ch,al
         ; shl ch,4
         ; shr ch,4
         ; add ch,30
          ;mov [si+10],ch
          ;mov word ptr [si+9],'12'
          mov dx,offset fBuffer 
          mov cx, 11
          mov ah,40h
          int 21h             ;写文件
          
         


          pop ax
          add ax,2
          mov cx, ax
          lea si,offset fBuffer2
          sub si,2
          mov byte ptr [si],0dh
          mov byte ptr [si+1],0ah
          mov dx,si
          mov ah,40h
          int 21h             ;写文件

          

          pop bx              ;弹出文件句柄
    
          mov ah,3eh          ;关闭文件
          int 21h
          
          .exit 0;           ;退出程序

fName db 'd:\myinfo.txt',0h
fBuffer db 'filesize:87';
fBuffer2 db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0;

end;