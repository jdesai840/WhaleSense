import cv2 as cv
from time import sleep
import serial
import os
import pyaudio
import wave

# Thermal camera capture

cv.namedWindow("Thermal Sensor Data")
cameraID = 0
vc = cv.VideoCapture(cameraID)

if vc.isOpened():
    rval, frame = vc.read()
else:
    rval = False
    
while rval:
    frame_hsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    frame_v=frame_hsv[:,:,2]
    cv.imshow("Thermal Sensor Data", frame_v)
    rval,frame = vc.read()
    key = cv.waitKey(20)
    if key == 27:
        break
