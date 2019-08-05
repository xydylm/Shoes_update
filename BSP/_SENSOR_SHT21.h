/*
 * _SENSOR_SHT21.h
 *
 *  Created on: 2017Äê8ÔÂ16ÈÕ
 *      Author: HR052
 */

#ifndef _SENSOR_SHT21_H_
#define _SENSOR_SHT21_H_

void _Sensor_SHT21_readTEM_(unsigned int* tem);
void _Sensor_SHT21_readHUM_(unsigned int* hum);
void _Sensor_SHT21_getTEM_(unsigned int* tem);
void _Sensor_SHT21_getHUM_(unsigned int* hum);

#endif /* _SENSOR_SHT21_H_ */
