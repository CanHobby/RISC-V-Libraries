/*
 * pins.h
 *  Created on: Nov. 16, 2023
 *  Author: CanHobby.ca  http://github.com/CanHobby/RISC-V
*/

#ifndef INC_PINS_H_
#define INC_PINS_H_

#include "debug.h"
#include "inttypes.h"
//#include "ch32v00x.h"
//#include "ch32v00x_gpio.h"

#define BD_CH32V103
#define _CHIP_103

#define HIGH Bit_SET
#define LOW  Bit_RESET
#define IRQ  true

#define A0	0x10000

#define A2	0x10002

#define A8	0x10008
#define A9	0x10008  //  A9 is USART1 Tx - BeWare
#define A11	0x1000B

#define B14 0x2000E
#define B15 0x2000F

#define C1	0x30001
#define C2	0x30002
#define C3	0x30003
#define C4	0x30004

#define C13 0x3000D

#define D0	0x40000
// #define D1	0x40001  //  PD1 is SWIO UpLoad pin
#define D2	0x40002
#define D3	0x40003
#define D4	0x40004

#define D6	0x40006
#define D7	0x40007

#define N_OUTPUT 0x10000000

#ifdef _CHIP_103
	#define PWM1  A8   //  PB13 (N)
	#define PWM2  A9   //  PA9  is USART_Tx
	#define PWM2N B14 | N_OUTPUT //  PA9  is USART_Tx
	#define PWM3  B15  //  PA10 is USART_Rx
	#define PWM3N B15 | N_OUTPUT //  PA10  is USART_Rx
	#define PWM4  A11
#endif

#ifdef _CHIP_003
	#define PWM1 D2
	//#define PWM2 A8
	#define PWM3 C3
	#define PWM4 C4
#endif

#define digitalRead(  p ) 	  gpio.read(  p )
#define digitalWrite( p, st ) gpio.write( p, st )
#define analogRead(   p ) 	  adc.Read_ADC( p )
#define analogWrite(  p, pc ) pwm.TIM1_PWMOut_Init( p, pc )
// pwm.TIM1_PWMOut_Init( PWM2N, 60 );

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
