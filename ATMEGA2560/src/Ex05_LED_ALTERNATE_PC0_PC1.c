/********************************************************************************
 * Program Title   : Alternate LED Blink using ATmega2560 (PC0 ? PC1)          *
 * Author          : Sadan Asampally                                           *
 * Date            : 05 July 2025                                              *
 * Time            : 12:30 PM                                                  *
 * Description     : This program alternately blinks two LEDs connected to     *
 *                   PC0 and PC1. While one LED is ON, the other is OFF.       *
 *                   The state switches every 50 milliseconds.                *
 * Target MCU      : ATmega2560                                                *
 * Clock Frequency : 16 MHz                                                    *
 ********************************************************************************/

#define F_CPU 16000000UL                // Set clock frequency for delay calculation

#include <avr/io.h>                     // AVR I/O definitions
#include <util/delay.h>                 // Delay functions

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC              // Direction register for PORTC
#define LED_PORT      PORTC             // Data register for PORTC

// -------- Constants --------
#define LED0          PC0
#define LED1          PC1
#define OUTPUT_MASK   ((1 << LED0) | (1 << LED1))  // Enable PC0 and PC1 as output

int main(void)
{
    LED_PORT_DIR |= OUTPUT_MASK;        // Set PC0 and PC1 as output pins

    while (1)
    {
        LED_PORT |= (1 << LED0);        // Turn ON PC0
        LED_PORT &= ~(1 << LED1);       // Turn OFF PC1
        _delay_ms(50);                 // Wait

        LED_PORT &= ~(1 << LED0);       // Turn OFF PC0
        LED_PORT |= (1 << LED1);        // Turn ON PC1
        _delay_ms(50);                 // Wait
    }
}

