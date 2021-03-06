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

EndLoop:        BRA     *               ; Endlos-Loop (=Programmende falls weiter oben Loop vergessen wurde)
                




;--------------------------------------------------------------------
; dummy - Alle nicht benutzten Interruptvektoren werden hierher
;         geleitet damit kein Absturz passiert, wenn ein unerwarteter
;         Interrupt auftritt. (z.B. loss of lock vom ICG)
;--------------------------------------------------------------------
dummy:          BGND
                BRA     dummy
