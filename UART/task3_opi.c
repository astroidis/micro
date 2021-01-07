#include <wiringPi.h>
#include <wiringSerial.h>
#include <time.h>

int main(){
    wiringPiSetup();
    
    int fd = serialOpen("/dev/ttyS2", 9600);
    time_t old, new;
    struct tm *curtime;
    
    time(&old);
    
    while (1){
        time(&new);
        curtime = localtime(&new);
        // add check for hour range (10-18)
        if (curtime->tm_wday > 0 && curtime->tm_wday < 6){
            if (difftime(new, old) >= 30){
                serialPutchar(fd, 1);
                old = new;
            }
        }
    }
    
    return 0;
}