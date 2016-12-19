/*
 * slip.h
 *
 *  Created on: 19.12.2016
 *      Author: Tobias
 */

#ifndef SRC_UTIL_SLIP_SLIP_H_
#define SRC_UTIL_SLIP_SLIP_H_


int slip_recv_packet(char *p, int len, char (*recv_char)());
void slip_send_packet(char *p, int len, void (*send_char)(char c));




#endif /* SRC_UTIL_SLIP_SLIP_H_ */
