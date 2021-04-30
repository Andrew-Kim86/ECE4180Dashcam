
# ECE4180Dashcam
#### by Andrew Kim and Sidong Guo

## Introduction
A dashboard camera is an in-car camera that records continously interiors or surroundings to provide reliable 24/7 surveillance, the goal of the project is to build a Mbed and Raspberry PI4 based dashcam that streams continously, saves videos and alerts during incidents. 

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
* Pushbuttons 

## PIN connections
Raspberry Pi Peripherals 
![MBED](https://user-images.githubusercontent.com/82831509/116631723-8f6a7400-a923-11eb-97dc-e1964e7295b3.jpg)

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

## Project Details

## Video Demonstration

## Setup Instructions
* Boot Raspberry Pi 4 with [PI4 Set up](https://www.raspberrypi.org/documentation/installation/installing-images/README.md)
* Open terminal and enter the following command (Picamera should come pre-installed) 
* sudo apt-get update
* sudo apt-get install python-picamera python3-picamera
* Load the dashcam.py with Python3 
[Python Picamera Module](https://picamera.readthedocs.io/en/release-1.13/recipes1.html#recording-to-a-circular-stream)
* Import the Mbed codes into your program
* Connect all related Modules, refer to 'PIN connections'
* Press Start on LPC1768 Mbed 
* Use the DIP switch to control whether Camera Stream is on or off and the state of the car
