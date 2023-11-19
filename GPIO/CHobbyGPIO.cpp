/*
 * CHobbyGPIO.cpp
 *  Created on: Nov. 16, 2023
 *      Author: CanHobby   github.com/CanHobby/GPIO
 */

#include <CHobbyGPIO.h>

extern "C" {
	void EXTI7_0_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
	void CHobby_reset();
	};

	void CHobby_reset() {  asm(" j 0 " ); }

CHobby_GPIO::CHobby_GPIO() {
	 _pins = 0;
	_port = NULL;
}

CHobby_GPIO::~CHobby_GPIO() {
	// TODO Auto-generated destructor stub
}

uint8_t CHobby_GPIO::read( uint32_t pin ) {

	if( (pin >> 16) == 1 ) _port = GPIOA;
	if( (pin >> 16) == 3 ) _port = GPIOC;
	if( (pin >> 16) == 4 ) _port = GPIOD;

	return( GPIO_ReadInputDataBit( _port, 1 << ( pin & 0xFFFF)) );
}

int CHobby_GPIO::write( uint32_t pin, bool st ) {

	if( (pin >> 16) == 1 ) _port = GPIOA;
	if( (pin >> 16) == 3 ) _port = GPIOC;
	if( (pin >> 16) == 4 ) _port = GPIOD;

	GPIO_WriteBit( _port, 1 << (pin & 0xFF), st ? Bit_SET : Bit_RESET );

	return 0;

}

int CHobby_GPIO::pinMode( uint32_t pins, GPIOMode_TypeDef mode, FunctionalState irq ) {

	GPIO_InitTypeDef GPIO_InitStructure = {0};
    EXTI_InitTypeDef EXTI_InitStructure = {0};
    NVIC_InitTypeDef NVIC_InitStructure = {0};

	_pins = ( 1 << ( pins & 0xFFFF) );

	if( (pins >> 16) == 4 ) { _port = GPIOD; }  //  rcc_mask = 0x20; }
	if( (pins >> 16) == 3 ) { _port = GPIOC; }  //  rcc_mask = 0x10; }

//	printf("pinMode pin %c%d (0x%08X) to 0x%04X\n", pins >> 16 | 0x40, pins & 0xFFFF, pins, mode );

    RCC_APB2PeriphClockCmd( pins >> 12, ENABLE );
    GPIO_InitStructure.GPIO_Pin = _pins;
    GPIO_InitStructure.GPIO_Mode = mode;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init( _port, &GPIO_InitStructure );

//    GPIO_EXTILineConfig(GPIO_PortSourceGPIOD, GPIO_PinSource4);  //  _pins&0xFF );
    GPIO_EXTILineConfig( (pins >> 16)-1, pins&0xFF );
    EXTI_InitStructure.EXTI_Line = _pins;
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt ;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_InitStructure.EXTI_LineCmd = irq;  //  irq;
//    printf( "pinSource = 0x%X\n", pins&0xFF );  //  GPIO_PinSource4 );  //  _pins&0xFF );  //  pin );
//    printf( "pinLine   = 0x%X\n", EXTI_Line4 );  //  ( 1 << pin ) | EXTI_Line7 );
    EXTI_Init(&EXTI_InitStructure);

    NVIC_InitStructure.NVIC_IRQChannel = EXTI7_0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

	return 0;
}


void EXTI7_0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0)!=RESET)
	  { EXTI_ClearITPendingBit(EXTI_Line0);  /* Clear Flag */
	    printf( "IRQ from D0\n"); }

  if(EXTI_GetITStatus(EXTI_Line2)!=RESET)
	  { EXTI_ClearITPendingBit(EXTI_Line2);  /* Clear Flag */
	    printf( "IRQ from D2\n"); }

  if(EXTI_GetITStatus(EXTI_Line3)!=RESET)
	  { EXTI_ClearITPendingBit(EXTI_Line3);  /* Clear Flag */
	    printf( "IRQ from D3\n"); }

  if(EXTI_GetITStatus(EXTI_Line4)!=RESET)
	  { EXTI_ClearITPendingBit(EXTI_Line4);  /* Clear Flag */
	    printf( "IRQ from D4\n"); }

  if(EXTI_GetITStatus(EXTI_Line7)!=RESET)
  	  { EXTI_ClearITPendingBit( 0xFFF );   /* Clear All Flag - we are going to Reset */
  	    CHobby_reset();  }
}

