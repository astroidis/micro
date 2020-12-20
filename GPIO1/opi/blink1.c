#include <wiringPi.h>

int main(){
	wiringPiSetup();
	pinMode(14, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	
	while (1){
		digitalWrite(14, HIGH);
		delay(500);
		digitalWrite(12, HIGH);
		delay(500);
		digitalWrite(13, HIGH);
		delay(500);
		
		digitalWrite(14, LOW);
		digitalWrite(12, LOW);
		digitalWrite(13, LOW);
		delay(500);
	}
	
	return 0;
}