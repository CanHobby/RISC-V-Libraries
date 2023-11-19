/*
 * CHobbyGPIO.h
 *  Created on: Nov. 16, 2023
 *      Author: CanHobby    https://github.com/CanHobby/RISC-V-Libraries/tree/main/GPIO
 */

#ifndef INC_CHOBBYGPIO_H_
#define INC_CHOBBYGPIO_H_

#include <inttypes.h>
#include "pins.h"



class CHobby_GPIO {
public:
	CHobby_GPIO();
	virtual ~CHobby_GPIO();

	int pinMode( uint32_t pin, GPIOMode_TypeDef mode = OUTPUT, FunctionalState irq = DISABLE );
	int write( uint32_t pin, bool st );
	uint8_t read( uint32_t pin );

private:
	uint16_t _pins;
	GPIO_TypeDef * _port;

};

#endif /* INC_CHOBBYGPIO_H_ */
