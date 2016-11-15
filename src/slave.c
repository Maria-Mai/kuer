#include "n2sound.h"

enum {
	RED, ORANGE, GREEN
};

typedef struct tone_t {
	char name[];
	int sound;
	uint16_t bitPattern;
	int distanceSensors[2];
	int led[2][2];
} tone;

int triad[11] = { C4, C4SHARP, D4, D4SHARP, E4, F4, F4SHARP, G4, G4SHARP, A4, A4SHARP, B4 };

void init() {

	tone *toneC4 = (tone*) malloc(sizeof(tone));
	toneC4->name = "C4";
	toneC4->sound = C4;
	toneC4->bitPattern = 0x0001;
	toneC4.distanceSensors[0] = -1;
	toneC4.distanceSensors[1] = 0;
	toneC4.led[0][0] = 7;
	toneC4.led[0][1] = GREEN;
	toneC4.led[1][0] = -1;
	toneC4.led[1][1] = -1;

	tone *toneC4Sharp = (tone*) malloc(sizeof(tone));
	toneC4Sharp.name = "C4 Sharp";
	toneC4Sharp.sound = C4SHARP;
	toneC4Sharp.bitPattern = 0x0002;
	toneC4Sharp.distanceSensors[0] = 0;
	toneC4Sharp.distanceSensors[1] = 1;
	toneC4Sharp.led[0][0] = 7;
	toneC4Sharp.led[0][1] = GREEN;
	toneC4Sharp.led[1][0] = 6;
	toneC4Sharp.led[1][1] = GREEN;

	tone *toneD4 = (tone*) malloc(sizeof(tone));
	toneD4.name = "D4";
	toneD4.sound = D4;
	toneD4.bitPattern = 0x0003;
	toneD4.distanceSensors[0] = -1;
	toneD4.distanceSensors[1] = 1;
	toneD4.led[0][0] = 7;
	toneD4.led[0][1] = GREEN;
	toneD4.led[1][0] = -1;
	toneD4.led[1][1] = -1;

	tone *toneD4Sharp = (tone*) malloc(sizeof(tone));
	toneD4Sharp->name = "D4 Sharp";
	toneD4Sharp.sound = D4SHARP;
	toneD4Sharp.bitPattern = 0x0004;
	toneD4Sharp.distanceSensors[0] = 1;
	toneD4Sharp.distanceSensors[1] = 4;
	toneD4Sharp.led[0][0] = 6;
	toneD4Sharp.led[0][1] = GREEN;
	toneD4Sharp.led[1][0] = 2;
	toneD4Sharp.led[1][1] = GREEN;

	tone *toneE4 = (tone*) malloc(sizeof(tone));
	toneE4.name = "E4";
	toneE4.sound = E4;
	toneE4.bitPattern = 0x0005;
	toneE4.distanceSensors[0] = -1;
	toneE4.distanceSensors[1] = 2;
	toneE4.led[0][0] = 4;
	toneE4.led[0][1] = GREEN;
	toneE4.led[1][0] = 5;
	toneE4.led[1][1] = GREEN;

	tone *toneF4 = (tone*) malloc(sizeof(tone));
	toneF4.name = "F4";
	toneF4.sound = F4;
	toneF4.bitPattern = 0x0006;
	toneF4.distanceSensors[0] = -1;
	toneF4.distanceSensors[1] = 3;
	toneF4.led[0][0] = 3;
	toneF4.led[0][1] = GREEN;
	toneF4.led[1][0] = -1;
	toneF4.led[1][1] = -1;

	tone *toneF4Sharp = (tone*) malloc(sizeof(tone));
	toneF4Sharp.name = "F4 Sharp";
	toneF4Sharp.sound = F4SHARP;
	toneF4Sharp.bitPattern = 0x0007;
	toneF4Sharp.distanceSensors[0] = 0;
	toneF4Sharp.distanceSensors[1] = 2;
	toneF4Sharp.led[0][0] = 5;
	toneF4Sharp.led[0][1] = ORANGE;
	toneF4Sharp.led[1][0] = 4;
	toneF4Sharp.led[1][1] = ORANGE;

	tone *toneG4 = (tone*) malloc(sizeof(tone));
	toneG4.name = "G4";
	toneG4.sound = G4;
	toneG4.bitPattern = 0x0008;
	toneG4.distanceSensors[0] = -1;
	toneG4.distanceSensors[1] = 4;
	toneG4.led[0][0] = 2;
	toneG4.led[0][1] = RED;
	toneG4.led[1][0] = -1;
	toneG4.led[1][1] = -1;

	tone *toneG4Sharp = (tone*) malloc(sizeof(tone));
	toneG4Sharp.name = "G4 Sharp";
	toneG4Sharp.sound = G4;
	toneG4Sharp.bitPattern = 0x0009;
	toneG4Sharp.distanceSensors[0] = 2;
	toneG4Sharp.distanceSensors[1] = 4;
	toneG4Sharp.led[0][0] = 0;
	toneG4Sharp.led[0][1] = RED;
	toneG4Sharp.led[1][0] = 1;
	toneG4Sharp.led[1][1] = RED;

	tone *toneA4 = (tone*) malloc(sizeof(tone));
	toneA4.name = "A4";
	toneA4.sound = A4;
	toneA4.bitPattern = 0x000A;
	toneA4.distanceSensors[0] = 0;
	toneA4.distanceSensors[1] = 4;
	toneA4.led[0][0] = 5;
	toneA4.led[0][1] = ORANGE;
	toneA4.led[1][0] = 4;
	toneA4.led[1][1] = ORANGE;

	tone *toneA4Sharp = (tone*) malloc(sizeof(tone));
	toneA4Sharp.name = "A4 Sharp";
	toneA4Sharp.sound = A4;
	toneA4Sharp.bitPattern = 0x000B;
	toneA4Sharp.distanceSensors[0] = 0;
	toneA4Sharp.distanceSensors[1] = 3;
	toneA4Sharp.led[0][0] = 7;
	toneA4Sharp.led[0][1] = GREEN;
	toneA4Sharp.led[1][0] = 3;
	toneA4Sharp.led[1][1] = GREEN;

	tone *toneB4 = (tone*) malloc(sizeof(tone));
	toneB4.name = "B4";
	toneB4.sound = B4;
	toneB4.bitPattern = 0x000C;
	toneB4.distanceSensors[0] = 1;
	toneB4.distanceSensors[1] = 3;
	toneB4.led[0][0] = 6;
	toneB4.led[0][1] = GREEN;
	toneB4.led[1][0] = 3;
	toneB4.led[1][1] = GREEN;
}

void playTriad(int rootNote, int pos) {

	int i = 0;

	while (rootNote != triad[i]) {
		i = (i + 1) % 11;
	}

	if (pos == 1) {
		for (int j = 0; j < 4; j++) {
			i = (i + 1) % 11;
		}
	} else {
		for (int j = 0; j < 7; j++) {
			i = (i + 1) % 11;
		}
	}

	tone(triad[i], 500);

	setLEDForSound(triad[i]);
	setDisplayForSound(triad[i]);
}

void playMasterSound() {

}

int getSound() {

	return 0;
}

void setLEDForSound(int sound) {

}

void setDisplayForSound(int sound) {

}
