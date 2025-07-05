/*********************************************************************************
 * Program Title   : LED Sweep with Trail using ATmega2560 (Knight Rider)        *
 * Author          : Sadan Asampally                                             *
 * Date            : 05 July 2025                                                *
 * Time            : 12:40 PM                                                    *
 * Description     : This program creates a sweeping LED effect on PORTC.        *
 *                   Multiple LEDs turn ON in a left-to-right and back           *
 *                   pattern creating a trailing light effect (Knight Rider).    *
 * Target MCU      : ATmega2560                                                  *
 * Clock Frequency : 16 MHz                                                      *
 ********************************************************************************/

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

// -------- Pin & Port Definitions --------
#define LED_PORT_DIR  DDRC
#define LED_PORT      PORTC

// -------- Constants --------
#define OUTPUT         0xFF      // All PORTC pins as output
#define TRAIL_LENGTH   3         // Number of LEDs to keep ON as trail
#define STEP_DELAY     50       // Delay between shifts in milliseconds

int main(void)
{
    LED_PORT_DIR = OUTPUT;       // Configure all PORTC pins as output

    while (1)
    {
        // Left to right sweep
        for (uint8_t i = 0; i <= (8 - TRAIL_LENGTH); i++)
        {
            LED_PORT = (0x07 << i);  // Light 3-bit wide trail
            _delay_ms(STEP_DELAY);
        }

        // Right to left sweep
        for (int8_t i = (8 - TRAIL_LENGTH - 1); i >= 0; i--)
        {
            LED_PORT = (0x07 << i);
            _delay_ms(STEP_DELAY);
        }
    }
}

