#include <wiringPi.h>
#include <wiringPiI2C.h>

int main(){
    wiringPiSetup();
    
    int fd = wiringPiI2CSetup(0x23);
    
    while(1){
        for (int i = 0; i < 10; i++){
            wiringPiI2CWrite(fd, i);
            delay(1000);
        }
    }
}