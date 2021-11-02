# Lab 6: Zdeňka Varmužová

Link to this file in your GitHub repository:

[https://github.com/zvarmuzova/Digital-electronics-2/tree/main/Labs/06-lcd](https://github.com/zvarmuzova/Digital-electronics-2/tree/main/Labs/06-lcd)


### LCD display module

1. In your words, describe what ASCII table is.
   * ASCII table: character encoding that uses numbers to represent characters

2. (Hand-drawn) picture of time signals between ATmega328P and LCD keypad shield (HD44780 driver) when transmitting three character data `De2`.

   ![time signals](images/time_signals_De2_3.png)


### Stopwatch

1. Flowchart figure for `TIMER2_OVF_vect` interrupt service routine which overflows every 16&nbsp;ms but it updates the stopwatch LCD approximately every 100&nbsp;ms (6 x 16&nbsp;ms = 100&nbsp;ms). Display tenths of a second and seconds `00:seconds.tenths`. Let the stopwatch counts from `00:00.0` to `00:59.9` and then starts again. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![flowchart](images/flowchart_2.png)


### Custom characters

1. Code listing of two custom character definition. Always use syntax highlighting and meaningful comments:

```c
/* Variables ---------------------------------------------------------*/
// Custom character definition
uint8_t customChar[16] = {
	0b10101,	// start of char 1 (0)  
	0b10101,
	0b10101,
	0b01110,	
	0b00100,
	0b00100,
	0b00100,	
	0b00100,
	0b10101,	//start of char 2 (1)
	0b01010,
	0b10101,
	0b01010,
	0b10101,
	0b01010,
	0b10101,
	0b01010
};
```


### Kitchen alarm

Consider a kitchen alarm with an LCD, one LED and three push buttons: start, +1 minute, -1 minute. Use the +1/-1 minute buttons to increment/decrement the timer value. After pressing the Start button, the countdown starts. The countdown value is shown on the display in the form of mm.ss (minutes.seconds). At the end of the countdown, the LED will start blinking.

1. Scheme of kitchen alarm; do not forget the supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values.

   ![kitchen alarm](images/kitchen_alarm.png)
