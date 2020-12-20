#include <wiringPi.h>

int main(){
	wiringPiSetup();
	
	pinMode(14, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	
	pinMode(0, INPUT);
	pullUpDnControl(0, PUD_UP);
	pinMode(2, INPUT);
	pullUpDnControl(2, PUD_UP);
	pinMode(3, INPUT);
	pullUpDnControl(3, PUD_UP);
	
	while(1){
		if (digitalRead(0))
			digitalWrite(14, LOW);
		else
			digitalWrite(14, HIGH);
		
		if (digitalRead(2))
			digitalWrite(12, LOW);
		else
			digitalWrite(12, HIGH);
		
		if (digitalRead(3))
			digitalWrite(13, LOW);
		else
			digitalWrite(13, HIGH);
	}
	
	return 0;
}