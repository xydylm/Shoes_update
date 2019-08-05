/*
 * _msp430fr6989_lanchpad.h
 *
 *  Created on: 2018Äê2ÔÂ8ÈÕ
 *      Author: HR052
 */

#ifndef _MSP430FR6989_LANCHPAD_H_
#define _MSP430FR6989_LANCHPAD_H_

#include"msp430.h"
#include <stdio.h>

#define uchar unsigned char
#define uint unsigned int

// CS
struct systemClk_kHz {
    unsigned int MCLK;
    unsigned int SMCLK;
    unsigned int ACLK;
};

// UART
#define uartReadMaxLength 20

// Lanchpad
// LED port operation
#define _LP_LEDR_INIT   P9DIR |= BIT7;
#define _LP_LEDR_on     P9OUT |= BIT7;
#define _LP_LEDR_off    P9OUT &= ~BIT7;

#define _LP_LEDL_INIT   P1DIR |= BIT0;
#define _LP_LEDL_on     P1OUT |= BIT0;
#define _LP_LEDL_off    P1OUT &= ~BIT0;

// special port set
#define _UCB0_I2C_PORTINIT\
    P1SEL1 &= ~(BIT6 | BIT7);\
    P1SEL0 |= BIT6 | BIT7;      // Configure P1.6/P1.7 for I2C
#define _ADC12_ADC_PORTINIT\
    P8SEL1 |= BIT4;\
    P8SEL0 |= BIT4;             // Configure P1.1 for ADC
#define _UCA1_UART_PORTINIT\
    P3SEL0 |= BIT4 | BIT5;\
    P3SEL1 &= ~(BIT4 | BIT5);   // Configure P3.4/P3.5 for USCI_A1 UART operation
#define _UCA0_UART_PORTINIT\
    P2SEL0 |= BIT0 | BIT1;\
    P2SEL1 &= ~(BIT0 | BIT1);   // Configure P2.0/P2.1 for USCI_A0 UART operation

// function
// MCU basic operation
void _noOperation();
void _MCU_LPMSet_(void(*ptr)());
void _MCU_PxInterruptSet_(uchar portName,uint portBit,uint portIES,void(*interruptFunction)());
void _MCU_T0Delay_(uint time);
// UCA0 UART operation
void _UCA0_UARTInit_();
void _UCA0_UARTWrite_(char* txBuff);
void _UCA0_UARTRead_(char* rxBuff);
// UCA1 UART operation
void _UCA1_UARTInit_();
void _UCA1_UARTWrite_(char* txBuff);
void _UCA1_UARTRead_(char* rxBuff);
// UCB0 I2C operation
void _UCB0_I2CInit_();
void _UCB0_I2CAddress_(uchar address);
void _UCB0_I2CWrite_(uchar* writeData, uint dataL);
void _UCB0_I2CRead_(uchar* readData, uint dataL);
// ADC12 operation
void _ADC12_AVCCInit_();
void _ADC12_Close_();
void _ADC12_Open_();

#endif /* MSP430FR6989_LANCHPAD_H_ */
