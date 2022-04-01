import serial
import time

gpsArduino = serial.Serial('COM5', 9600, timeout = .1)
LiDARArduino = serial.Serial('COM6', 9600, timeout = .1)

gpsData = []
LiDARArduino = []
timeData = []

while True:
    gps = gpsArduino.readline()
    LiDAR = LiDARArduino.readline()
    if gps:
        gpsData.append(float(gps)) # Append a data to your declared list
        print gpsData
    if LiDAR:
        LiDARData.append(float(gps)) # Append a data to your declared list
        print gpsData
