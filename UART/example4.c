#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>

static int fd;
int mydata = 0;

int main(){
	wiringPiSetup();

	fd = serialOpen("/dev/ttyS2", 9600);

	while (1){
        serialPrintf(fd, "%d", mydata);
        mydata++;
	}

	return 0;
}