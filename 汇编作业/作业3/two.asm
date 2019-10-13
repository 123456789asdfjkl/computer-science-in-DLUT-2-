.model tiny
.stack
.data
	point1 db 19h,03h; ;五个顶点 
	point2 db 10h,06h;
	point3 db 10h,0ch; 
	point4 db 22h,06h; 
	point5 db 22h,12h; 
	point db ?,?;
	ratio1 db 01h;	;直线斜率
	ratio2 db 03h;	;直线斜率 
	ratio3 db 02h;	;划线比例 
.code
.startup
	mov ah,00h
	mov al,0dh
	int 10h
	mov ah,15
	int 10h
	mov ah,0
	int 10h
 	mov dl,point1[0];	point1 到 point3 的直线
	mov dh,point1[1]; 
line1:	cmp dl,point3[0];
	jb line_2;
	call show; 
	dec dl;
	add dh,ratio1; 
	jmp line1;

line_2:      mov dl,point1[0];    point1 到 point4 的直线
	mov dh,point1[1]; 
line2:	cmp dl,point4[0];
	jnbe line_3; 
	call show;
	inc dl;
	add dh,ratio1;
	jmp line2;

line_3:      mov dl,point2[0];    point2 到 point5 的直线
	mov dh,point2[1]; 
line3:	cmp dl,point5[0];
	jnbe line_4; 
	call show; 
	add dl,ratio3; 
	jmp line3;

line_4:      mov dl,point2[0];    point2 到 point4 的直线
	mov dh,point2[1];
line4:	cmp dl,point4[0];
	jnbe line_5; 
	call show; 
	inc dh;
	add dl,ratio2;
	jmp line4;

line_5:	mov dl,point3[0]; 
	mov dh,point3[1];
line5:	cmp dl,point5[0];
	jnbe done; 
	call show; 
	dec dh;
	add dl,ratio2; 
	jmp line5;


show proc	;显示* 
	push dx;
	mov ah,0bh
	mov bh,00h
	mov bl,09h
	int 10h
	mov al,2ah; 
	mov ah,02h; 
	int  10h; 
	mov ah,02h; 
	mov dl,al;
	 int 21h;
	pop dx; 
	ret;
show	endp;


done:	mov al,02h; 
	mov  dl,16h;  
	mov dh,0dh;
	int  10h; 
	mov al,02h; 
	mov dl,00h;
	mov dh,20h;
	int 10h;
	int 21h
.exit 0; 
end