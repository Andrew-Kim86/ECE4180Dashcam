
# Mbed and Pi Dashcam
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
* SPST DIP switch
* MMA8452 Accelerometer

## PIN connections
### Raspberry Pi Peripherals 
<img src="https://user-images.githubusercontent.com/82831509/116631723-8f6a7400-a923-11eb-97dc-e1964e7295b3.jpg" alt="PI" style="width:300px;"/>
<p>Camera Module and one signal pin in connected to the pi as well as supporting power supply and display.</p>

|Raspberry Pi|            |
|------------|------------|
|  GPIO 4    | Mbed P6    | 
|  GPIO 17   | DIP switch |
|  GPIO 27   | RGB LED    |
<p></p>

### MBED Peripherals
<img src="https://user-images.githubusercontent.com/82831509/116728394-da33cc80-a9b3-11eb-926d-bfd39d7cca04.jpg" alt="Project" style="width:3
00px;"/>
<p>Mbed connected to all other peripherals and PI.</p>
<br>

#### LCD
|Mbed  | LCD |
|----- |-----|
| p9   | Rx  |
| p10  | Tx  |
| p11  | Res |
| 5V   | 5V  |
| GND  | GND |
<br>

#### Accelerometer and LIDAR
|Mbed  |Accelerometer | Lidar |
|----- |--------------|-------|
| p27  |SCL           | SCL   |
| p28  |SDA           | SDA   |
| 3.3V |3.3V          | Vin   |
| GND  | GND          | GND   |
<p>SCL and SDA need pullup resistor of 4.7k ohm</p>
<br>

#### Speaker
|Mbed  | TPA2005D1 |
|----- |-----------|
| p21  | in+       |
| 5V   | pwr+      |
| GND  | pwr-, in- |
<br>

#### Other
|Mbed  | Pi    | On/Off |
|------|-------|--------|
| p5   |       | DIP1   |
| p6   | GPIO4 |        |

## Project Details
<p>A DIP switch is being used in this demonstration to indicate whether the car is ON or OFF. When the car is off, the dashcamera will wait for either a slight acceleration (if the car is hit lightly while parked) or if the LIDAR detects an object close (if someone/something is near the car). A sound is played when an incident occurs. The mbed detects and keeps track of these incidents, updates the LCD, and sends a signal to the PI to save a couple seconds of video. When the car is on, the LIDAR is disabled, and when a large acceleration occurs (as if in an accident or hard breaking) a traffic incident is recorded and a sound is played. The incident number is updated, the LCD is updated, and a signal is sent to the PI to save video. Additionally, the mbed keeps track of the total number of videos recorded and displays them on the LCD.</p>

<p>In this demonstration version of the dashcam, the PI and mbed are connected to a PC. Additionally the PI is connected to the PC to display the video. In a completed project, the PI and mbed would need to be connected to car power and the car state would need to be connected to an electrical item in the car that is only on when the car is on such as a 12V jack. Some packaging would have to be done to make it more compact. Other modification include increasing the threshold for the acceleration and LIDAR sensors to be more inline with the actual incidents. Video length can also be modified. The SD in the PI would need to be removed to view the video.</p>

## Video Demonstration

<p>https://youtu.be/YxSZItViBIs</p>

## Pi Setup Instructions
* Boot Raspberry Pi 4 with [PI4 Set up](https://www.raspberrypi.org/documentation/installation/installing-images/README.md)
* Open terminal and enter the following command (Picamera should come pre-installed) 
* sudo apt-get update
* sudo apt-get install python-picamera python3-picamera
* Load the dashcam.py with Python3 
[Python Picamera Module](https://picamera.readthedocs.io/en/release-1.13/recipes1.html#recording-to-a-circular-stream)
* Import the Mbed codes into your program
* Connect all related Modules, refer to 'PIN connections'
* Press Start on LPC1768 Mbed 
