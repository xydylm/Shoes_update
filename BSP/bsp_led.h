/*
 * bsp_led.h
 *	硬件连接:LED1 --> P1.0
 *  Created on: 2018年11月30日
 *      Author: xu
 */

#ifndef BSP_BSP_LED_H_
#define BSP_BSP_LED_H_

#include "msp430fr6989.h"


void GPIO_InitConfig(void);
void LED_Config(void);

#endif /* BSP_BSP_LED_H_ */
