/* Simplified Logitech Extreme 3D Pro Joystick Report Parser */

#include <usbhid.h>
#include <hiduniversal.h>
#include <usbhub.h>

#include "vkb.h"

//RF24L01part
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

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
  ///nRF24L01 PART
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
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


//these were initialized to save bandwidth

int old_arr[4]; //initializing array in loop()
int arr[4]; //initializing array in loop()

int i; //initializing counter for going through elements in array
int change = 0; //initializing variable. Checks whether there is a change in input or not. 
//

void loop()
{
    Usb.Task();
    //extern uint16_t x, y, rudder, throttle;
    extern int x, y, rudder, throttle;

    //normalize values. PPM range is 1000-2000, USB values are x, y = 0~4095, rudder and throttle 0~2048, so 
    arr[0] = x * 0.244140625 + 1000;
    arr[1] = y * 0.244140625 + 1000;
    arr[2] = rudder * 0.48828125 + 1000;
    //since throttle is inversed
    arr[3] = (-throttle+2048) * 0.48828125 + 1000;
 
    for (i=0; i<=3; i++)
    {  
      if (old_arr[i] != arr[i])
      {
        change = 1;
      }
      old_arr[i] = arr[i];
    }

    if (change == 1)
    {
      Serial.println((String)arr[0] + "///" + arr[1] + "///" + arr[2] + "///" + arr[3]);
      
      
      radio.write(&arr, sizeof(arr));
    }
    
    i = 0;
    change = 0;
    
//    Serial.print("X: ");
//    Serial.print(x);
//    Serial.print(" ");
//
//    APC.println((String)x + "///" + y + "///" + rudder + "///" + throttle);
//    
//  
//    Serial.print("Y: ");
//    Serial.print(y);
//    Serial.print(" ");
////
////    APC.print("///");
////    APC.print(y);
//  
//    Serial.print("Rudder: ");
//    Serial.print(rudder);
//    Serial.print(" ");
////
////    APC.print("///");
////    APC.print(rudder);
//
//    Serial.print("Throttle: ");
//    Serial.print(throttle);
//    Serial.print(" ");
////    
////    APC.print("///");
////    APC.print(throttle);
//
//    
//    Serial.println("");
}
