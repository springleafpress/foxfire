int daylight = 3;
int sunset = 5;
int foxfire = 6;
int firefly1 = 2;
int firefly2[] = { 10, 9, 8, 7, 4 };
int fireflyLength = (sizeof(firefly2) / sizeof(int));
int brightness = 0;
int fadeAmount = 5;

void setup() {
	pinMode(firefly1, OUTPUT);
	for (int i = 0; i < fireflyLength; i++) {
		pinMode(firefly2[i], OUTPUT);
	}
}

void loop() {
	fadeIn(daylight);
	delay(3000);
	fadeIn(sunset);
	fadeOut(daylight);
	delay(3000);
	fadeOut(sunset);
	delay(3000);
	fadeIn(foxfire);
	delay(3000);
	runFirefly(firefly1, firefly2, fireflyLength);
	delay(3000);
	fadeOut(foxfire);
	delay(10000);
}

void blinkLED(int pin) {
	digitalWrite(pin, HIGH);
	delay(1000);
	digitalWrite(pin, LOW);
	delay(1000);
}

void blinkTwoLED(int pin1, int pin2) {
	digitalWrite(pin1, HIGH);
	digitalWrite(pin2, HIGH);
	delay(1000);
	digitalWrite(pin1, LOW);
	digitalWrite(pin2, LOW);
	delay(2000);
}

void runFirefly(int firefly, int *fireflyArray, int arrayLength) {
	int lastElement = arrayLength;
	for (int i = 0; i < arrayLength; i++) {
		blinkLED(firefly);
		delay(1000);
		blinkLED(fireflyArray[i]);
		delay(1000);
	}
	blinkTwoLED(firefly, fireflyArray[4]);
	blinkTwoLED(firefly, fireflyArray[4]);
	delay(4000);
}

void fadeIn(int pin) {
	float in, out;
	for (in = 4.712; in < 7.853; in = in + 0.0001) {
		out = sin(in) * 127.5 + 127.5;
		analogWrite(pin, out);
	}
}

void fadeOut(int pin) {
	float in, out;
	for (in = 1.570; in < 4.712; in = in + 0.0001) {
		out = sin(in) * 127.5 + 127.5;
		analogWrite(pin, out);
	}
}
