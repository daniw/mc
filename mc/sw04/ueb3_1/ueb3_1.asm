; Maschinencode
$0960 -------- -------- --A60FB7 0BA680B7
$0970 09A6EFB7 C1B70A48 484848B7 08AEFFA6
$0980 FF4E0602 4E06024E 06024E06 025A26F1
$0990 AEFF4BED B6C149B7 C1B70A48 484848B7
$09A0 0820DA-- -------- -------- --------

; Mascheinencode -> Assembler
$0969 A60F   LDA #$0F
$096B B70B   STA $0B
$096D A680   LDA #$80
$096F B709   STA $09
$0971 A6EF   LDA #$EF
$0973 B7C1   STA $C1
$0975 B70A   STA $0A
$0977 48     LSLA
$0978 48     LSLA
$0979 48     LSLA
$097A 48     LSLA
$097B B708   STA $08
$097D AEFF   LDX #$FF
$097F A6FF   LDA #$FF
$0981 4E0602 MOV $06, $02
$0984 4E0602 MOV $06, $02
$0987 4E0602 MOV $06, $02
$098A 4E0602 MOV $06, $02
$098D 5A     DECX
$098E 26F1   BNE $F1  (Relative)
$0990 AEFF   LDX #$FF
$0992 4BED   DBNZA $ED (Decrement A and branch if not zero)
$0994 B6C1   LDA $C1
$0996 49     ROLA
$0997 B7C1   STA $C1
$0999 B70A   STA $0A
$099B 48     LSLA
$099C 48     LSLA
$099D 48     LSLA
$099E 48     LSLA
$099F B708   STA $08
$09A1 20DA   BRA $DA

; Ergänzen von Labels
$0969 A60F   LDA #$0F
$096B B70B   STA PTFDD
$096D A680   LDA #$80
$096F B709   STA PTEDD
$0971 A6EF   LDA #$EF
$0973 B7C1   STA $C1 (Speicherstelle im RAM)
$0975 B70A   STA PTFD
$0977 48     LSLA
$0978 48     LSLA
$0979 48     LSLA
$097A 48     LSLA
$097B B708   STA PTED
OuterLoop:
$097D AEFF   LDX #$FF
$097F A6FF   LDA #$FF
InnerLoop:
$0981 4E0602 MOV PTDD, PTBD
$0984 4E0602 MOV PTDD, PTBD
$0987 4E0602 MOV PTDD, PTBD
$098A 4E0602 MOV PTDD, PTBD
$098D 5A     DECX
$098E 26F1   BNE InnerLoop (relative jump mit -15)
$0990 AEFF   LDX #$FF
$0992 4BED   DBNZA InnerLoop (Decrement A and branch if not zero)
$0994 B6C1   LDA $C1 (Speicherstelle im RAM)
$0996 49     ROLA
$0997 B7C1   STA $C1
$0999 B70A   STA PTFD
$099B 48     LSLA
$099C 48     LSLA
$099D 48     LSLA
$099E 48     LSLA
$099F B708   STA PTED
$09A1 20DA   BRA OuterLoop

; Kommentieren
            LDA #$0F            ; enable LEDs
            STA PTFDD           
            LDA #$80            
            STA PTEDD           
            LDA #$EF            
            STA $C1             ; temp = 0xEF
            STA PTFD            ; switch LEDs off
            LSLA                
            LSLA                
            LSLA                
            LSLA                
            STA PTED            
OuterLoop:                      ; repeat
            LDX #$FF            ;     wait for 1'562'134 cycles
            LDA #$FF            
InnerLoop:                      
            MOV PTDD, PTBD      
            MOV PTDD, PTBD      
            MOV PTDD, PTBD      
            MOV PTDD, PTBD      
            DECX                
            BNE InnerLoop       
            LDX #$FF            
            DBNZA InnerLoop     
            LDA $C1             ;     temp = temp << 1
            ROLA                ; 
            STA $C1             
            STA PTFD            
            LSLA                
            LSLA                
            LSLA                
            LSLA                
            STA PTED            
            BRA OuterLoop       ; forever

=> Lauflicht