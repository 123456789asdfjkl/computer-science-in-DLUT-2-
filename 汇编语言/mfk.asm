.model tiny
.code
.startup

      START:  
              PUSH     CS
              POP      DS
              PUSH      DS
;GET INT 1C ADRESS 
              MOV       AL,1CH      ;定时器控制的软中断
              MOV       AH,35H      ;取中断向量
              INT       21H         ;DOS调用
              MOV       SEGMENT1C,ES
              MOV       OFF1C,BX
;SET INT 1C ADRESS 
              MOV       DX,OFFSET INT1C
              PUSH CS
              POP DS
              MOV       AL,1CH      ;定时器控制的软中断
              MOV       AH,25H      ;设置中断向量
              INT       21H         ;DOS调用
              POP       DS

   GAMEOVER:
              MOV       AH,00H
              MOV       AL,03H
              INT       10H
  SELECTSPEED:
              MOV       AH,09H
              MOV       DX,OFFSET STARTMSG1
              INT       21H
              MOV       DX,OFFSET STARTMSG2
              INT       21H
              MOV       DX,OFFSET STARTMSG3
              INT       21H
              MOV       DX,OFFSET STARTMSG4
              INT       21H
              MOV       DX,OFFSET STARTMSG5
              INT       21H
              MOV       AH,08H
              INT       21H
              SUB       AL,'0'
              MOV       CL,AL
              AND       AL,3
              CMP       AL,CL
              JNE       SELECTSPEED
              INC       AL
              INC       CL
              MUL       CL
              CMP       AL,1H
              JE        EXIT
              MOV       SPEED,AL

;SET GRAPHICS 
              MOV       AH,00H
              MOV       AL,12H
              INT       10H
              MOV       AH,0BH
              MOV       BH,01
              MOV       BL,00H
              INT       10H
;START  GAME 
              CALL      INITGAME
              CALL      BEGIN
              CALL      DELAY
              MOV       TIM,0H
      LOOP1:  STI
              MOV       AL,TIM
              CMP       AL,SPEED
              JG        TIME
              MOV       AH,1
              INT       16H
              JZ        LOOP1
              MOV       AH,0
              INT       16H
              CMP       AL,1BH
              JZ        EXIT
              CMP       AL,'a'
              JZ        KA
              CMP       AL,'s'
              JZ        KS
              CMP       AL,'d'
              JZ        KD
              CMP       AL,09H
              JNZ       TIME
       KTAB:  CALL      DELAY
              CALL      DOWN
              CMP       CON,1
              JNE       KTAB
              CALL      BEGIN
              JMP       LOOP1
         KA:  CALL      LEFT
              JMP       LOOP1
         KS:  CALL      ROTATE
              JMP       LOOP1
         KD:  CALL      RIGHT
              JMP       LOOP1
       TIME:  MOV       TIM,0H
              CALL      DOWN
              CMP       CON,0
              JE        LOOP1
              CALL      BEGIN
              JMP       LOOP1

       EXIT:                        ;SET GRAPHICS
              MOV       AX,0003H
              INT       10H

              MOV       DX,OFFSET ENDMSG
              MOV       AH,09H
              INT       21H
