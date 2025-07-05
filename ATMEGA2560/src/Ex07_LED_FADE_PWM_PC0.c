/*********************************************************************************
 * Program Title   : LED Brightness Control using Software PWM (PC0)             *
 * Author          : Sadan Asampally                                             *
 * Date            : 05 July 2025                                                *
 * Time            : 12:50 PM                                                    *
 * Description     : This program simulates PWM by manually switching LED        *
 *                   ON/OFF with variable duty cycle on PC0. It gradually        *
 *                   increases and decreases brightness.                         *
 * Target MCU      : ATmega2560                                                  *
 * Clock Frequency : 16 MHz                                                      *
 ********************************************************************************/

#define F_CPU 16000000UL                // Define clock speed for _delay_us()

#include <avr/io.h>                     // AVR register definitions
#include <util/delay.h>                 // Delay library for timing

// -------- Pin & Port Definitions --------
#define LED_DDR   DDRC                  // Data Direction Register for PORTC
#define LED_PORT  PORTC                 // Data Output Register for PORTC
#define LED_PIN   PC0                   // LED connected to PC0

// -------- Software PWM Function --------
// This function simulates one full PWM cycle at 100% resolution
void software_pwm_brightness(uint8_t duty)
{
    // Turn ON LED for 'duty' microseconds (duty cycle)
    LED_PORT |= (1 << LED_PIN);
    for (uint8_t i = 0; i < duty; i++)
        _delay_us(1);                   // ON-time delay

    // Turn OFF LED for remaining time of 255 - duty
    LED_PORT &= ~(1 << LED_PIN);
    for (uint8_t i = 0; i < (255 - duty); i++)
        _delay_us(1);                   // OFF-time delay
}

int main(void)
{
    LED_DDR |= (1 << LED_PIN);          // Configure PC0 as output

    while (1)
    {
        // Gradually increase brightness (fade IN)
        for (uint8_t duty = 0; duty < 255; duty++)
        {
            software_pwm_brightness(duty);
        }

        // Gradually decrease brightness (fade OUT)
        for (uint8_t duty = 255; duty > 0; duty--)
        {
            software_pwm_brightness(duty);
        }
    }
}
