#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>

int main(){
    wiringPiSetup();
    int fdi2c = wiringPiI2CSetup(0x23);
    int fduart = serialOpen("/dev/ttyS2", 9600);
    int data;
    
    while(1){
        data = wiringPiI2CRead(fdi2c);
        serialPrintf(fduart, "%d\n", data);
        delay(1000);
    }
}