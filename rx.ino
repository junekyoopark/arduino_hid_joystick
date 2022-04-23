#include <SoftwareSerial.h>

SoftwareSerial APC(3, 4); // RX and TX
 
void setup()
{
  APC.begin(9600);    // start serial to APC
  Serial.begin(9600);
}

void loop()
{
   while(APC.available()) {
     Serial.print((char)APC.read());
   }
   //delay(100);
}
