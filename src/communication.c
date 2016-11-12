void initCommunication() {

	while (1 == 1) {
		uint16_t input = getXBeeMessage();
		if (input == initMessage) {
			break;
		}
	}

	// send id every 100
	while (1 == 1) {
		myId = rand() % 255;
		uint16_t message = (myId << 8) | 0x00;
		sendXBeeMessage(message);
		delay(100);
		uint16_t input = getXBeeMessage();
		if (input == shutupMessage) {
			break;
		}
	}
}


