#include <msp430.h>
#include "_msp430fr6989_lanchpad.h"
#include "_SENSOR_SHT21.h"
#include "_PMM.h"
#include "bsp_delay.h"
#include "bsp_cc1101.h"
#include "bsp_spi.h"


/*
 * main.c
 */





#define FRAM_START 0x1800

void _StepClear_()
{
    uint *fram_step;
    fram_step = (uint*)FRAM_START;
    *fram_step = 0;
}


void main(void)
{
    uint8_t sendByte[8];

    uint tem;
    uint hum;
//    uint adc;

    uint *fram_step;
    fram_step = (uint*)FRAM_START;

    WDTCTL = WDTPW | WDTHOLD;       // Stop watchdog timer

    _MCU_LPMSet_(_PMM_LP_Controll);         // Low Power Set -- all port set to GND output(LEDL on)

#if 1

    P2OUT |= BIT6;

    (*fram_step)++;

    _PMM_SHT21_VCC;
    _MCU_T0Delay_(750);
    _UCB0_I2CInit_();
    _Sensor_SHT21_getTEM_(&tem);
    _Sensor_SHT21_getHUM_(&hum);
    _PMM_SHT21_GND;

    P2OUT &= ~BIT6;

/*    _PMM_ADC_VCC;
    _MCU_T0Delay_(30);
    // pressure sense
    _ADC12_AVCCInit_();
    _ADC12_Open_();
    while (!(ADC12IFGR0 & BIT0));           // ADC12 measurement
    adc = ADC12MEM0;
    _ADC12_Close_();
    _PMM_ADC_GND;*/

    sendByte[0] = *fram_step;
    sendByte[1] = (*fram_step)>>8;
    sendByte[2] = tem;
    sendByte[3] = tem>>8;
    sendByte[4] = hum;
    sendByte[5] = hum>>8;
    sendByte[6] = 0;
    sendByte[7] = 0;
//    sendByte[6] = adc;
//    sendByte[7] = adc>>8;

    P2OUT |= BIT6;


#endif


    _PMM_CC_VCC;
    SPI_Init();                                             //SPI初始化配置
    CC1101_Reset();                                         //复位CC1101
    CC1101_Init();                                          //CC1101初始化
    CC1101_RFDataPack_Send(sendByte, sizeof(sendByte));     //发送数据
    P4OUT &= ~(BIT0|BIT1|BIT2|BIT3);
    _PMM_CC_GND;

    P2OUT &= ~BIT6;

    _PMM_ALL_End_();
}