;SET INT 1C ADRESS 
              MOV       DX,OFF1C
              MOV       AX,SEGMENT1C
              MOV       DS,AX
              MOV       AL,1CH
              MOV       AH,25H
              INT       21H
              MOV       AX,4C00H
              INT       21H

       INT1C  PROC
              STI
              PUSH      AX
              PUSH      DX
              
              PUSH CS
              POP DS
              
              INC       TIM
              POP       DX
              POP       AX
              IRET
       INT1C  ENDP

       DELAY  PROC      NEAR
              PUSH      CX
              MOV       CX,00FFH
     LOOP20:  LOOP      LOOP20
              POP       CX
              RET
       DELAY  ENDP

      ROTATE  PROC      NEAR
              MOV       SI,OFFSET PAD
              MOV       AL,NOW
              MOV       AH,0H
              MOV       CL,32
              MUL       CL
              ADD       SI,AX
              MOV       AL,DIRE
              INC       AL
              AND       AL,03H
              MOV       AH,0H
              MOV       CL,8
              MUL       CL
              ADD       SI,AX
              MOV       DI,OFFSET P2
              MOV       CX,04H
              CLD
     LOOP12:  PUSH      CX
              LODSW
              MOV       CL,XR
              SHR       AX,CL
              MOV       CL,XL
              SHL       AX,CL
              STOSW
              POP       CX
              LOOP      LOOP12

              CALL      CHECK
              CMP       AL,0H
              JNE       SKIP10
              MOV       BX,0000H
              CALL      DISPPAD

              CALL      COPY21
              INC       DIRE
              AND       DIRE,3H
              MOV       BH,00H
              MOV       BL,NCOLOR
              CALL      DISPPAD
     SKIP10:  RET
      ROTATE  ENDP

       RIGHT  PROC      NEAR
              CALL      COPY12
              MOV       SI,OFFSET P2
              MOV       CX,04H
      LOOP7:  MOV       AX,[SI]
              SHR       AX,1
              MOV       [SI],AX
              INC       SI
              INC       SI
              LOOP      LOOP7
              CALL      CHECK
              CMP       AL,0H
              JNE       SKIP6
              MOV       BX,0000H
              CALL      DISPPAD
              CALL      COPY21

              CMP       XL,0
              JE        SKIP7
              DEC       XL
              DEC       XR
      SKIP7:  INC       XR

              MOV       BH,00H
              MOV       BL,NCOLOR
              CALL      DISPPAD

      SKIP6:  RET
       RIGHT  ENDP

        LEFT  PROC      NEAR
              CALL      COPY12
              MOV       SI,OFFSET P2
              MOV       CX,04H
     LOOP10:  MOV       AX,[SI]
              SHL       AX,1
              MOV       [SI],AX
              INC       SI
              INC       SI
              LOOP      LOOP10
              CALL      CHECK
              CMP       AL,0H
              JNE       SKIP8
              MOV       BX,0000H
              CALL      DISPPAD
              CALL      COPY21

              CMP       XR,0
              JE        SKIP9
              DEC       XR
              DEC       XL
      SKIP9:  INC       XL

              MOV       BH,00H
              MOV       BL,NCOLOR
              CALL      DISPPAD

      SKIP8:  RET
        LEFT  ENDP

        DOWN  PROC      NEAR
              CALL      COPY12
              INC       TY
              CALL      CHECK
              CMP       AL,0H
              JNE       SKIP5
              MOV       BX,0000H
              CALL      DISPPAD
              CALL      COPY21
              MOV       BH,00H
              MOV       BL,NCOLOR
              CALL      DISPPAD
              MOV       CON,00H
              RET
      SKIP5:  CALL      PUT
              MOV       CON,01H
              RET
        DOWN  ENDP

         PUT  PROC      NEAR
              MOV       BH,0H
              MOV       BL,0H
              CALL      DISPPAD
              MOV       BH,0H
              MOV       BL,01011001B
              CALL      DISPPAD

              INC       SCORE[4]
              MOV       DV,01H
              MOV       AH,0H
              MOV       AL,Y
              ADD       AL,Y
              MOV       SI,OFFSET BOARD
              ADD       SI,AX
              MOV       DI,00H
              MOV       CX,04H
              CLD
     LOOP15:  LODSW
              OR        AX,P1[DI]
              MOV       [SI-2],AX
              INC       DI
              INC       DI
              LOOP      LOOP15

              MOV       SI,OFFSET BOARD
              ADD       SI,23*2
              MOV       DI,SI
              MOV       CX,20
              MOV       BH,00H
         
              MOV       FLG,00H
              STD
     LOOP13:  LODSW
              CMP       AX,0FFFFH
              JNE       SKIP12
              MOV       FLG,0FFH
              MOV       AL,DV
              SAL       AL,1
              MOV       DV,AL
              JMP       LOOP13
     SKIP12:  STOSW
