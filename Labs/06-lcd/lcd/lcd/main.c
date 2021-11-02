/***********************************************************************
 * 
 * Stopwatch with LCD display output.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2017-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include "lcd.h"            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for conversion function

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD display when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize LCD display
    lcd_init(LCD_DISP_ON);
	
	/* Variables ---------------------------------------------------------*/
	// Custom character definition using 
	uint8_t customChar[64] = {		// 8*8 = 64
		0b00111,		// 0
		0b01110,
		0b11100,
		0b11000,
		0b11100,
		0b01110,
		0b00111,
		0b00011,
		0b10101,	// další znak - 1
		0b10101,
		0b10101,
		0b01110,
		0b00100,
		0b00100,
		0b00100,
		0b00100,
		0b10101,	//další znak - 2
		0b01010,
		0b10101,
		0b01010,
		0b10101,
		0b01010,
		0b10101,
		0b01010,
		// 03 - first progress bar
		0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 
		// second prog. bar (04)
		0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 
		// 3. (05)
		0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 
		// 4. (06) 
		0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 
		// 5. (07)
		0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111
	};

    // Put string(s) at LCD display
    //lcd_gotoxy(1, 0);
    //lcd_puts("LCD Test");
    //lcd_putc('!');
	
    lcd_gotoxy(1, 0);
    lcd_puts("00:00.0   a");
	
    //lcd_gotoxy(1, 1);
	//lcd_putc('b');
	lcd_gotoxy(11, 1);
	lcd_putc('c');
	
    // Set pointer to beginning of CGRAM memory
    lcd_command(1 << LCD_CGRAM);
    for (uint8_t i = 0; i < 64; i++)
    {
        // Store all new chars to memory line by line
        lcd_data(customChar[i]);
    }
    // Set DDRAM address
    lcd_command(1 << LCD_DDRAM);
    
    // Display first custom character
    lcd_putc(0);
	// go to another position and display second char
	lcd_gotoxy(12, 1);
	lcd_putc(1);
	lcd_putc(2);
	
	
	// progress bar - pozice 2 až 6
	lcd_gotoxy(1, 1);
	lcd_putc(7);
	lcd_putc(6);
	lcd_putc(5);
	lcd_putc(4);
	lcd_putc(3);

    // Configure 8-bit Timer/Counter2 for Stopwatch
    // Set the overflow prescaler to 16 ms and enable interrupt
	TIM2_overflow_16ms();
	TIM2_overflow_interrupt_enable();
	
    // Configure 8-bit Timer/Counter0 for Stopwatch
    // Set the overflow prescaler to 16 ms and enable interrupt
	TIM0_overflow_16ms();
	TIM0_overflow_interrupt_enable();

    // Enables interrupts by setting the global interrupt mask
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines ISRs */
    }

    // Will never reach this
    return 0;
}

/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD display every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t number_of_overflows = 0;
    static uint8_t tens = 0;        // Tenths of a second
    static uint8_t secs = 0;        // Seconds
    char lcd_string[2] = "  ";      // String for converting numbers by itoa()
	int16_t sec_sqr;
	char lcd_string_sqr[4] = "    ";
	
    number_of_overflows++;
    if (number_of_overflows >= 6)
    {
        // Do this every 6 x 16 ms = 100 ms
        number_of_overflows = 0;

        // WRITE YOUR CODE HERE
		//itoa(tens, lcd_string, 10);     // Convert decimal value to string
		//lcd_puts(lcd_string);
		
		tens++;
		if(tens>=10)
		{
			tens = 0;
			secs++;
			if(secs>=60)
			{
				secs = 0;
			}
			sec_sqr = secs * secs;
			itoa(sec_sqr, lcd_string_sqr, 10);
			lcd_gotoxy(11,0);
			lcd_puts(lcd_string_sqr);
			
		}
			lcd_gotoxy(7,0);
			lcd_putc(tens + '0');		// + 48 according to acsii table, or + '0'
			itoa(secs, lcd_string, 10);
			lcd_gotoxy(4,0);
			if(secs<10) lcd_putc('0');	//posunutí kurzoru o jedno (zapíše nic na pozici)
			lcd_puts(lcd_string);		// 10 a vìtší èísla na pozici (4,0)
    }
    // Else do nothing and exit the ISR
}

