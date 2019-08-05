/*
 * _PMM.c
 *
 *  Created on: 2019Äê2ÔÂ28ÈÕ
 *      Author: HR052
 */

#include "_msp430fr6989_lanchpad.h"
#include "_PMM.h"

void _PMM_ALL_End_()
{
    _LP_LEDR_on;

    while(1)
    {
       IO_CLK_H;
       _MCU_T0Delay_(15);       //~470us
       IO_CLK_L;
       _MCU_T0Delay_(15);
    }
}

void _PMM_LP_Controll()
{
    _PMM_SHT21_GND;
    _PMM_ADC_GND;
    _PMM_CC_GND;

    IO_D_H;
    IO_CLK_H;
}
