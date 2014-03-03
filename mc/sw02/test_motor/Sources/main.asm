;--------------------------------------------------------------------
;          HSLU T&A Hochschule Luzern Technik+Architektur            
;--------------------------------------------------------------------
;
; \brief         Template for HCS08 Assembler
; \file
; \author        J.Wassner/C.Jost/L.Kressebuch
; \date          10.10.2012
;
; \b Language:   Assembler \n\n
; \b Target:     JM60 Testboard V1.1 \n
;
; \par Description:
;
; $Id: main.asm 485 2013-09-22 06:02:55Z zajost $
;--------------------------------------------------------------------
                include 'derivative.inc'
                

; Global definierte Symbole sind von aussen sichtbar.
;--------------------------------------------------------------------
                GLOBAL      _Startup    ; Start Hauptprogramm
                GLOBAL      main
                GLOBAL      dummy       ; Dummy Interrupt Service Routine

; EQUATIONS
;--------------------------------------------------------------------
StackSize:      EQU     $60             ; Equation for the stack size
pi:             EQU     31416           ; Example for a constant value

; STACK, VARIABLEN (Datenspeicher) und KONSTANTEN (Festwertspeicher) 
;--------------------------------------------------------------------
DATEN_STACK:    SECTION
TofStack:       DS      StackSize-1     ; definiton of "Top of Stack"
BofStack:       DS      1               ; definition of "Bottom of Stack"

DATEN:          SECTION
Variable1:      DS      1               ; Example of a 1 Byte Variable
Array1:         DS      $20             ; Example of an Array of $20 Bytes

KONSTANTEN:     SECTION
Maske1:         DC.B    %00000001
Parameter1:     DC.B    $3A             ; DC mit Punkt-> Coloring geht nicht!
Parameter2:     DC.W    57100
Reserve_Par:    DS      16              ; nur leerer Bereich reservieren!
STRING1:        DC.B    10,"Hello",$0D

; Programmstart (Initialisierungen)
;--------------------------------------------------------------------
PROGRAMM:       SECTION                 ; Code Segment
_Startup:                               ; Resetvektor zeigt hierhin
Stackinit:      LDHX    #(BofStack+1)
                TXS                     ; TXS dekrementiert, deshalb oben +1     
                LDA     #$00
                STA     SOPT1           ; Disable Watchdog

; Start des Benutzer-Codes
;--------------------------------------------------------------------
main:       
				BCLR		0, PTGDD	; Pins for Joystick as input with Pull-Ups enabled
				BCLR		1, PTGDD
				BCLR		2, PTGDD
				LDA			PTGPE
				ORA			#$07
				STA			PTGPE
				
				BCLR		3, PTGDD	; Mode Switch

				BSET		4, PTDDD	; Pins for Motor control
				BSET		5, PTDDD
				BSET		6, PTDDD
				BSET		7, PTDDD
				BSET		4, PTFDD	; Pins for PWM Motor control
				BSET		5, PTFDD
				
				BCLR		4, PTDD		; Stop Motor
				BCLR		5, PTDD
				BCLR		6, PTDD
				BCLR		7, PTDD
				BCLR		4, PTFD
				BCLR		5, PTFD
				
				BSET		2, PTDDD	; Rear LEDs on
				BSET		2, PTDD

				BSET		1, PTFDD	; Front left red LED on
				BCLR		1, PTFD
				
				BSET		4, PTCDD	; Front left green LED on
				BCLR		4, PTCD
				
				BSET		0, PTFDD	; Front left blue LED on
				BCLR		0, PTFD
				
				BSET		2, PTFDD	; Front right red LED on
				BCLR		2, PTFD
				
				BSET		6, PTCDD	; Front right green LED on
				BCLR	 	6, PTCD
				
				BSET		7, PTEDD	; Front right blue LED on
				BCLR		7, PTED
				
				BSET		2, PTCDD	; White LED on bottom side on
				BSET		2, PTCD

