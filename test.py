import serial
import hashlib

ser = serial.Serial('COM3', baudrate=115200, timeout=1)
fail = 0
success = 0

print("USB Serial Test v0.1")

while 1:
    testData = ser.readline()
    testData = testData.rstrip("\n\r")

    if not testData.startswith("SHA1:"):
        print(testData)
        m = hashlib.sha1()
        m.update(testData)
        hashString = "SHA1:" + m.hexdigest()
        print(hashString + " :: PY")
    else:
        print(testData + " :: PICO")
        if hashString == testData:
            success += 1
        else:
            fail += 1
        print("SUCCESS: {} FAIL: {}".format(success, fail))
    

        



