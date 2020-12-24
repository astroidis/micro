#include <wiringPi.h>

int main(){
	wiringPiSetup();
	// opi leds
	pinMode(14, OUTPUT);  // OP1
	pinMode(12, OUTPUT);  // OP2
	pinMode(13, OUTPUT);  // OP3
	// to atmega
	pinMode(0, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	
	while (1){
		for (int i = 0; i < 64; i++){
			if (i & 0x01)
				digitalWrite(13, HIGH);
			else
				digitalWrite(13, LOW);
			
			if (i & 0x02)
				digitalWrite(12, HIGH);
			else
				digitalWrite(12, LOW);
			
			if (i & 0x04)
				digitalWrite(14, HIGH);
			else
				digitalWrite(14, LOW);
			
			if (i & 0x08)
				digitalWrite(0, HIGH);
			else
				digitalWrite(0, LOW);
			
			if (i & 0x10)
				digitalWrite(2, HIGH);
			else
				digitalWrite(2, LOW);
			
			if (i & 0x20)
				digitalWrite(3, HIGH);
			else
				digitalWrite(3, LOW);
			
			delay(500);
		}
	}
	
	return 0;
}