/*********************************************************************************
 * Program Title    : Blink LED using ATmega2560 (Bare-Metal C)                  *
 * Author           : Sadan Asampally                                            *
 * Date             : 05 July 2025                                               *
 * Time             : 12:00 PM                                                   *
 * Description      : This program toggles an LED connected to pin PC0 of        *
 *                    PORTC at regular intervals (10ms delay).                   *
 *                    Useful for fast blink or heartbeat indicators.             *
 * Target MCU       : ATmega2560                                                 *
 * Clock Frequency  : 16 MHz                                                     *
 ********************************************************************************/

#define F_CPU 16000000UL                // Define CPU clock frequency as 16 MHz

#include <avr/io.h>                     // AVR I/O definitions
#include <util/delay.h>                 // Delay functions

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // Data Direction Register for PORTC
#define LED_PORT      PORTC             // Data Register for PORTC
#define LED_PIN       PC0               // LED connected to PC0

// -------- Constants --------
#define LED_ON         (1 << LED_PIN)   // Bit mask to toggle LED
#define OUTPUT         0xFF             // Set entire port as output

int main(void)                          // Entry point of the program
{
    LED_PORT_DIR = OUTPUT;              // Set all PORTC pins as output

    while (1)                           // Infinite loop
    {
        LED_PORT ^= LED_ON;             // Toggle PC0 (ON if OFF, OFF if ON)
        _delay_ms(10);                  // Wait for 10 milliseconds
    }
}
