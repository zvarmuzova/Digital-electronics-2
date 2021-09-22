# Digital-electronics-2

# Lecture 1
# Header 1
## Header 2
### Header 3

## Emphasis
_italics_ *italics*
__bold__ **bold**

## Lists
1. First ordered
2. Second ordedred

- 1
  - 1.1
  - 1.2
- 2
  - 2.1
    - 2.1.1

* First unordered
* Second unordered

## Links
[Google] (https://www.google.com/)
https://www.vut.cz/

## Table
x | y
---- | ----
0 | 2
1 | 4
2 | 8

## Listing of C source code
```c
  // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY);

        // Invert LED in Data Register
        // PORTB = PORTB xor 0010 0000
        PORTB = PORTB ^ (1<<LED_GREEN);
    }
```

