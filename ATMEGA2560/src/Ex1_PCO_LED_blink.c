/********************************************************************************
 * Program Title    : Blink LED using ATmega2560 (Bare-Metal C)                 *
 * Author           : Sadan Asampally                                           *
 * Date             : 05 July 2025                                              *
 * Time             : 12:00 PM                                                  *
 * Description      : This program blinks an LED connected to pin PC0 of PORTC  *
 *                    at regular intervals (100ms ON, 100ms OFF).               *
 * Target MCU       : ATmega2560                                                *
 * Clock Frequency  : 16 MHz                                                    *
 *******************************************************************************/

#define F_CPU 16000000UL                // Define CPU clock frequency as 16 MHz for delay calculation

#include <avr/io.h>                     // Include I/O definitions for AVR
#include <util/delay.h>                 // Include delay functions

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // Data Direction Register for PORTC
#define LED_PORT      PORTC             // Data Register for PORTC
#define LED_PIN       PC0               // LED connected to PC0

// -------- Constants --------
#define LED_ON        (1 << LED_PIN)    // Bit mask to turn ON LED
#define LED_OFF      ~(1 << LED_PIN)    // Bit mask to turn OFF LED (used with AND operation)
#define OUTPUT        0xFF              // Set entire port as output

void main(void)                          // Entry point of the program
{
    LED_PORT_DIR = OUTPUT;              // Set all pins of PORTC as output

    while (1)                           // Infinite loop
    {
        LED_PORT |= LED_ON;             // Set PC0 HIGH (turn ON LED)
        _delay_ms(10);                 // Wait for 100 milliseconds

        LED_PORT &= LED_OFF;            // Clear PC0 LOW (turn OFF LED)
        _delay_ms(10);                 // Wait for 100 milliseconds
    }
}
