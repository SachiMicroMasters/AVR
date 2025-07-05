
/*********************************************************************************
 * Program Title   : Blink LED using ATmega2560 (Full Port On/Off)               *
 * Author          : Sadan Asampally                                             *
 * Date            : 05 July 2025                                                *
 * Time            : 12:00 PM                                                    *
 * Description     : This program blinks all LEDs connected to PORTC by          *
 *                   writing 0xFF to turn ON all pins and 0x00 to turn them OFF. *
 *                   Each state lasts for 100ms.                                 *
 * Target MCU      : ATmega2560                                                  *
 * Clock Frequency : 16 MHz                                                      *
 ********************************************************************************/

#define F_CPU 16000000UL                // Define CPU clock frequency as 16 MHz for delay calculation

#include <avr/io.h>                     // Include I/O definitions for AVR
#include <util/delay.h>                 // Include delay functions

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // Data Direction Register for PORTC
#define LED_PORT      PORTC             // Data Register for PORTC

// -------- Constants --------
#define LED_ON         0xFF             // Turn ON all 8 bits of PORTC
#define LED_OFF        0x00             // Turn OFF all 8 bits of PORTC
#define OUTPUT         0xFF             // Set all 8 pins as output

int main(void)                          // Entry point of the program
{
    LED_PORT_DIR = OUTPUT;              // Configure PORTC as output

    while (1)                           // Infinite loop
    {
        LED_PORT = LED_ON;              // Turn ON all LEDs
        _delay_ms(100);                 // Wait 100 milliseconds

        LED_PORT = LED_OFF;             // Turn OFF all LEDs
        _delay_ms(100);                 // Wait 100 milliseconds
    }
}
