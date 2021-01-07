#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>

#define OP1 14
#define OP2 12
#define OP3 13

/* read two bytes from serial port
 * and build an integer value
 * resulting range [0..1023]
 */
int serialRead2(int fd){
    int byte, res = 0;
    for (int i = 0; i < 2; i++){
        if (serialDataAvail(fd) > 0){
            byte = serialGetchar(fd);
            // on atm side value is shifted right by 2
            // so here i shift it back
            res |= byte << (2 * i);
        }
    }
    return res;
}

static int fd;
int main(){
    wiringPiSetup();

    pinMode(OP1, OUTPUT);
    pinMode(OP2, OUTPUT);
    pinMode(OP3, OUTPUT);
    fd = serialOpen("/dev/ttyS2", 9600);

    int adc;
    while (1){
        if (serialDataAvail(fd) > 0){
            adc = serialRead2(fd);
            // adc = serialGetchar(fd);
            // printf("%d\n", adc);

            if (adc <= 341){
                digitalWrite(OP1, HIGH);
                digitalWrite(OP2, LOW);
                digitalWrite(OP3, LOW);
            }

            if ( (adc >= 342) && (adc <= 682) ){
                digitalWrite(OP1, LOW);
                digitalWrite(OP2, HIGH);
                digitalWrite(OP3, LOW);
            }

            if (adc >= 683){
                digitalWrite(OP1, LOW);
                digitalWrite(OP2, LOW);
                digitalWrite(OP3, HIGH);
            }
        }
    }

    return 0;
}