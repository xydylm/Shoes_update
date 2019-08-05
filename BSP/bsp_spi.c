/*
 * bsp_spi.c
 *
 *  Created on: 2018年11月30日
 *      Author: xu
 *      SPI初始化配置			【复用功能通过datasheet里查找】
 *
 *
 *      		硬件说明:
 *      		 	EUSCI_B1_SPI:
 *      						SPI_CLK  --> P4.2
* 					  		    SPI_CS   --> P4.3
* 					  			SPI_MOSI --> P4.0
* 					  			SPI_MISO --> P4.1
 *
 *      			EUSCI_A0_SPI:
 *      						SPI_CLK  --> P2.2
* 					  		    SPI_CS   --> P2.3
* 					  			SPI_MOSI --> P4.2
* 					  			SPI_MISO --> P4.3
*
*
* 					本套代码使用的是EUSCI_B1_SPI
 */

#include "bsp_spi.h"

/************************************************************************************************
 *  说	明 : SPI相关引脚初始化
 *  参	数 : 无
 *  返回值  : 无
************************************************************************************************/
void SPI_GPIO_Config(void)
{
	//CLK(4.2)
//	P4DIR |= SPI_CLK_PIN;	//设置时钟引脚为输出方向...手册上说可以不用配置方向
	P4SEL1 |= SPI_CLK_PIN;
	P4SEL0 &=~ SPI_CLK_PIN;		//功能复用

	//MOSI(4.0)
//	P4DIR |= SPI_MOSI_PIN;	//设置主机输出从机输入引脚为输出方向...手册上说可以不用配置方向
	P4SEL1 |=  SPI_MOSI_PIN;
	P4SEL0 &=~ SPI_MOSI_PIN;		//功能复用

	//MISO(4.1)
//	P4DIR |= SPI_MISO_PIN;	//设置主机输入从机输出引脚为输入方向...手册上说可以不用配置方向;
	P4SEL1 |=  SPI_MISO_PIN;
	P4SEL0 &=~ SPI_MISO_PIN;		//功能复用
}


/************************************************************************************************
 *  说	明 : SPI片选引脚输出高电平
 *  参	数 : 无
 *  返回值  : 无
************************************************************************************************/
void SPI_CS_HIGH(void)
{
	P4DIR |= SPI_CS_PIN;	//配置为输出方向
	P4OUT |= SPI_CS_PIN;	//输出高电平
}


/*
 *  说	明 : SPI片选引脚输出低电平
 *  参	数 : 无
 *  返回值  : 无
************************************************************************************************/
void SPI_CS_LOW(void)
{
	P4DIR |=  SPI_CS_PIN;	//配置为输出方向
	P4OUT &=~ SPI_CS_PIN;	//输出低电平
}


/************************************************************************************************
 *  说	明 : SPI寄存器初始化配置
 *  参	数 : 无
 *  返回值  : 无
************************************************************************************************/
void SPI_Init_Config(void)
{
	UCB1BR0 = 0x01;
	UCB1BR1 = 0x00;			//传输速率配置

	UCB1CTL0 |= 0xAD;
	UCB1CTL1 = 0x82;		//SPI初始化寄存器配置，注：此寄存器配置完成后已经清零了，不需要再次配置位UCSWRST
}


/************************************************************************************************
 *  说	明 : SPI始化配置(严格按照手册上说明的配置步骤，请参照手册说明)
 *  参	数 : 无
 *  返回值  : 无
************************************************************************************************/
void SPI_Init(void)
{
//	UCB1CTLW0 |= UCSWRST;
	SPI_Init_Config();
	SPI_GPIO_Config();
//	UCB1CTLW0 &=~ UCSWRST;
}


/************************************************************************************************
 *  说	明 : SPI发送一个字节函数
 *  参	数 : 要发送的数据
 *  返回值  : 接收到的数据
************************************************************************************************/
uint8_t SPI_Send(uint8_t data)
{
	uint8_t receive_data = 0x00;	//定义一个变量作为接收数据缓存区

	UCB1TXBUF = data;			//将数据写入发送缓存区

	receive_data = UCB1RXBUF;		//读取收到的数据

	return receive_data;
}