;PUSH AX 
              CMP       FLG,0H
              JE        SKIP70
              PUSH      CX
              MOV       DH,CL
              ADD       DH,03H

              MOV       DL,0AH
              MOV       BX,0000H
              MOV       BP,OFFSET PADMSG
              MOV       CX,20
              PUSH      AX
              MOV       AX,1300H
              INT       10H
              POP       AX
              MOV       CL,03H
              SHL       AX,CL
              MOV       CX,0AH
              MOV       DL,08H
     LOOP14:  INC       DL
              INC       DL
              MOV       BL,0H
              SHL       AX,1
              JNC       SKIP11
              MOV       BL,01011001B
     SKIP11:  CALL      DISPCELL
              LOOP      LOOP14
              POP       CX
     SKIP70:  LOOP      LOOP13
         
              MOV       AL,DV
              SAR       AL,1
              ADD       SCORE[3],AL
              MOV       CX,05H
              MOV       SI,04H
     LOOP16:  CMP       SCORE[SI],'9'
              JNG       SKIP13
              INC       SCORE[SI-1]
              SUB       SCORE[SI],0AH
     SKIP13:  DEC       SI
              LOOP      LOOP16
              RET
         PUT  ENDP

   DISPSCORE  PROC      NEAR
              PUSH CS
              POP ES
              MOV       BP,OFFSET SCORE
              MOV       CX,05H
              MOV       DX,0635H
              MOV       BH,0H
              MOV       AL,0H
              MOV       BL,00110100B
              MOV       AH,13H
              INT       10H
              RET
   DISPSCORE  ENDP

    DISPNEXT  PROC      NEAR
              PUSH CS
              POP ES
              MOV       BP,OFFSET TMPMSG
              MOV       DI,BP
              MOV       SI,OFFSET PAD
              MOV       AL,NXT
              MOV       AH,0
              MOV       BL,32
              MUL       BL
              ADD       SI,AX

              CLD
              MOV       CX,04H
      LOOP8:  PUSH      CX
              LODSW
              MOV       CL,06H
              SHL       AX,CL
              MOV       CX,04H
      LOOP9:  MOV       BL,20H
              SHL       AX,1
              JNC       SKIP2
              MOV       BL,219
      SKIP2:  MOV       [DI],BL
              INC       DI
              MOV       [DI],BL
              INC       DI
              LOOP      LOOP9
              MOV       DX,0C30H
              POP       CX
              SUB       DH,CL
              PUSH      CX
              MOV       CX,08H
              MOV       BH,0H
              PUSH      SI
              MOV       AH,0H
              MOV       AL,NXT
              MOV       SI,AX
              MOV       BL,COLOR[SI]
              POP       SI
              MOV       AX,1300H
              INT       10H
              POP       CX
              MOV       DI,BP
              LOOP      LOOP8
              RET
    DISPNEXT  ENDP

      COPY21  PROC      NEAR
              CLD
              MOV       SI,OFFSET P2
              MOV       DI,OFFSET P1
              MOV       CX,08
              REP       MOVSB
              MOV       CL,TY
              MOV       Y,CL
              RET
      COPY21  ENDP

      COPY12  PROC      NEAR
              CLD
              MOV       SI,OFFSET P1
              MOV       DI,OFFSET P2
              MOV       CX,08
              REP       MOVSB
              MOV       CL,Y
              MOV       TY,CL
              RET
      COPY12  ENDP

       BEGIN  PROC      NEAR
              MOV       AL,NXT
              MOV       NOW,AL
              CALL      RANDOM
              CALL      DISPSCORE
              CALL      DISPNEXT
;FORMAT VALUE 
              MOV       DIRE,0
              MOV       Y,4
              MOV       TY,4
              MOV       XR,0
              MOV       XL,0
              MOV       AH,0
              MOV       AL,NOW
              MOV       SI,AX
              MOV       CL,COLOR[SI]
              MOV       NCOLOR,CL
              MOV       DI,OFFSET P2
              MOV       SI,OFFSET PAD
              MOV       BL,32
              MUL       BL
              ADD       SI,AX

              MOV       CX,08
              CLD
              REP       MOVSB

              CALL      COPY21
              MOV       BH,0H
              MOV       BL,NCOLOR
              CALL      DISPPAD
              CALL      CHECK
              CMP       AL,0
              JE        SKIP1
              MOV       DL,07H
              MOV       AH,02H
              INT       21H
              MOV       AH,08H
              INT       21H
              JMP       GAMEOVER
      SKIP1:  CALL      DELAY
              MOV       TIM,0H
              RET
       BEGIN  ENDP

       CHECK  PROC      NEAR        ;RETURN  AL=0/F  0:OK  F:NO
              MOV       AH,0H
              MOV       AL,TY
              ADD       AL,TY
              MOV       SI,OFFSET BOARD
              ADD       SI,AX
              MOV       DI,00H
              MOV       CX,04H
              CLD
      LOOP6:  LODSW
              AND       AX,P2[DI]
              JNZ       SKIP4
              INC       DI
              INC       DI
              LOOP      LOOP6
              MOV       AL,00H
              RET
      SKIP4:  MOV       AL,0FH
              RET
       CHECK  ENDP

     DISPPAD  PROC      NEAR        ;BX BH=PAGE BL=COLOR
              MOV       SI,OFFSET P1
              MOV       CX,04H
              MOV       DL,08H
              MOV       DH,Y
              ADD       DH,04H
              PUSH      DX
              CLD
      LOOP2:  LODSW
              POP       DX
              PUSH      DX
              SUB       DH,CL
              PUSH      CX
              MOV       CL,03H
              SHL       AX,CL
              MOV       CX,0AH
      LOOP3:  INC       DL
              INC       DL
              SHL       AX,1
              JNC       SKIP3
              CALL      DISPCELL
      SKIP3:  LOOP      LOOP3
              POP       CX
              LOOP      LOOP2
              POP       DX
              RET
     DISPPAD  ENDP

    DISPCELL  PROC      NEAR        ;DH=ROW DL=COL BH=PAGE BL=COLOR
              PUSH      AX
              PUSH      BX
              PUSH      CX
              PUSH      DX
              PUSH      DI
              PUSH      SI
              MOV       BP,OFFSET PADMSG
              MOV       CX,02H
              MOV       AX,1300H
              INT       10H
              CMP       BL,0H
              JE        SKIP20
