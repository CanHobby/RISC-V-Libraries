# the GPIO class provies the following functions:

### int pinMode(uint32_t pin, GPIOMode_TypeDef mode = OUTPUT, FunctionalState irq = DISABLE)
  sets the mode of pin - allowed modes (from pins.h are: OUTPUT, INPUT, INPUT_PULLDOWN, INPUT_PULLUP -- default = OUTPUT
  irq = ENABLE sets the pin as an interrupt.  --  default = DISABLE
  return value undefined for now...

	int write( uint32_t pin, bool st );
  sets pin to HIGH or LOW
  return value undefined for now...

	uint8_t read( uint32_t pin );
  returns the state of pin

  Example Code:
  

#include <CHobbyGPIO.h>

#include "pins.h"

<code>

CHobby_GPIO gpio;	  // instantiate the Class

   gpio.pinMode( D4 );  //  set D4 to OUTPUT
   gpio.pinMode( C5, INPUT_PULLUP );  //  set C5 to INPUT with internal pullu-up
   
   digitalWrite( D4, HIGH );
   gpio.write( D4, LOW );    //  similat to above
   
   printf("C5 = %d\n", digitalRead( C5 ) );
   printf("C5 = %d\n", gpio.read( C5 ) );    //  same as above
  </code>

  <H1> How to Install the GPIO class</H1>
   <br>
add CHobby_GPIO.h   into the Peripheral/inc directory<br>
add pins.h          into the Peripheral/inc directory<br><br>
add CHobby_GPIO.cpp into the Peripheral/src directory
  
  
