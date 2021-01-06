#include <wiringPi.h>
#include <wiringSerial.h>
#include <stdio.h>

#define OP1 14
#define OP2 12
#define OP3 13

// void serialRead(int fd, int *res){
    // int byte;
    // for (int i = 0; i < 2; i++){
        // if (serialDataAvail(fd) > 0){
            // byte = serialGetchar(fd);
            // *res += byte << (8 * i);
        // }
    // }
// }

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
            // serialRead(fd, &adc);
            adc = serialGetchar(fd);
            // printf("%d\n", adc);
            // getchar();
            
            if (adc <= 85){
                digitalWrite(OP1, HIGH);
                digitalWrite(OP2, LOW);
                digitalWrite(OP3, LOW);
            }

            if ( (adc >= 86) && (adc <= 171) ){
                digitalWrite(OP1, LOW);
                digitalWrite(OP2, HIGH);
                digitalWrite(OP3, LOW);
            }

            if (adc >= 172){
                digitalWrite(OP1, LOW);
                digitalWrite(OP2, LOW);
                digitalWrite(OP3, HIGH);
            }
        }
    }

    return 0;
}