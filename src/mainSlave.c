/**
 * @file slave.c
 * @author Maria Hinsche
 * @brief programm for the slave
 */

// standard Nibo2 includes
#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>

// display functions
#include <nibo/display.h>

// graphics library
#include <nibo/gfx.h>

// delay
#include <nibo/delay.h>

// library for Nibo2 co-processor
#include <nibo/copro.h>

// SPI communication library
#include <nibo/spi.h>

// microcontroller hardware interrupts
#include <avr/interrupt.h>

// input - output funtions
#include <stdio.h>
// interrupts
#include <stdint.h>
// random
#include <stdlib.h>

// nxb2/xbee communication functions
#include "nxb2.h"
// serial communication functions
#include "uart0.h"

#include "communication.h"

#include "slave.h"

int main() {

	// enable interrupts
	sei();

	// initialize robot (always)
	bot_init();

	// initialize spi
	spi_init();

	// initialize display and graphic functions
	display_init();
	gfx_init();

	// initialize xbee communications
	nxb2_init();

	char myId = -1;
	int myPos = -1;
	int sound = -1;

	while (1) {

		//init process finishes
		if (myId != -1 && myPos != -1) {

			//setPosition
			uint16_t input = getXBeeMessage();
			if ((input) >> 8 == myId) {
				myPos = input << 8;
			}

			sound = getSound();

			//play triad
			if(triad == 1){
				playTriad(sound);
			}
			//play master sound
			else{
				playMasterSound(sound);
			}

		}
		//do init process
		else {

			initCommunication();
		}
	}

	return 0;
}

