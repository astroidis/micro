#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <wiringSerial.h>
#include <stdio.h>

union Data{
    float f;
    char c[4];
} h, t;

void read4(int fd, union Data *buf){
    char b;
    for (int i = 0; i < 4; i++){
        b = wiringPiI2CRead(fd);
        printf("read %d\n", b);
        buf->c[i] = b;
    }
    printf("\n");
}

int main(){
    wiringPiSetup();
    int fdi2c = wiringPiI2CSetup(0x23);
    int fduart = serialOpen("/dev/ttyS2", 9600);

    while(1){
        wiringPiI2CWrite(fdi2c, 0);
        delay(1000);

        wiringPiI2CWrite(fdi2c, 1);

        read4(fdi2c, &h);
        //read4(fdi2c, &t);

        serialPrintf(fduart, "%f\n", h.f);
        //serialPrintf(fduart, "%f\n", t.f);

        delay(2000);
    }
}