/*
 * CHobbyADC.cpp
 *
 *  Created on: Nov. 23, 2023
 *      Author: moun
 */

#include "CHobbyADC.h"

#include "debug.h"

CHobby_ADC::CHobby_ADC() {
	 _pin = 0;
	_port = NULL;

}

CHobby_ADC::~CHobby_ADC() {
	// TODO Auto-generated destructor stub
}

/*********************************************************************
 * @fn      ADC_Init
 * @brief   Initializes ADC(s).
 * @return  none
*********/
void CHobby_ADC::Init_ADC( uint32_t pin )
{
    ADC_InitTypeDef  ADC_InitStructure = {0};
    GPIO_InitTypeDef GPIO_InitStructure = {0};

	if( (pin >> 16) == 4 ) { _port = GPIOD; }
	if( (pin >> 16) == 3 ) { _port = GPIOC; }

//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);
//    printf("Init_ADC RCC Port = 0x%08X\n", (2 << (pin >> 16) ) );
    RCC_APB2PeriphClockCmd( (2 << (pin >> 16) ), ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
    RCC_ADCCLKConfig(RCC_PCLK2_Div8);

    GPIO_InitStructure.GPIO_Pin =  (2 << (pin >> 16) ); //  GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
    GPIO_Init( _port, &GPIO_InitStructure);

    ADC_DeInit(ADC1);
    ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
    ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfChannel = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
# ifdef BD_CH32V003
    ADC_Calibration_Vol(ADC1, ADC_CALVOL_50PERCENT);
    ADC_DMACmd(ADC1, ENABLE);
#endif
    ADC_Cmd(ADC1, ENABLE);

    ADC_ResetCalibration(ADC1);
    while(ADC_GetResetCalibrationStatus(ADC1));
    ADC_StartCalibration(ADC1);
    while(ADC_GetCalibrationStatus(ADC1));
}

uint16_t CHobby_ADC::Read_ADC( uint8_t ch ) {

    uint16_t val;

// 003    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_241Cycles);
    ADC_RegularChannelConfig(ADC1, ch, 1, ADC_SampleTime_239Cycles5);
    ADC_SoftwareStartConvCmd(ADC1, ENABLE);

    while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
    val = ADC_GetConversionValue(ADC1);

    return val;
}

