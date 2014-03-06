/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         C Template for the MC Car
 * \file
 * \author        Christian Jost, christian.jost@hslu.ch
 * \date          04.10.2012
 *
 * \b Language:   Ansi-C \n\n
 * \b Target:     MC-Car  \n
 *
 * \par Description:
 *
 * $Id: main.c 485 2013-09-22 06:02:55Z zajost $
 *--------------------------------------------------------------------
 */
#include "platform.h" /* include peripheral declarations */



/**
 * main program
 */  
void main(void) 
{
    EnableInterrupts;       // Interrupts aktivieren
    
    for(;;) 
    {   
      __RESET_WATCHDOG();  /* feeds the dog */
      asm {
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
						BEQ			Upjmp
						CMP			#$06		; Case Down
						BEQ			Downjmp
						CMP			#$03		; Case Right
						BEQ			Rightjmp
						CMP			#$05		; Case Left
						BEQ			Leftjmp
						CMP			#$02		; Case Push
						BEQ			Pushjmp

						LDA			PTGD		; Default If Mode Switch not set stop motors
						AND			#$08
						CMP			#$00
						BEQ			Stopjmp

						Joystickend:	NOP						; Placeholder for any further instruction performed after processing Joystick

										JMP			Joystick	; Repeat for ever

						Upjmp:			JSR			Up			; Labels to extend maximal jump distance of branch instructions
										JMP			Joystickend
						Downjmp:		JSR			Down
										JMP			Joystickend
						Rightjmp:		JSR			Right
										JMP			Joystickend
						Leftjmp:		JSR			Left
										JMP			Joystickend
						Pushjmp:		JSR			Push
										JMP			Joystickend
						Stopjmp:		JSR			Stop
										JMP			Joystickend


      }
    }
    
  /* please make sure that you never leave main */
}
