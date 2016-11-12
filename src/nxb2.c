/*
 ============================================================================
 Name        : nxb2.c
 Author      : Daniel Wittekind
 Version     : 1.0
 Description : Funktionen fuer die Nutzung des NXB2 Moduls
 ============================================================================
 */

#include <nibo/niboconfig.h>

// delay
#include <nibo/delay.h>

// graphics
#include <nibo/display.h>
#include <nibo/gfx.h>

// interrups
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdio.h>

// serial comm
#include "uart0.h"

// headerfile
#include "nxb2.h"

// initalize the serial interface to xbee
void nxb2_init() {
	uart0_set_baudrate(9600);
	uart0_enable();
}

// receive an unsigned integer, 0 if nothing new was received
uint16_t getXBeeMessage() {

	// check for new data
	if (!uart0_rxempty()) {

		uint16_t message = 0;

		// make buffer
		char buf[MESSAGE_SIZE];

		// counter
		int i = 0;

		// get every byte of reception buffer
		for (i = 0; i < MESSAGE_SIZE; i++) {
			// get single received byte
			buf[i] = uart0_getchar();
		}

		/*
		 * check whether message is complete, check for start and end symbol
		 */
		if ((buf[0] == START_SYMBOL) && (buf[MESSAGE_SIZE - 1] == END_SYMBOL)) {

			// high Byte hochschieben und low Byte anhaengen
			message = buf[2] << 8 | buf[1];

			return message;
		}
		return message;

	} else
		return 0;
}

// sends an unsigned integer
void sendXBeeMessage(uint16_t message) {

	// buffer
	char buf[MESSAGE_SIZE];

	// Ein- und Ausgabesymbol festlegen
	buf[0] = START_SYMBOL;
	buf[3] = END_SYMBOL;

	// low byte of message
	buf[1] = message & 0x00FF;

	// high byte of message
	buf[2] = message & 0xFF00;

	uart0_txbuf_begin = 0;

	for(int i = 0; i < MESSAGE_SIZE; i++){
		uart0_putchar(buf[i]);
		delay(1);
	}

	delay(5);
}