;CALC ROW 
              MOV       AH,0H
              MOV       AL,DH
              MOV       CL,16
              MUL       CL
              MOV       SI,AX
;CALC COL 
              MOV       AH,0H
              MOV       AL,DL
              MOV       CL,8
              MUL       CL
              MOV       DI,AX
;DRAW 
              MOV       AX,0C00H
              MOV       DX,SI
              ADD       DX,15
              MOV       CX,16
     LOOP21:  ADD       CX,DI
              DEC       CX
              INT       10H
              INC       CX
              SUB       CX,DI
              LOOP      LOOP21

              MOV       DX,SI
              MOV       CX,15
              ADD       DI,15
     LOOP22:  PUSH      CX
              MOV       CX,DI
              INT       10H
              INC       DX
              POP       CX
              LOOP      LOOP22

              SUB       DI,2
              DEC       DX
              MOV       CX,13
     LOOP23:  PUSH      CX
              DEC       DX
              MOV       CX,DI
              INT       10H
              SUB       CX,12
              MOV       AL,07H
              INT       10H
              MOV       AL,00H
              POP       CX
              LOOP      LOOP23

              MOV       AX,0C07H
              MOV       DX,SI
              ADD       DX,1
              MOV       CX,12
              SUB       DI,12
     LOOP24:  ADD       CX,DI
              INT       10H
              SUB       CX,DI
              LOOP      LOOP24

     SKIP20:  POP       SI
              POP       DI
              POP       DX
              POP       CX
              POP       BX
              POP       AX
              RET
    DISPCELL  ENDP

         CLS  PROC      NEAR
              MOV       CX,0
              MOV       DH,24
              MOV       DL,79
              MOV       BH,0
              MOV       AX,600H
              INT       10H
              RET
         CLS  ENDP

      RANDOM  PROC      NEAR
      LOOP5:  IN        AX,40H
              INC       AL
              AND       AL,07H
              CMP       AL,07H
              JE        LOOP5
              MOV       NXT,AL
              RET
      RANDOM  ENDP

    INITGAME  PROC      NEAR
              CALL      CLS
;DRAW   TEXTFRAME 
              PUSH      CS
              POP       ES
              MOV       CX,15
              MOV       BP,OFFSET SCOREMSG1
              MOV       DX,052AH
     LOOP72:  PUSH      CX
              MOV       CX,21
              MOV       AL,0H
              MOV       BH,0H
              MOV       BL,01011010B
              MOV       AH,13H
              INT       10H
              ADD       BP,21
              INC       DH
              POP       CX
              LOOP      LOOP72

;DRAW BOARDFRAME 
              MOV       BP,OFFSET PADMSG
              MOV       CX,0024
              MOV       DX,0308H
              MOV       BH,0H
              MOV       AL,0H
              MOV       BL,00110100B
              MOV       AH,13H
              INT       10H
              MOV       DX,1808H
              INT       10H

              MOV       CX,20
              MOV       DX,0308H
      LOOP4:  MOV       SI,CX
              MOV       CX,02
              INC       DH
              INT       10H
              MOV       CX,SI
              LOOP      LOOP4

              MOV       CX,20
              MOV       DX,031EH
     LOOP11:  MOV       SI,CX
              MOV       CX,02
              INC       DH
              INT       10H
              MOV       CX,SI
              LOOP      LOOP11
