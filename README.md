# arduino_hid_joystick
Arduino Drone Controller using input from USB HID Joystick

## What it does
Tx parses X, Y, Rudder, Throttle values from USB Joystick HID Descriptor and sends them to Rx using APC220 communications module (433MHz).

Very slight modification of "le3dp" example from https://github.com/felis/USB_Host_Shield_2.0 so that it works with VKBSim Gladiator NXT Evo.

Currently does not support button presses. If you would like to add this features, go through the HID Descriptor and edit the GamePadEventData struct in vkb.h accordingly.


## How to use
Need 2 Arduinos, 1 USB Host Shield

Assemble Arduino and USB Host shield. This Arduino runs the Tx. Just open tx_vkb.ino and flash it to the Arduino.
The other arduino runs Rx. Open rx.ino and flash it to the Arduino.
Run the serial monitor on the Rx Arduino and you will see joystick values being streamed.

## Why?
This is for a personal / school club project.
