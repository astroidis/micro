#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>

static int fd;

int main(){
	wiringPiSetup();

	pinMode(13, OUTPUT);
	fd = serialOpen("/dev/ttyS2", 9600);

	while (1){
        if (serialDataAvail(fd) > 0){
            if (serialGetchar(fd) != '0')
                digitalWrite(13, HIGH);
            else
                digitalWrite(13, LOW);
        }
	}

	return 0;
}