Joystick:		LDA			PTGD		; Read Joystick
				AND			#$07
				CMP			#$04		; Case Up
				BEQ			Up
				CMP			#$06		; Case Down
				BEQ			Down
				CMP			#$03		; Case Right
				BEQ			Right
				CMP			#$05		; Case Left
				BEQ			Left
				CMP			#$02		; Case Push
				BEQ			Push

				LDA			PTGD		; Default If Mode Switch not set stop motors
				AND			#$08
				CMP			#$00
				BEQ			Stopjmp
								
				JMP			Joystick	; Repeat for ever


EndLoop:        BRA     *               ; Endlos-Loop (=Programmende falls weiter oben Loop vergessen wurde)
                
Stopjmp:		JMP			Stop

Up:				BCLR		2, PTDD		; Rear LEDs off
				BCLR		1, PTFD		; Front left red LED off
				BCLR		4, PTCD		; Front left green LED off
				BCLR		0, PTFD		; Front left blue LED off
				BCLR		2, PTFD		; Front right red LED off
				BCLR		6, PTCD		; Front right green LED off
				BCLR		7, PTED		; Front right blue LED off
				BCLR		2, PTCD		; White LED on bottom side off

				BCLR		4, PTDD		; Drive forward
				BSET		5, PTDD
				BSET		6, PTDD
				BCLR		7, PTDD

				JMP			Joystick

Down:			BSET		2, PTDD		; Rear LEDs off
				BSET		1, PTFD		; Front left red LED off
				BSET		4, PTCD		; Front left green LED off
				BSET		0, PTFD		; Front left blue LED off
				BSET		2, PTFD		; Front right red LED off
				BSET		6, PTCD		; Front right green LED off
				BSET		7, PTED		; Front right blue LED off
				BCLR		2, PTCD		; White LED on bottom side off

				BSET		4, PTDD		; Drive backward 
				BCLR		5, PTDD
				BCLR		6, PTDD
				BSET		7, PTDD

				JMP			Joystick


Right:			BCLR		2, PTDD		; Rear LEDs off
				BSET		1, PTFD		; Front left red LED off
				BSET		4, PTCD		; Front left green LED off
				BSET		0, PTFD		; Front left blue LED off
				BCLR		2, PTFD		; Front right red LED off
				BSET		6, PTCD		; Front right green LED off
				BSET		7, PTED		; Front right blue LED off
				BCLR		2, PTCD		; White LED on bottom side off

				BCLR		4, PTDD		; Turn right
				BCLR		5, PTDD
				BSET		6, PTDD
				BCLR		7, PTDD

				JMP			Joystick


Left: 			BCLR		2, PTDD		; Rear LEDs off
				BCLR		1, PTFD		; Front left red LED off
				BSET		4, PTCD		; Front left green LED off
				BSET		0, PTFD		; Front left blue LED off
				BSET		2, PTFD		; Front right red LED off
				BSET		6, PTCD		; Front right green LED off
				BSET		7, PTED		; Front right blue LED off
				BCLR		2, PTCD		; White LED on bottom side off

				BCLR		4, PTDD		; Turn left
				BSET		5, PTDD
				BCLR		6, PTDD
				BCLR		7, PTDD

				JMP			Joystick


Push:			BCLR		2, PTDD		; Rear LEDs off
				BSET		1, PTFD		; Front left red LED off
				BSET		4, PTCD		; Front left green LED off
				BSET		0, PTFD		; Front left blue LED off
				BSET		2, PTFD		; Front right red LED off
				BSET		6, PTCD		; Front right green LED off
				BSET		7, PTED		; Front right blue LED off
				BCLR		2, PTCD		; White LED on bottom side off

				BSET		4, PTDD		; Rotate right
				BCLR		5, PTDD
				BSET		6, PTDD
				BCLR		7, PTDD

				JMP			Joystick

Stop:			BCLR		4, PTDD		; Stop Motor
				BCLR		5, PTDD
				BCLR		6, PTDD
				BCLR		7, PTDD
				BCLR		4, PTFD
				BCLR		5, PTFD

				JMP			Joystick

;--------------------------------------------------------------------
; dummy - Alle nicht benutzten Interruptvektoren werden hierher
;         geleitet damit kein Absturz passiert, wenn ein unerwarteter
;         Interrupt auftritt. (z.B. loss of lock vom ICG)
;--------------------------------------------------------------------
dummy:          BGND
                BRA     dummy
