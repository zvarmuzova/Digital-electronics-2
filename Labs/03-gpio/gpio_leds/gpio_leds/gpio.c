/***********************************************************************
 * 
 * GPIO library for AVR-GCC.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2019-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 *
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include "gpio.h"
#include <avr/sfr_defs.h>

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: GPIO_config_output()
 * Purpose:  Configure one output pin in Data Direction Register.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_config_output(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name | (1<<pin_num);
}

/**********************************************************************
 * Function: GPIO_config_input_nopull()
 * Purpose:  Configure one input pin in DDR without pull-up resistor.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/

void GPIO_config_input_nopull(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    reg_name++;                     // Change pointer to Data Register (DDRx +1 = PORTx)
    *reg_name = *reg_name & ~(1<<pin_num);   // Data Register - no pull
}

/**********************************************************************
 * Function: GPIO_config_input_pullup()
 * Purpose:  Configure one input pin and enable pull-up.
 * Input:    reg_name - Address of Data Direction Register, such as &DDRB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_config_input_pullup(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num);  // Data Direction Register
    reg_name++;                     // Change pointer to Data Register (DDRx +1 = PORTx)
    *reg_name = *reg_name | (1<<pin_num);   // Data Register
}

/**********************************************************************
 * Function: GPIO_write_low()
 * Purpose:  Write one pin to a low value.
 * Input:    reg_name - Address of Port Register, such as &PORTB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/
void GPIO_write_low(volatile uint8_t *reg_name, uint8_t pin_num)
{
    *reg_name = *reg_name & ~(1<<pin_num); //
}

/**********************************************************************
 * Function: GPIO_write_high()
 * Purpose:  Write one pin to a high value.
 * Input:    reg_name - Address of Port Register, such as &PORTB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/

void GPIO_write_high(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name | (1<<pin_num);		//set |
}

/**********************************************************************
 * Function: GPIO_toggle()
 * Purpose:  Toggle one output pin value in PORT register
 * Input:    reg_name - Address of Port Register, such as &PORTB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  none
 **********************************************************************/

void GPIO_toggle(volatile uint8_t *reg_name, uint8_t pin_num)
{
	*reg_name = *reg_name ^ (1<<pin_num);	//togo = xor
}

/**********************************************************************
 * Function: GPIO_read()
 * Purpose:  Get input pin value from PIN register
 * Input:    reg_name - Address of Port Register, such as &PORTB
 *           pin_num - Pin designation in the interval 0 to 7
 * Returns:  uint8_t
 **********************************************************************/
uint8_t GPIO_read(volatile uint8_t *reg_name, uint8_t pin_num)
{
	return bit_is_set(*reg_name, pin_num);
	
	//2. choice
	//if((*reg_name & (1<<pin_num)) == 0) return(0);
		//else return(1);
		
	//3. choice
	//return((*reg_name & (1<<pin_num)));
}
