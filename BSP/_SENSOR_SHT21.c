/*
 * _SENSOR_STH21.c
 *
 * SHT21温度传感器基本操作
 *
 *  Created on: 2017年8月16日
 *      Author: HR052
 */

#include <string.h>
#include "_msp430fr6989_lanchpad.h"
#include "_SENSOR_SHT21.h"

//define address
#define SHT21_ADDR 0x40
#define SHT21_TEMP 0xE3
#define SHT21_HUMI 0xE5
#define SHT21_USER_W 0xE6
#define SHT21_USER_R 0xE7
#define SHT21_TEMP_LOW 0x83
#define SHT21_HUMI_LOW 0x03

static unsigned char TxData[2];             // Table of data to transmit

void _Sensor_SHT21_readTEM_(unsigned int* tem)
{
    _UCB0_I2CAddress_(SHT21_ADDR);
    //set measurement accuracy
    TxData[0] = SHT21_USER_W;
    TxData[1] = SHT21_TEMP_LOW;
    _UCB0_I2CWrite_(TxData,2);
    //read data
    TxData[0]=SHT21_TEMP;
    _UCB0_I2CWrite_(TxData,1);

    _UCB0_I2CRead_(TxData,2);
    //The resolution of temperature ADC is 14bit
    //The 2 LSB must be set to 0
    *tem = TxData[0];
    *tem = (*tem) << 8;
    *tem += TxData[1];
    *tem &= ~0x0003;
}

void _Sensor_SHT21_readHUM_(unsigned int* hum)
{
    _UCB0_I2CAddress_(SHT21_ADDR);
    //set measurement accuracy
    TxData[0] = SHT21_USER_W;
    TxData[1] = SHT21_HUMI_LOW;
    _UCB0_I2CWrite_(TxData,2);
    //read data
    TxData[0]=SHT21_HUMI;
    _UCB0_I2CWrite_(TxData,1);

    _UCB0_I2CRead_(TxData,2);
    //The resolution of humidity ADC is 12bit
    //The 2 LSB must be set to 0
    *hum = TxData[0];
    *hum = (*hum) << 8;
    *hum += TxData[1];
    *hum &= ~0x0003;
}

void _Sensor_SHT21_getTEM_(unsigned int* tem)
{
    _Sensor_SHT21_readTEM_(tem);
    if(*tem > 0)
        *tem = (-46.85+175.72*(*tem)/65536)*100;
}

void _Sensor_SHT21_getHUM_(unsigned int* hum)
{
    _Sensor_SHT21_readHUM_(hum);
    if(*hum > 0)
        *hum = (-6+125.0/65536*(*hum))*100;
}


