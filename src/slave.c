#include "n2sound.h"

enum {
	RED, ORANGE, GREEN
};

typedef struct {
	char name[] = "C4";
	int frequence = C4;
	uint16_t initMessage = 0xAAAA;
	int distanceSensor[2] = { -1, 0 };
int led[2][2] =;
}c;

typedef struct {
	char name[] = "C SHARP";
	int frequence = C4SHARP;
	uint16_t initMessage = 0xBAAA;
	int distanceSensor[2] = { 0, 1 };
int led[] =;
}cSharp;

typedef struct {
	char name[] = "D4";
	int frequence = D4;
	uint16_t initMessage = 0xCAAA;
	int distanceSensor[2] = { -1, 1 };
int led[] =;
}d;

typedef struct {
	char name[] = "D4 SHARP";
	int frequence = D4SHARP;
	uint16_t initMessage = 0xDAAA;
	int distanceSensor[2] = { 1, 4 };
int led[] =;
}dSharp;

typedef struct {
	char name[] = "E4";
	int frequence = E4;
	uint16_t initMessage = 0xEAAA;
	int distanceSensor[2] = { -1, 2 };
int led[] =;
}e;

typedef struct {
	char name[] = "F4";
	int frequence = F4;
	uint16_t initMessage = 0xFAAA;
	int distanceSensor[2] = { -1, 3 };
int led[] =;
}f;

typedef struct {
	char name[] = "F4 SHARP";
	int frequence = F4SHARP;
	uint16_t initMessage = 0xBBBB;
	int distanceSensor[2] = { 0, 2 };
int led[] =;
}fSharp;

typedef struct {
	char name[] = "G4";
	int frequence = G4SHARP;
	uint16_t initMessage = 0xABBB;
	int distanceSensor[2] = { -1, 4 };
int led[] =;
}g;

typedef struct {
	char name[] = "G4 SHARP";
	int frequence = G4SHARP;
	uint16_t initMessage = 0xCBBB;
	int distanceSensor[2] = { 2, 4 };
int led[] =;
}gSharp;

typedef struct {
	char name[] = "A4";
	int frequence = A4;
	uint16_t initMessage = 0xDBBB;
	int distanceSensor[2] = { 0, 3 };
int led[] =;
}a;

typedef struct {
	char name[] = "A4 SHARP";
	int frequence = A4SHARP;
	uint16_t initMessage = 0xEBBB;
	int distanceSensor[2] = { 0, 4 };
int led[] =;
}aSharp;

typedef struct {
	char name[] = "B4";
	int frequence = B4;
	uint16_t initMessage = 0xFBBB;
	int distanceSensor[2] = { 1, 3 };
int led[] =;
}b;

int triad[11] = { C4, C4SHARP, D4, D4SHARP, E4, F4, F4SHARP, G4, G4SHARP, A4,
		A4SHARP, B4 }

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

	setLEDForSound(sound);
	setDisplayForSound(sound);
}

void playMasterSound() {

}

int getSound() {

}

void setLEDForSound(int sound) {

}

void setDisplayForSound(int sound) {

}
