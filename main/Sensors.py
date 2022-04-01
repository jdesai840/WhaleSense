import serial
import time
from time import sleep
import os
import datetime

gpsArduino = serial.Serial('COM5', 9600, timeout = .1)
lidarArduino = serial.Serial('COM6', 9600, timeout = .1)

file = open("/home/pi/whalesense_data_log.csv", "a")

if os.stat("home/pi/data_log.csv").st_size == 0:
    file.write("Time", "GPS data", "Camera Pitch", "Camera Yaw", "LiDAR Distance", "LiDAR Angle\n")

pointsLogged = 0
maxPoints = 100000 #can be adjusted depending on desired data point limit

while pointsLogged < maxPoits:
    pointsLogged += 1
    gps = gpsArduino.readline()
    lidar = lidarArduino.readline()
    time = datetime.now()
    file.write(str(time)+","+str(gps)+","+str(gps)+","+str(gps)+","+str(lidar)+","+str(lidar)+"\n")
    file.flush()
    time.sleep(1)
    
 file.close()

