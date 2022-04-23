/* Simplified Logitech Extreme 3D Pro Joystick Report Parser */

#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "vkb.h"

//APC PART
#include <SoftwareSerial.h>
SoftwareSerial APC(3, 4); // RX and TX
//


// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>

USB                                             Usb;
USBHub                                          Hub(&Usb);
HIDUniversal                                    Hid(&Usb);
JoystickEvents                                  JoyEvents;
JoystickReportParser                            Joy(&JoyEvents);

void setup()
{
  ///APC PART
  APC.begin(9600);    // start serial to APC
  ////
  Serial.begin( 115200 );
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  Serial.println("Start");

  if (Usb.Init() == -1)
      Serial.println("OSC did not start.");

  delay( 200 );

  if (!Hid.SetReportParser(0, &Joy))
      ErrorMessage<uint8_t>(PSTR("SetReportParser"), 1  );
}

void loop()
{
    Usb.Task();
    extern uint16_t x, y, rudder, throttle;
    
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(" ");

    APC.println((String)x + "///" + y + "///" + rudder + "///" + throttle);
    
  
    Serial.print("Y: ");
    Serial.print(y);
    Serial.print(" ");
//
//    APC.print("///");
//    APC.print(y);
  
    Serial.print("Rudder: ");
    Serial.print(rudder);
    Serial.print(" ");
//
//    APC.print("///");
//    APC.print(rudder);

    Serial.print("Throttle: ");
    Serial.print(throttle);
    Serial.print(" ");
//    
//    APC.print("///");
//    APC.print(throttle);

    
    Serial.println("");
}
