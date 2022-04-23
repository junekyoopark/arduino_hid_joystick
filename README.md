# arduino_hid_joystick
Arduino Drone Controller using input from USB HID Joystick (VKBSim Gladiator NXT EVO)

## What this does
Transmits X, Y, Rudder, Throttle axis values from a USB Joystick (connected to a transmitter Arduino) to a receiver Arduino. 


## How this works

Using the [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0),
Tx (transmitter) parses X, Y, Rudder, Throttle values from USB Joystick HID Descriptor and sends them to Rx (receiver) using APC220 communications module (433MHz).

This repo is a very slight modification of "le3dp" example from [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0) so that it works with the VKBSim Gladiator NXT EVO Joystick.

Currently does not support button presses. If you would like to add this feature, go through the HID Descriptor (or you can check "HID Descriptor.txt" I uploaded; may not be accurate) and edit the "GamePadEventData" struct in "vkb.h" accordingly.

## How to use
Need 2 Arduinos, 2 APC220 Modules, 1 USB Host Shield

Assemble Arduino and USB Host shield. This Arduino runs the Tx. Just open "tx_vkb.ino" and flash it to the Arduino.
The other Arduino runs Rx. Open "rx.ino" and flash it to the Arduino.

and of course do not forget to assemble the APC220 modules.

Run the serial monitor on the Rx Arduino and you will see joystick values being streamed.

## Want to learn more?
I referred to these websites:

https://chome.nerpa.tech/category/mcu/arduino/usb-shield/hid/
https://www.tracesystemsinc.com/USB_Tutorials_web/USB/B1_USB_Classes/Books/A3_A_Closer_Look_at_HID_Class/slide01.htm
https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/

## Why?
This is for a personal / school club project.