;FORMAT BOARD 
              CLD
              MOV       DI,OFFSET BOARD
              MOV       CX,24
              MOV       AX,0E007H
              REP       STOSW
;FORMAT SCORE 
              MOV       DI,OFFSET SCORE
              MOV       AL,'0'
              MOV       CX,05H
              REP       STOSB
              CALL      RANDOM
              MOV       AL,NXT
              MOV       NOW,AL
              RET
    INITGAME  ENDP

   SEGMENT1C  DW        0
       OFF1C  DW        0
       BOARD  DW        24 DUP(?),0FFFFH
           Y  DB        ?
          TY  DB        ?
          XR  DB        ?
          XL  DB        ?
         NOW  DB        ?
        DIRE  DB        ?
         NXT  DB        ?
         TIM  DB        0
       SPEED  DB        0
         CON  DB        0
          DV  DB        0
         FLG  DB        0
         PAD  DW        0H,3C0H,0H,0H           ;0
              DW        100H,100H,100H,100H
              DW        0H,3C0H,0H,0H
              DW        100H,100H,100H,100H
              DW        0H,180H,180H,0H         ;1
              DW        0H,180H,180H,0H
              DW        0H,180H,180H,0H
              DW        0H,180H,180H,0H
              DW        0H,380H,200H,0H         ;2
              DW        200H,200H,300H,0H
              DW        0H,80H,380H,0H
              DW        0H,300H,100H,100H
              DW        0H,380H,80H,0H          ;3
              DW        300H,200H,200H,0H
              DW        0H,200H,380H,0H
              DW        100H,100H,300H,0H
              DW        0H,180H,300H,0H         ;4
              DW        100H,180H,80H,0H
              DW        0H,180H,300H,0H
              DW        100H,180H,80H,0H
              DW        0H,300H,180H,0H         ;5
              DW        80H,180H,100H,0H
              DW        0H,300H,180H,0H
              DW        80H,180H,100H,0H
              DW        0H,380H,100H,0H         ;6
              DW        100H,180H,100H,0H
              DW        100H,380H,0H,0H
              DW        100H,300H,100H,0H
          P1  DW        4 DUP(?)
          P2  DW        4 DUP(?)
       COLOR  DB        00001001B,00001010B,00001011B,00001100B,00001101B,00001110B,00000001B
      NCOLOR  DB        ?
       SCORE  DB        5 DUP('0'),'$'
      PADMSG  DB        25 DUP(219)
      TMPMSG  DB        25 DUP(?)
   STARTMSG1  DB        0DH,0AH,'Select speed.',0DH,0AH,'$'
   STARTMSG2  DB        20H,20H,'1. Fast',0DH,0AH,'$'
   STARTMSG3  DB        20H,20H,'2. Middle',0DH,0AH,'$'
   STARTMSG4  DB        20H,20H,'3. Slow',0DH,0AH,'$'
   STARTMSG5  DB        20H,20H,'0. Exit',0DH,0AH,'$'
      ENDMSG  DB        0DH,0AH,'Good Bye!',0DH,0AH,'$'
   SCOREMSG1  DB        201,19 DUP(205),187
   SCOREMSG2  DB        186,'  Score:           ',186
   SCOREMSG3  DB        204,19 DUP(205),185
   SCOREMSG4  DB        186,19 DUP(32),186
   SCOREMSG5  DB        186,19 DUP(32),186
   SCOREMSG6  DB        186,19 DUP(32),186
   SCOREMSG7  DB        186,19 DUP(32),186
   SCOREMSG8  DB        204,19 DUP(205),185
   SCOREMSG9  DB        186,'   Left  : A       ',186
  SCOREMSG10  DB        186,'   Right : D       ',186
  SCOREMSG11  DB        186,'   Rotate: S       ',186
  SCOREMSG12  DB        186,'   Down  : Tab     ',186
  SCOREMSG13  DB        186,'-------------------',186
  SCOREMSG14  DB        186,'   Exit  : Esc     ',186
  SCOREMSG15  DB        200,19 DUP(205),188
END