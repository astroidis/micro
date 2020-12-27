#include <wiringPi.h>

#define TACT 20000
#define PULSE_LEFT 1000
#define PULSE_CENTER  1500
#define PULSE_RIGHT 2000
#define OP1 14
#define OP2 12
#define OP3 13


void servoState(int pulse, int led){
	digitalWrite(led, HIGH);
	for (int i = 0; i < 50; i++){
		digitalWrite(7, HIGH);
		delayMicroseconds(pulse);
		digitalWrite(7, LOW);
		delayMicroseconds(TACT - pulse);
	}
	digitalWrite(led, LOW);
}

int main(){
	wiringPiSetup();
	
	pinMode(7, OUTPUT);
	pinMode(OP1, OUTPUT);
	pinMode(OP2, OUTPUT);
	pinMode(OP3, OUTPUT);
	
	while (1){
		servoState(PULSE_LEFT, OP1);
		servoState(PULSE_CENTER, OP2);
		servoState(PULSE_RIGHT, OP3);
	}
	
	return 0;
}