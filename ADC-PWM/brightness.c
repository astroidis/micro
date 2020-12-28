#include <wiringPi.h>

#define OP1 14
#define OP2 12
#define TACT 3000
#define DELTA 100
#define STEPS TACT/DELTA

int main(){
	wiringPiSetup();
	
	pinMode(OP1, OUTPUT);
	pinMode(OP2, OUTPUT);
	
	while (1){
		for (int i = 0; i <= STEPS; i++){
			for (int j = 0; j < 50; j++){
				digitalWrite(OP1, HIGH);
				digitalWrite(OP2, LOW);
				delayMicroseconds(i * DELTA);
				
				digitalWrite(OP1, LOW);
				digitalWrite(OP2, HIGH);
				delayMicroseconds(TACT - i * DELTA);
			}
		}
		
		for (int i = 0; i <= STEPS; i++){
			for (int j = 0; j < 50; j++){
				digitalWrite(OP1, LOW);
				digitalWrite(OP2, HIGH);
				delayMicroseconds(i * DELTA);
				
				digitalWrite(OP1, HIGH);
				digitalWrite(OP2, LOW);
				delayMicroseconds(TACT - i * DELTA);
			}
		}
	}
	
	return 0;
}