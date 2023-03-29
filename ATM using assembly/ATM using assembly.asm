include 'emu8086.inc'

ORG 100h
.DATA
card    DW    1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20  
pass    DB    1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,4,3,2,1,0
cmess   DB    'Enter card number:$'
pmess   DB    'Enter password:$'
correct DB    'welcome$'
nf      DB    'wrong email or card number$'
inputc  DW    ?
inputp  DB    ?
element DB    0   
found   DB    0
confirm DB    0 
two     DB    2 
ten     DB    10


.CODE  
MAIN PROC
begin:
        MOV AX,@DATA
        MOV DS,AX

        MOV AH,2
        MOV DL,0AH
        INT 21H    
    
        LEA DX,cmess 
        MOV AH,09H
        INT 21H

        CALL scan_num
        MOV  BX,CX 

        MOV inputc,BX  
  
        MOV AH,2
        MOV DL,0AH
        INT 21H
        
        LEA DX,pmess 
        MOV AH,09H
        INT 21H  

        CALL scan_num
        MOV  BL,CL   
      
        MOV inputp,BL
       
        MOV AH,2
        MOV DL,0AH
        INT 21H 

        MOV CX,20  
        LEA SI,card
        MOV BX,0 
        MOV DX,inputc

the_loop:
        CMP  DX,[SI+BX] 
        JE   F          
        ADD  BX,2
        LOOP the_loop
        JMP  notf
        
       
F:      MOV  AX,BX
        DIV  two
        MOV  BX,AX
        MOV  DL,inputp      
        MOV  found,1 
        LEA  SI,pass 
        CMP  DL,[SI+BX]
        JNE  the_end
        MOV  confirm,1
    
the_end: 
        CMP confirm,1
        JE  corr  
    
notf:   LEA DX,nf 
        MOV AH,09H
        INT 21H 
        JMP begin  
         
corr:   LEA DX,correct 
        MOV AH,09H
        INT 21H    
        
        DEFINE_SCAN_NUM
      
RET