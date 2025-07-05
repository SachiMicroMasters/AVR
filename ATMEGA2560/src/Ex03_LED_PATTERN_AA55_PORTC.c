
/********************************************************************************
 * Program Title   : LED Pattern Blink using ATmega2560 (0xAA/0x55 Toggle)     *
 * Author          : Sadan Asampally                                           *
 * Date            : 05 July 2025                                              *
 * Time            : 12:10 PM                                                  *
 * Description     : This program blinks all LEDs connected to PORTC in an     *
 *                   alternating pattern using 0xAA and 0x55. Each pattern      *
 *                   holds for 100 milliseconds. This creates a ripple effect. *
 * Target MCU      : ATmega2560                                                *
 * Clock Frequency : 16 MHz                                                    *
 ********************************************************************************/

#define F_CPU 16000000UL                // Define CPU clock frequency as 16 MHz

#include <avr/io.h>                     // Include I/O definitions
#include <util/delay.h>                 // Include delay utilities

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // Direction register for PORTC
#define LED_PORT      PORTC             // Data register for PORTC

// -------- Constants --------
#define OUTPUT         0xFF             // Set all 8 pins as output

int main(void)                          // Entry point of the program
{
    LED_PORT_DIR = OUTPUT;              // Configure PORTC as output

    while (1)                           // Infinite loop
    {
        LED_PORT = 0xAA;                // Pattern: 10101010
        _delay_ms(100);                 // Delay 100 ms

        LED_PORT = 0x55;                // Pattern: 01010101
        _delay_ms(100);                 // Delay 100 ms
    }
}
