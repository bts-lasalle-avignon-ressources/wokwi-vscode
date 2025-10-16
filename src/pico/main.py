import time
import machine

time.sleep(0.1); # Wait for USB to become ready

ledVerte = machine.Pin(1, machine.Pin.OUT)
ledRouge = machine.Pin(2, machine.Pin.OUT)

while 1:
    ledRouge.on()
    time.sleep(1)
    ledRouge.off()
    time.sleep(1)

    ledVerte.on()
    time.sleep(1)
    ledVerte.off()
    time.sleep(1)
