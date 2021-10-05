/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define BLINK_DELAY 500
#define LED_1 PC5			// AVR pin where first LED is connected
#define LED_2 PC4			// AVR pin where second LED is connected
#define LED_3 PC3			// AVR pin where third LED is connected
#define LED_4 PC2			// AVR pin where fourth LED is connected
#define LED_5 PC1			// AVR pin where fifth LED is connected
#define BUTTON PD2			// AVR pin where button is connected
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/sfr_defs.h>

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // First LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_1);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_1);
	
	// Second LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_2);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_2);
	
	// Third LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_3);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_3);
	
	// Fourth LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_4);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_4);
	
	// Fifth LED at port C
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_5);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_5);
	
	
	// Configure Push button at port D and enable internal pull-up resistor
	DDRD = DDRD & ~(1<<BUTTON);
	
	PORTD = PORTD | (1<<BUTTON);

    // Infinite loop
    while (1)
    {	
		// Pause several milliseconds
		_delay_ms(BLINK_DELAY);	
		
		if(bit_is_clear(PIND, 2))
		{
			// TO DO
			
		}
    }

    // Will never reach this
    return 0;
}

