#include "mbed.h"
#include "rtos.h"
#include "uLCD_4DGL.h"
#include "MMA8452.h"
#include "XNucleo53L0A1.h"
#include "speaker.h"
#include <stdio.h>

#define VL53L0_I2C_SDA   p28
#define VL53L0_I2C_SCL   p27

uLCD_4DGL uLCD(p9,p10,p11);
Serial pc(USBTX,USBRX);
MMA8452 acc(p28, p27, 9600);
Speaker mySpeaker(p21);
static XNucleo53L0A1 *board=NULL;
DigitalOut shdn(p26);
Mutex i2c;

double ax, ay, az;
int status;
uint32_t distance;

int numOfPark;
int numOfAcc;
int numOfVideos;

void display()
{
    i2c.lock();
    uLCD.cls();
    uLCD.printf("Parking Incidents:\n%d\n", numOfPark);
    uLCD.printf("Traffic Incidents:\n%d\n", numOfAcc);
    uLCD.printf("Number of Videos:\n%d\n", numOfVideos);
    i2c.unlock();
}

void pulse(void const *argument)
{
    while(1)
    {
        i2c.lock();
        acc.readXYZGravity(&ax,&ay,&az);
        i2c.unlock();
        if(ax>1 || ay > 1)
        {
            mySpeaker.PlayNote(969.0, 0.5, 1.0);
        }
        pc.printf("x:%lf   y:%lf z:%lf\r\n",ax,ay,az);
        Thread::wait(50);
    }
}

int main() {
    uLCD.cls();
    numOfPark = 0;
    numOfAcc = 0;
    numOfVideos = 0;
    display();
    //acc.setDynamicRange(DYNAMIC_RANGE_8G);
    int status;
    uint32_t distance;
    DevI2C *device_i2c = new DevI2C(VL53L0_I2C_SDA, VL53L0_I2C_SCL);
    /* creates the 53L0A1 expansion board singleton obj */
    board = XNucleo53L0A1::instance(device_i2c, A2, D8, D2);
    shdn = 0; //must reset sensor for an mbed reset to work
    wait(0.1);
    shdn = 1;
    wait(0.1);
    /* init the 53L0A1 board with default values */
    status = board->init_board();
    while (status) {
        //pc.printf("Failed to init board! \r\n");
        status = board->init_board();
    }
    //Thread thread1(display);
    //Thread thread2(pulse);
    while (1) {
        i2c.lock();
        status = board->sensor_centre->get_distance(&distance);
        i2c.unlock();
        if (status == VL53L0X_ERROR_NONE) {
            if(distance != 0 && distance < 100)
            {
                pc.printf("D=%ld mm\r\n", distance);
                numOfPark++;
                //display();
                wait(15);
            }
        }
        Thread::wait(500);
    }
}
