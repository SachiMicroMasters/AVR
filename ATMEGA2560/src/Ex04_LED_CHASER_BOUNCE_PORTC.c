
/*********************************************************************************
 * Program Title   : LED Chaser Pattern using ATmega2560 (Left-Right Sweep)      *
 * Author          : Sadan Asampally                                             *
 * Date            : 05 July 2025                                                *
 * Time            : 12:20 PM                                                    *
 * Description     : This program creates a chaser effect across PORTC LEDs      *
 *                   moving left to right and then right to left repeatedly.     *
 *                   Each LED lights up for 5 milliseconds.                      *
 * Target MCU      : ATmega2560                                                  *
 * Clock Frequency : 16 MHz                                                      *
 ********************************************************************************/

#define F_CPU 16000000UL                // Define CPU clock frequency as 16 MHz

#include <avr/io.h>                     // AVR I/O header
#include <util/delay.h>                 // AVR delay library
#include <stdint.h>                     // For uint8_t type

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // PORTC direction register
#define LED_PORT      PORTC             // PORTC data register

// -------- Constants --------
#define OUTPUT         0xFF             // All pins as output

int main(void)
{
    LED_PORT_DIR = OUTPUT;              // Set PORTC as output

    while (1)
    {
        // Left to right sweep
        for (uint8_t i = 0; i < 8; i++)
        {
            LED_PORT = (1 << i);        // Turn ON one LED at a time
            _delay_ms(5);              // Short delay
        }

        // Right to left sweep
        for (int8_t i = 6; i > 0; i--)
        {
            LED_PORT = (1 << i);        // Turn ON one LED at a time in reverse
            _delay_ms(5);              // Short delay
        }
    }
}
