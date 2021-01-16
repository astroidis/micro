#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>
#include <unistd.h>

union {
    float f;
    char c[4];
} h, t;

char buf[8];

int main(){
    wiringPiSetup();

    int fdi2c = wiringPiI2CSetup(0x23);
    int fduart = serialOpen("/dev/ttyS2", 9600);

    while(1){
        read(fdi2c, buf, 8);

        for (int i = 0; i < 4; i++){
            h.c[i] = buf[i];
        }

        for (int i = 0; i < 4; i++){
            t.c[i] = buf[4 + i];
        }

        serialPrintf(fduart, "Humidity %f\n", h.f);
        serialPrintf(fduart, "Temperature %f\n\n", t.f);

        delay(2000);
    }
}
