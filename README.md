# RISC-V-Libraries
Sample Libraries for RISC-V MCUs

This is my attempt to put together some C++ classes for RISC-V peripherals, trying to emulate the "Arduino" style, and in some cases creating compatible functions.  My goal is to make them universal acreoss all WCH MCUs where possible so they are arranged here by peripheral type.

I start with GPIO - "blinky" is "hello world" for MCUs.  digitalWrite and digitalRead are available.<br>
and ADC - so far adc.read only ( analogRead and analogWrite are very different animals )... analogRead is available.

Next will be SPI because I use it for controlling NeoPixels.

I have included a sample main.cpp to show actual usage of these classes.

you may wish to view my <a href="https://github.com/CanHobby/RISC-V" target="_blank">updated C++ library installation</a>.
