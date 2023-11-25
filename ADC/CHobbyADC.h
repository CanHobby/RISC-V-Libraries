/** CHobbyADC.h
 *  Created on: Nov. 23, 2023
 *  Author: https://github.com/CanHobby/RISC-V
***/


#ifndef CHOBBYADC_H_
#define CHOBBYADC_H_

#include <inttypes.h>
#include "debug.h"
#include "CHobby_pins.h"

class CHobby_ADC {
public:
	CHobby_ADC();
	virtual ~CHobby_ADC();

	void Init_ADC( uint32_t pin );
	uint16_t Read_ADC( uint8_t ch );

private:
	uint16_t _pin;
	GPIO_TypeDef * _port;


};

#endif /* CHOBBYADC_H_ */
