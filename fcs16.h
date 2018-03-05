/*
 * fcs16.h
 *
 *  Created on: 04.07.2017
 *      Author: Tobias
 */

#ifndef UTIL_SLIP_FCS16_H_
#define UTIL_SLIP_FCS16_H_


uint16_t CalcFcs16(const uint8_t* data, size_t len) ;
uint16_t CalcFcs16WithInit(uint16_t fcs, const uint8_t* data, size_t len);
bool CheckFsc16(uint8_t* data, size_t len);

void Test_Fcs16();

#endif /* UTIL_SLIP_FCS16_H_ */
