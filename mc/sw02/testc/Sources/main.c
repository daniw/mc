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
    }
    
  /* please make sure that you never leave main */
}
