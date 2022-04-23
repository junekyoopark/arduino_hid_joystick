# arduino_hid_joystick
Arduino Drone Controller using input from USB HID Joystick

Tx parses X, Y, Rudder, Throttle values from USB Joystick HID Descriptor and sends them to Rx using APC220 communications module (433MHz).

Very slight modification of "le3dp" example from https://github.com/felis/USB_Host_Shield_2.0 so that it works with VKBSim Gladiator NXT Evo.
