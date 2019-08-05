/*
 * _PMM.h
 *
 *  Created on: 2019Äê2ÔÂ28ÈÕ
 *      Author: HR052
 */

#ifndef _PMM_H_
#define _PMM_H_

#define IO_D_H      P3OUT |= BIT0;
#define IO_CLK_H    P3OUT |= BIT1;
#define IO_D_L      P3OUT &= ~BIT0;
#define IO_CLK_L    P3OUT &= ~BIT1;

#define IO_SHORT    P2OUT |= BIT7;

#define _PMM_SHT21_VCC  P8OUT |= BIT5;
#define _PMM_SHT21_GND  P8OUT &= ~BIT5;

#define _PMM_ADC_VCC    P8OUT |= BIT6;
#define _PMM_ADC_GND    P8OUT &= ~BIT6;

#define _PMM_CC_VCC    P8OUT |= BIT7;
#define _PMM_CC_GND    P8OUT &= ~BIT7;

void _PMM_LP_Controll();
void _PMM_ALL_End_();

#endif /* _PMM_H_ */
