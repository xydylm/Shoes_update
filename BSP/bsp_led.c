/*
 * bsp_led.c
 *
 *  	Created on: 2018年11月30日
 *      Author: xu
 *      说明：引脚未采用宏定义的原因是担心与后面某些引脚重复
 */
#include "bsp_led.h"


/************************************************************************************************
 *  说	明 : GPIO引脚初始化
 *  参	数 : 无
 *  返回值  : 无
*************************************************************************************************/
void GPIO_InitConfig(void)
{
	//初始化,配置为输出方向
	P1DIR = 0xFF;
	P2DIR = 0xFF;
	P3DIR = 0xFF;
	P4DIR = 0xFF;
	P5DIR = 0xFF;
	P6DIR = 0xFF;
	P7DIR = 0xFF;
	P8DIR = 0xFF;
	P9DIR = 0xFF;
	P10DIR = 0xFF;
	PJDIR = 0xFFFF;

	//将所有的引脚初始化配置为输出低电平
	P1OUT = 0x00;
	P2OUT = 0x00;
	P3OUT = 0x00;
	P4OUT = 0x00;
	P5OUT = 0x00;
	P6OUT = 0x00;
	P7OUT = 0x00;
	P8OUT = 0x00;
	P9OUT = 0x00;
	P10OUT = 0x00;
	PJOUT = 0x00;
}


/************************************************************************************************
 *  说	明 : LED相关引脚初始化
 *  参	数 : 无
 *  返回值  : 无
*************************************************************************************************/
void LED_Config(void)
{
	P1DIR |=  BIT0;
	P1OUT &=~ BIT0;		//LED灯初始化配置为输出低电平(P1.0)

	P1DIR &=~ BIT1;		//按键1为输入方向(P1.1)
	P1REN |=  BIT1;
	P1OUT |=  BIT1;		//上拉使能
}



