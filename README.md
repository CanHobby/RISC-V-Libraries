# RISC-V-Libraries
Sample Libraries for RISC-V MCUs

This is my attempt to put together some C++ classes for RISC-V peripherals, trying to emulate the "Arduino" style, and in some cases creating compatible functions.  My goal is to make them universal acreoss all WCH MCUs where possible so they are arranged here by peripheral type.

I start with GPIO - "blinky" is "hello world" for MCUs.  digitalWrite and digitalRead are available.
and ADC - so far adc.read only ( analogRead and analogWrite are very different animals )... analogRead is available.

Next will be SPI because I use it for controlling NeoPixels.
