#include <wiringPi.h>
#include <time.h>

int main(){
	wiringPiSetup();
	pinMode(14, OUTPUT);
	
	time_t timer;
	struct tm *tm_ptr;
	
	while (1){
		time(&timer);
		tm_ptr = gmtime(&timer);
		
		if ((tm_ptr->tm_hour > 19) && (tm_ptr->tm_hour < 23))
			digitalWrite(14, HIGH);
		else
			digitalWrite(14, LOW);
	}
	
	return 0;
}