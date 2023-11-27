/*
 * CHobbyPWM.cpp
 *  Created on: Nov. 26, 2023
 *      Author: github.com/CanHobby/RISC-V
**/

#include "CHobbyPWM.h"

CHobby_PWM::CHobby_PWM() {
	_pin = 0;
	_port = 0;

}

CHobby_PWM::~CHobby_PWM() {
	// TODO Auto-generated destructor stub
}

void CHobby_PWM::TIM1_PWMOut_Init( uint32_t pin, uint16_t ccp ) {

	_pin = ( 1 << ( pin & 0xFFFF) );

	if( ((pin >> 16) & 0xF) == 1 ) _port = GPIOA;
	if( ((pin >> 16) & 0xF) == 2 ) _port = GPIOB;
	if( ((pin >> 16) & 0xF) == 3 ) _port = GPIOC;
	if( ((pin >> 16) & 0xF) == 4 ) _port = GPIOD;

	printf("PWM_init: pin %c%d (0x%08X) to %02d%%\n", pin >> 16 | 0x40, pin&0xF, pin, ccp );
	printf("PWM_init: _port=0x%08X GPIOB=0x%08X\n", _port, GPIOB );

	    GPIO_InitTypeDef        GPIO_InitStructure = {0};
	    TIM_OCInitTypeDef       TIM_OCInitStructure = {0};
	    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure = {0};

	    RCC_APB2PeriphClockCmd( 2 << ((pin >> 16) & 0xF) | RCC_APB2Periph_TIM1, ENABLE );
//	    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_TIM1, ENABLE);

	    GPIO_InitStructure.GPIO_Pin = _pin;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_Init( _port, &GPIO_InitStructure);
//	    GPIO_Init(GPIOB, &GPIO_InitStructure);

	    TIM_TimeBaseInitStructure.TIM_Period = 100;
	    TIM_TimeBaseInitStructure.TIM_Prescaler = 750-1;
	    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStructure);

	#if(PWM_MODE == PWM_MODE1)
	    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;

	#elif(PWM_MODE == PWM_MODE2)
	    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;

	#endif
	 if( !(pin & N_OUTPUT) ) TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	 if( (pin & N_OUTPUT) )  TIM_OCInitStructure.TIM_OutputNState = TIM_OutputNState_Enable;
	    TIM_OCInitStructure.TIM_Pulse = 100-ccp;
	    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	if( pin == PWM1 ) TIM_OC1Init(TIM1, &TIM_OCInitStructure);
	if( (pin==PWM2) || (pin==PWM2N) ) TIM_OC2Init(TIM1, &TIM_OCInitStructure);
	if( (pin==PWM3) || (pin==PWM3N) ) TIM_OC3Init(TIM1, &TIM_OCInitStructure);
	if( pin == PWM4 ) TIM_OC4Init(TIM1, &TIM_OCInitStructure);

	    TIM_CtrlPWMOutputs(TIM1, ENABLE);
	    TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Disable);
	    TIM_ARRPreloadConfig(TIM1, ENABLE);
	    TIM_Cmd(TIM1, ENABLE);

}
