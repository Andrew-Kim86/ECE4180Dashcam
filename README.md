# ECE4180Dashcam
#### by Andrew Kim and Sidong Guo

## Description

## Components
* LPC1768 Mbed 
* Raspberry PI 4 
* Raspberry PI Camera Module V2
* USB-C Power Supply (DCAR-RSP-3A5C)
* 16G uSD with Raspbian OS 
* HDMI cable
* uLCD-144-G2
* Sparkfun PCB Speaker 
* Sparkfun Class D audio amplifier 
* LIDAR TOF Distance Sensor
* RGB LED
* SPST DIP switch
* ADXL345 Accelerometer

## PIN connections
Raspberry Pi Peripherals 
|Raspberry Pi|      |
|------------|------|
|  GPIO 4    | Mbed P?| 
|  GPIO 17   | DIP switch |
|  GPIO 27   | RGB LED    |
| 3.3V       |      |
| gnd        |      |

Mbed Peripherals
|Mbed  | LCD | Accelerometer | Lidar |Speaker|
|----- |-----|---------------|-------|-------|
|  p28 | Rx  |               |       ||
|  p27 | Tx  |               |       ||
|  p30 | Res |               |       ||
|      |     |               |       ||
|      |     |               |       ||
| 5V   | 5V  |               |       ||
| gnd  | gnd |               |       ||
