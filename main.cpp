#include "mbed.h"
#include "rtos.h"
#include "uLCD_4DGL.h"
#include "MMA8452.h"
#include "VL53L0X.h"
#include "speaker.h"
#include <stdio.h>

#define VideoLength 1

Serial pc(USBTX,USBRX);
uLCD_4DGL uLCD(p9,p10,p11);
MMA8452 acc(p28, p27, 40000);
DevI2C i2c(p28, p27);
DigitalOut shdn(p26);
VL53L0X sensor(&i2c, &shdn, NC);
DigitalIn power(p5);

//Data
double ax, ay, az;
int numOfPark;
int numOfAcc;
int numOfVideos;
 
void display()
{
    uLCD.locate(0,1);
    uLCD.printf("Parking Incidents:%d\n\n", numOfPark);
    uLCD.printf("Traffic Incidents:%d\n\n", numOfAcc);
    uLCD.printf("Number of Videos: %d\n\n", numOfVideos);
}
 
int main() {
    numOfPark = 0;
    numOfAcc = 0;
    numOfVideos = 0;
    display();
    
    //Hardware
    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_400);
    sensor.VL53L0X_off();
    sensor.init_sensor(0x30);
    sensor.VL53L0X_on();
    uint32_t distance;
    while(1) {
        //Get data
        int status = sensor.get_distance(&distance);
        if(!acc.isXYZReady()) {
            wait(0.01);
            continue;
        }
        acc.readXYZGravity(&ax,&ay,&az);
        //Process
        if (power == 1)
        {
            if(abs(ax) >= 1.5 || abs(ay) >= 1.5 || abs(az-1) >= 1.5)
            {
                pc.printf("AccTrigDrive %lf %lf %lf\n", ax, ay, az);
                numOfAcc++;
                numOfVideos++;
                display();
                wait(VideoLength);
            }
        }
        else
        {
            if(abs(ax) >= 1 || abs(ay) >= 1)
            {
                pc.printf("AccTrigPark\n");
                numOfPark++;
                numOfVideos++;
                display();
                wait(VideoLength);
            }
            else
            {
                if (status == VL53L0X_ERROR_NONE && distance <= 100) 
                {
                    pc.printf("VL53L0X [mm]:            %6ld\r\n", distance);
                    numOfPark++;
                    numOfVideos++;
                    display();
                    wait(VideoLength);
                }
            } 
        }
        wait(0.1);
    }
}