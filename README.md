# arduino_hid_joystick
Arduino Drone Controller using input from USB HID Joystick (VKBSim Gladiator NXT EVO)

## What this does
Sends X, Y, Rudder, Throttle axis values from a USB Joystick to a RC Transmitter.

A version that sends axis values from an Arduino to another Arduino is archived inside the "nrf" folder. Those files utilize 2 Arduino Unos and 2 nRF24L01 modules. That version was archived due to connection issues with the nRF24L01 modules.

## How this works

Using the [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0),
Tx (transmitter) parses X, Y, Rudder, Throttle values from USB Joystick HID Report into a PPM signal and sends them to a FlySky FS-i6 RC Transmitter set in "Trainer Mode". 

This repo is a very slight modification of "le3dp" example from [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0) so that it works with the VKBSim Gladiator NXT EVO Joystick.

Currently does not support button presses. If you would like to add this feature, go through the HID Report Descriptor (or you can check "HID Descriptor.txt" I uploaded; may not be accurate) and edit the "GamePadEventData" struct in "vkb.h" accordingly.

## How to use
The current version of the code only utilizes files inside the "tx_vkb" folder. No need to care about other files as they are from a depracated method (tried to use an nRF24L01 PA+LNA module; left here for archival purposes).
1. Download the folder, flash tx_vkb.ino onto an Arduino Uno. 
2. Setup a FlySky FS-i6 RC Transmitter such that it is in "Trainer Mode". This way the RC Transmitter accepts PPM input.
3. Using a jumper cable or any other compatible cable (the PPM port on the RC Transmitter is a Mini-DIN 4 pin), connect the GND and SIG cables. (Arduino GND to RC GND, Arduino SigPin to RC top right port).
4. It should work. If not, put your transmitter as "Student Mode" (PPM output) and check the signals coming out from the PPM out port (top left) using a oscilloscope. Then change the values in the CONFIGURATION part accordingly.

## Want to learn more?
I referred to these websites:

https://chome.nerpa.tech/category/mcu/arduino/usb-shield/hid/

https://www.tracesystemsinc.com/USB_Tutorials_web/USB/B1_USB_Classes/Books/A3_A_Closer_Look_at_HID_Class/slide01.htm

https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/

## Why?
This is for a personal / school club project.
