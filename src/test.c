// Standard Includes fuer das Funktionieren des Nibo2
#include <nibo/niboconfig.h>
#include <nibo/iodefs.h>
#include <nibo/bot.h>

// Bibliothek zum Ansteuern des Display
#include <nibo/display.h>

// Bibliothek mit Grafikfunktionen
#include <nibo/gfx.h>

// Wartefunktionen
#include <nibo/delay.h>

// Coprozessorfunktionen einbinden, da dieser die Motoren steuert
#include <nibo/copro.h>

// Kommunikationsfunktionen fuer die SPI Schnittstelle zum Coprozessor
#include <nibo/spi.h>

// Interrupts fuer die Kommunikation mit dem Coprozessor
#include <avr/interrupt.h>

// Ein- und Ausgabefunktionen
#include <stdio.h>

#include "pflicht.h"

void init() {

	// Aktivierung von Interrupts
	sei();

	// Initialisierung des Roboters (immer noetig)
	bot_init();

	// Initialisierung der SPI Schnittstelle
	spi_init();

	// initialisiert das Display und die Grafikfunktionen
	display_init();
	gfx_init();
}

int main() {

	init();

	// Endlosschleife
	while (1 == 1) {

		//stop
		copro_setSpeed(0, 0);
		getMovement(0, 0);
		delay(10000);

		// ROTATION_LEFT BACKWARD
		copro_setSpeed(-3, 3);
		getMovement(-3, 3);
		delay(10000);

		//ROTATION_RIGHT BACKWARD
		copro_setSpeed(3, -3);
		getMovement(3, -3);
		delay(10000);

		//FORWARD LEFT
		copro_setSpeed(6, 3);
		getMovement(6, 3);
		delay(10000);

		//FORWARD RIGHT
		copro_setSpeed(3, 6);
		getMovement(3, 6);
		delay(10000);

		//FORWARD STRAIGHT
		copro_setSpeed(3, 3);
		getMovement(3, 3);
		delay(10000);

		//BACKWARD STRAIGHT
		copro_setSpeed(-3, -3);
		getMovement(-3, -3);
		delay(5000);

		//BACKWARD RIGHT
		copro_setSpeed(-3, -6);
		getMovement(-3, -6);
		delay(10000);

		//BACKWARD LEFT
		copro_setSpeed(-6, -3);
		getMovement(-6, -3);
		delay(10000);



		// ROTATION_LEFT FORWARD
		copro_setSpeed(-1, 10);
		getMovement(-3, 3);
		delay(10000);

		//ROTATION_RIGHT FORWARD
		copro_setSpeed(10, -1);
		getMovement(3, -3);
		delay(10000);

	}
}

