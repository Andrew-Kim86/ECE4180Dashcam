import RPi.GPIO as GPIO
import time
import io
import random
import picamera
import serial
from time import sleep


GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
C=picamera.PiCamera(resolution=(640,480))
stream = picamera.PiCameraCircularIO(C,seconds=10)
C.rotation=180
GPIO.setup(4,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(17,GPIO.IN,GPIO.PUD_UP)
GPIO.setup(27,GPIO.OUT)


def motion_detected():
    if GPIO.input(4)==0:
        return 1

   
   
i=0;
while True:
    if GPIO.input(17):
        print('On')
        GPIO.output(27,True)
        C.start_recording(stream,format='h264')
        while True:
            C.wait_recording(0.1)
            if motion_detected():
                C.wait_recording(5)
                stream.copy_to('%d.h264'% i)
                i+=1
                print(i)
                break
        C.stop_recording()
        print('Video saved')
    else:
        GPIO.output(27,False)
        print('Off')
        time.sleep(5)
