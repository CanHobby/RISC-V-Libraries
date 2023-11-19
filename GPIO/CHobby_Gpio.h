/* CHobby_Gpio.h  Author: CanHobby.ca */

#ifndef CHOBBY_GPIO_H_
#define CHOBBY_GPIO_H_

/*****  CH32V003 Ports and Pins  ****/
#define LEDs_PORT	GPIOC
#define Rst_PORT	GPIOD

#define PORTA_Free	0x00  // A1=A2=Crystal
#define PORTB_Free	0x00  // PORTB does not exist on -003
#define PORTC_Free	0xFF  // all pins unused
#define PORTD_Free	0x1D  // D7=Rst, D6=RX, D5=TX, D1=UpLoad pin

#define Rst PD7
#define Rst_PIN	GPIO_Pin_7


void CHobby_GPIO_INIT( GPIO_TypeDef *Port, uint16_t Pins );

#endif /* CHOBBY_GPIO_H_ */
