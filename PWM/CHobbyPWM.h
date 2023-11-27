/*
 * CHobbyPWM.h
 *  Created on: Nov. 26, 2023
 *      Author: github.com/CanHobby/RISC-V
 */

#ifndef LIBRARIES_CHOBBYPWM_H_
#define LIBRARIES_CHOBBYPWM_H_

#include "inttypes.h"
#include "CHobby_pins.h" // - the various classes refer to this ".h"
// which has important #defines which you may want to change.
#include "debug.h"

/* PWM Output Mode Definition */
#define PWM_MODE1    0
#define PWM_MODE2    1

/* PWM Output Mode Selection */
// #define PWM_MODE PWM_MODE1
#define PWM_MODE PWM_MODE2

class CHobby_PWM {
public:
	CHobby_PWM();
	virtual ~CHobby_PWM();

	void TIM1_PWMOut_Init( uint32_t pin, uint16_t ccp );

private:
	uint16_t _pin;
	GPIO_TypeDef * _port;
};

#endif /* LIBRARIES_CHOBBYPWM_H_ */
