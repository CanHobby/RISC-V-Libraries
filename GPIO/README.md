# GPIO class functions
Note that "pins" are expressed as A4, D5 etc due to the multitude of GPIO pins on some RISC-V MCUs, they are defined as uint32_t in "pins.h" in the format of 0x000P000p where P is the Port number and p is the pin number.  ie. D5 = 0x0004005, G12 = 0x0x0007000C

### int gpio.pinMode( uint32_t pin, enum mode );

### int gpio.digitalWrite( uint32_t pin, int state );

### int gpio.digitalRead( uint32_t pin );

#### digitalWrite and digitalRead are concessions for Arduinites - the are defined  to gpio.write and gpio.read respectively.

Writing to multiple pins is provided in the standard MRS peripheral section - I plan to make "wrappers" in my class to provide a consistent interface.  For now here are some useful functions to use.

GPIO_Write( GPIOC, 0xF );   will write a 1 to the lower 4 bits of Port C.

uint16_t GPIO_ReadInputData( GPIOD );  will return the contents of Port D.

I also plan to write a multi-pin pinMode - (your encouragement with make this happen faster).

