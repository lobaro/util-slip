/*
 * slip.h
 *
 *  Created on: 19.12.2016
 *      Author: Tobias
 */

#ifndef SRC_UTIL_SLIP_SLIP_H_
#define SRC_UTIL_SLIP_SLIP_H_

#include "github.com/Lobaro/util-ringbuf/drv_ringbuf.h"

/* SLIP special character codes
 */
#define SLIP_END             0300    /* indicates end of packet */
#define SLIP_ESC             0333    /* indicates byte stuffing */
#define SLIP_ESC_END         0334    /* ESC ESC_END means END data byte */
#define SLIP_ESC_ESC         0335    /* ESC ESC_ESC means ESC data byte */

typedef struct {
	charRingBuf_t ringBuf;
	bool esc; // true if we got an esc char
	uint8_t packetCnt; // Number of packets in buffer
} slipBuffer_t;

void init_slip_buffer(slipBuffer_t* slip_buf, char* buf, int size);

void slip_uart_putc(slipBuffer_t* slip_buf, char c);

/* slip_recv_packet: reads a packet from buf into the buffer
 * located at "p". If more than len bytes are received, the
 * packet will be truncated.
 * Returns the number of bytes stored in the buffer.
 * Returns 0 if the buffer does not contain a full packet.
 */
int slip_read_packet(slipBuffer_t* buf, char *p, int len);
void slip_send_packet(char *p, int len, void (*send_char)(char c));

#endif /* SRC_UTIL_SLIP_SLIP_H_ */
