#include "vkb.h"

JoystickReportParser::JoystickReportParser(JoystickEvents *evt) :
	joyEvents(evt)
{}

void JoystickReportParser::Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf)
{
	bool match = true;

	// Checking if there are changes in report since the method was last called
	for (uint8_t i=0; i<RPT_GAMEPAD_LEN; i++) {
		if( buf[i] != oldPad[i] ) {
			match = false;
			break;
		}
  }
  	// Calling Game Pad event handler
	if (!match && joyEvents) {
		joyEvents->OnGamePadChanged((const GamePadEventData*)buf);

		for (uint8_t i=0; i<RPT_GAMEPAD_LEN; i++) oldPad[i] = buf[i];
	}
}


//

//uint16_t x, y, rudder, throttle;
int x, y, rudder, throttle;

//

void JoystickEvents::OnGamePadChanged(const GamePadEventData *evt)
{
  x = evt->x;
  y = evt->y;
  rudder = evt->rudder;
  throttle = evt->throttle;
/*  
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(" ");
  
  Serial.print("Y: ");
  Serial.print(y);
  Serial.print(" ");
  
  Serial.print("Rudder: ");
  Serial.print(rudder);
  Serial.print(" ");
  
  Serial.print("Throttle: ");
  Serial.print(throttle);
  Serial.print(" ");
*/
  /*
	Serial.print("X: ");
	PrintHex<uint16_t>(evt->x, 0x80);
 
	Serial.print(" Y: ");
	PrintHex<uint16_t>(evt->y, 0x80);

	Serial.print(" Rudder: ");
	PrintHex<uint16_t>(evt->rudder, 0x80);

  Serial.print(" Throttle: ");
  PrintHex<uint16_t>(evt->throttle, 0x80);
  */

  //Serial.println("");
}
