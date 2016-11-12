/*
 ============================================================================
 Name        : nxb2.c
 Author      : Daniel Wittekind
 Version     : 1.0
 Description : Funktionen fuer die Nutzung des NXB2 Moduls
 ============================================================================
 */

#define NIBO_USE_UART0

#ifndef NXB2_H_
#define NXB2_H_

#include "uart0.h"

// amount of bytes in message, payload is smaller by 2
// set to 4 - byte 0: start symbol, byte 1: payload low Byte, byte 2: payload high byte, byte 3: end symbol
#define MESSAGE_SIZE 4

// start symbol = !
#define START_SYMBOL 0x21

// end symbol = ?
#define END_SYMBOL 0x3F

// initialize serial comm
void nxb2_init();

// disable serial comm
void nxb2_disable();

/*
 * get message from xbee
 */
uint16_t getXBeeMessage();

/*
 * send unsigned integer
 */
void sendXBeeMessage(uint16_t message);

#endif /* NXB2_H_ */
