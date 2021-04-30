
# ECE4180Dashcam
#### by Andrew Kim and Sidong Guo

## Introduction
A dashboard camera is an in-car camera that records video for security and documentation. This project was designed and built for the final design project in Embedded Systems Design (ECE4180) at Georgia Tech by Andrew Kim and Sidong Guo. The project uses an Mbed and Raspberry PI4 based dashcam that streams continously, saves videos, and alerts during incidents. 

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
| p5   |     |               |       |       |
| p9   | Rx  |               |       |       |
| p10  | Tx  |               |       |       |
| p11  | Res |               |       |       |
| p26  |     |               | SHDN  |       |
| p27  |     | SCL           | SCL   |       |
| p28  |     | SDA           | SDA   |       |
| 3.3V |     | 3.3V          | Vin   |       |
| 5V   | 5V  |               |       |       |
| GND  | GND |               | GND   |       |

## Project Details
A switch indicates whether the car is ON or OFF. When the car is ON, and accelerometer experiences an abrupt change in velocity pertaining to a brake or an incident, a signal will be sent to the PI4. During the OFF state, if the car experiences a slight change in velocity or when the motion detector senses an approaching vehicle or human, indicating a displacement or potential incident, a signal will be sent to the PI4. Meanwhile, a speaker will make an alert and the LCD will indicate the number of incidents occured and other relevant information. A second switch controls if the camera module is ON or OFF, during ON state, camera records in a continuous stream, whenever a signal is detected from Mbed, the camera will save the previous 30 and next 30 seconds as a 1 min video which will likely include the occurrence of the incident. Each signal will create a separate video file. 
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
