#include <wiringPi.h>
#include <time.h>

int main(){
	wiringPiSetup();
	pinMode(14, OUTPUT);
	
	time_t timer1, timer2;
	

	time(&timer1);
	while (1){
		time(&timer2);

		if (difftime(timer2, timer1) >= 60){
			timer1 = timer2;
			digitalWrite(14, HIGH);
			delay(10000);
			digitalWrite(14, LOW);
		}
	}
	
	return 0;
}
