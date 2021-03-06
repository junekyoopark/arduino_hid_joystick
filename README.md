# arduino_hid_joystick
Arduino Drone Controller using input from USB HID Joystick (VKBSim Gladiator NXT EVO)

## What this does
Sends X, Y, Rudder, Throttle axis values from a USB Joystick (connected to a transmitter Arduino) to a receiver Arduino. 


## How this works

Using the [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0),
Tx (transmitter) parses X, Y, Rudder, Throttle values from USB Joystick HID Report and sends them to Rx (receiver) using nRF24L01 communications module (2.4GHz).

This repo is a very slight modification of "le3dp" example from [USB Host Shield Library](https://github.com/felis/USB_Host_Shield_2.0) so that it works with the VKBSim Gladiator NXT EVO Joystick.

Currently does not support button presses. If you would like to add this feature, go through the HID Report Descriptor (or you can check "HID Descriptor.txt" I uploaded; may not be accurate) and edit the "GamePadEventData" struct in "vkb.h" accordingly.

## How to use
Need 2 Arduinos, 2 nRF24L01 Modules, 1 USB Host Shield

Use the code in the "nrf" folder. Other files are deprecated (they use the APC220 module) but are here for archival purposes.

1. Assemble Arduino and USB Host shield. This Arduino runs the Tx. Just open "tx_vkb.ino" and flash it to the Arduino.
2. The other Arduino runs Rx. Open "rx.ino" and flash it to the Arduino.
3. Of course do not forget to connect the nRF24L01 modules to respective pins.
4. Run the serial monitor on the Rx Arduino and you will see joystick values being streamed.

You can use other communication modules such as APC220. Just modify the nRF24L01 parts in the repo and you will be good to go.

## Want to learn more?
I referred to these websites:

https://chome.nerpa.tech/category/mcu/arduino/usb-shield/hid/

https://www.tracesystemsinc.com/USB_Tutorials_web/USB/B1_USB_Classes/Books/A3_A_Closer_Look_at_HID_Class/slide01.htm

https://eleccelerator.com/tutorial-about-usb-hid-report-descriptors/

## Why?
This is for a personal / school club project.
