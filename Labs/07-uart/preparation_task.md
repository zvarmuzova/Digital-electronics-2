## Preparation tasks

1. Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of five push buttons: Select, Left, Up, Down, and Right.

   &nbsp;

   &nbsp;

   &nbsp;

   &nbsp;

   &nbsp;

   &nbsp;

2. According to the connection, calculate the voltage values on pin PC0[A0] if one button is pressed at a time. In this case, the voltage on the pin is given by the [voltage divider](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/), where resistors R3, R4, R5 and R6 are applied successively.

   ![Equation: Voltage divider](Images/eq_divider1.png)

   ![Equation: Voltage divider](Images/eq_divider2.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider3.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider4.png)

   &nbsp;

   ![Equation: Voltage divider](Images/eq_divider5.png)

   &nbsp;

3. Calculate the voltage value if none of the push buttons is pressed.

   ![Equation: Voltage divider](Images/eq_divider6.png)

   &nbsp;

4. Calculate the ADC values for these voltages according to the following equation if reference is Vref=5V and number of bits for analog to digital conversion is n=10.

   ![Equation: ADC conversion](Images/eq_adc.png)

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 |
   | Down   | 1,202&nbsp;V |     | 257 |
   | Left   | 1,970&nbsp;V |     | 410 |
   | Select | 3,182&nbsp;V |     | 639 |
   | none   |       |     | 1023 |


      | **Operation** | **Register(s)** | **Bit(s)** | **Description** |
   | :-- | :-: | :-: | :-- |
   | Voltage reference    | ADMUX | REFS1:0 | 00: ..., 01: AVcc voltage reference (5V), ... |
   | Input channel        | ADMUX | MUX3:0 | 0000: ADC0, 0001: ADC1, ... |
   | ADC enable           | ADCSRA |  |  |
   | Start conversion     |  |  |  |
   | ADC interrupt enable |  |  |  |
   | ADC clock prescaler  |  | ADPS2:0 | 000: Division factor 2, 001: 2, 010: 4, ...|
   | ADC 10-bit result    |  |  |  |