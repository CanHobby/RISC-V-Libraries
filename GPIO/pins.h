/*
 * pins.h
 *  Created on: Nov. 16, 2023
 *      Author: CanHobby.ca  http://github.com/CanHobby
*/

#ifndef INC_PINS_H_
#define INC_PINS_H_

#include "ch32v00x.h"
#include "ch32v00x_gpio.h"

#define HIGH Bit_SET
#define LOW  Bit_RESET
#define IRQ  true

#define C3	0x30003

#define D0	0x40000
// #define D1	0x40001  //  PD1 is SWIO the UpLoad pin
#define D2	0x40002
#define D3	0x40003
#define D4	0x40004

#define D7	0x40007

#define digitalRead(  p ) 	  gpio.read(  p )
#define digitalWrite( p, st ) gpio.write( p, st )

#define OUTPUT GPIO_Mode_Out_PP
//    GPIO_Mode_AIN = 0x0,
#define INPUT GPIO_Mode_IN_FLOATING  	// = 0x04,
#define INPUT_PULLDOWN GPIO_Mode_IPD	// = 0x28,
#define INPUT_PULLUP   GPIO_Mode_IPU    // = 0x48,
//    GPIO_Mode_Out_OD = 0x14,
//  OUTPUT		 = GPIO_Mode_Out_PP,		// = 0x10,
//    GPIO_Mode_AF_OD = 0x1C,
//    GPIO_Mode_AF_PP = 0x18

#endif /* INC_PINS_H_ */
