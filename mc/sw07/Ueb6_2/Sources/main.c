/**
 *--------------------------------------------------------------------\n
 *          HSLU T&A Hochschule Luzern Technik+Architektur            \n
 *--------------------------------------------------------------------\n
 *
 * \brief         C Template for the MC Car
 * \file
 * \author        Daniel Winz, Adrian Imboden
 * \date          06.03.2014
 *
 * \b Language:   Ansi-C \n\n
 * \b Target:     MC-Car  \n
 *
 * \par Description:
 *
 * $Id: main.c 485 2014-06-03 21:17:55Z daniw $
 *--------------------------------------------------------------------
 */
#include "platform.h" /* include peripheral declarations */

#define CLOCK 1000000
#define FREQ_LED 2
#define PRESC_MASK 0x07
#define PRESC_VAL (1<<PRESC_MASK)
#define MOD_VALUE ((CLOCK / PRESC_VAL / FREQ_LED) - 1)
#if MOD_VALUE > 0xffff
    #error "Modulo Register out of range -> Check Prescaler and Frequency values"
#endif

#define LED 0x04

void InitTimer(void)
{
    TPM1SC_PS = PRESC_MASK; // Prescaler 128
    TPM1MOD = MOD_VALUE;    // Modulo value according to LED Frequency
    TPM1SC_CLKSx = 2;       // Fixed system clock
    TPM1SC_TOIE = 1;        // Enable Timer Overflow interrupt

}

interrupt void tpm1ofisr(void)
{
	TPM1SC_TOF = 0;
    PTFD ^= LED;
}

/**
 * main program
 */
void main(void)
{
    EnableInterrupts;       // Interrupts aktivieren

    PTFDD = LED;

    InitTimer();

    for(;;)
    {
        __RESET_WATCHDOG();  /* feeds the dog */
    }

  /* please make sure that you never leave main */
}
