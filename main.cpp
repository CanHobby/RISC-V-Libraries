/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.cpp
 * Author             : CanHobby  ( git@canhobby.ca )
 * Version            : V1.0.0
 * Date               : 2023/11/22
 * Description        : Main C++ example program showing usage of I/O classes.
 * Derived from Nanjing Qinheng Microelectronics Co., Ltd.
 *******************************************************************************/

#include "CanHobby.h"    //  defines the class
#include "CHobby_pins.h" // - the various classes refer to this ".h"
// which has important #defines which you may want to change.
#include "debug.h"
#include "CHobbyADC.h"
#include "CHobbyGPIO.h"
#include "CHobbyPWM.h"

/* Global typedef */

/* Global define */
#define _CHIP_103			//  This is the MCU being used
#define LED_Pin_103 C13
#define LED_Pin_003 D6

/* Global Variable */
CanHobby    A_CLass;	//  instantiate the classes
CHobby_GPIO gpio;
CHobby_ADC  adc;
CHobby_PWM  pwm;

/*********************************************************************
 * @fn      main
 */

int main(void)
{
	uint32_t Chip = DBGMCU_GetCHIPID();
	const char *C8 = "C8T6";
	const char *R8 = "R8T6";
	int ClsArr;
	uint32_t  tmp;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    USART_Printf_Init(115200);
    printf("\nSysClk = %d MHz\n\r", SystemCoreClock / 1000000 );

    printf("Chip is CH32V%s", ((Chip & 0xFFFFFF00))==0x25004100 ? "103" : "003" );
    printf("%s: id = %08X\r\n", Chip & 0xF ? R8 : C8, Chip );
    printf("External C++ Libraries example\n\n\r");

/***/
    printf("*** Sample Class Demo ***\n");
    ClsArr =  A_CLass.getArr( );  // defaults to element 2
    printf( "ClsArr[default] = %d\n", ClsArr );
    ClsArr =  A_CLass.getArr( 0 );  // get element 0
    printf( "ClsArr[0] = %d\n*************************\n\n", ClsArr );
/***/

/***/
    printf("*** Sample analogWrite ***\n");
    // Output 60% of Vcc on PWM2N pin (PB14) define in CHobby_pims.h
    // pwm.TIM1_PWMOut_Init( PWM2N, 60 );
    analogWrite( PWM2N, 10 );
/***/

/***/
    printf("*** Sample GPIO Toggle and ADC Demo Loop ***\n");
    gpio.pinMode( LED_Pin_103 );
    adc.Init_ADC( A2 );  //    ADC_Function_Init();
//    ADC_RegularChannelConfig(ADC1, ADC_Channel_2, 1, ADC_SampleTime_239Cycles5 );

    while(1)
    {
    	gpio.toggle( LED_Pin_103 );
    	tmp  = adc.Read_ADC( 2 );
    	tmp  = analogRead( 2 );
    	tmp *= 330;
    	tmp /= 4096;
    	printf("%d.%02d V -- %04d\n", tmp/100, tmp%100, tmp );
    	Delay_Ms( 2000 );

    }
/***/
}
