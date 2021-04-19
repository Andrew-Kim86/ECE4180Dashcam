#include "mbed.h"
#include "uLCD_4DGL.h"
#include "MMA8452.h"

uLCD_4DGL uLCD(p9,p10,p11);
Serial pc(USBTX,USBRX);
MMA8452 acc(p28, p27, 100000);

DigitalOut myled(LED1);

int main() {
    while(1) {
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}
