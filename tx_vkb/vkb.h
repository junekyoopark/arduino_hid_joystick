#if !defined(__HIDJOYSTICKRPTPARSER_H__)
#define __HIDJOYSTICKRPTPARSER_H__

#include <usbhid.h>

struct GamePadEventData
{
  union { //axes and hut switch
    uint32_t axes;
    struct {
      uint32_t filler : 8;
      uint32_t x : 16;
      uint32_t y : 16;
      uint32_t rudder : 16;
      uint32_t throttle : 11;
      uint32_t x_2 : 16;
      uint32_t y_2 : 16;
      
      uint32_t filler1 : 8;
      uint32_t filler2 : 8;
      uint32_t filler3 : 8;
      uint32_t filler4 : 8;
      
      uint32_t hatswitch : 16;
      uint32_t toptrigger : 8;
      uint32_t funcbuttons : 8;
    };
  };
};

class JoystickEvents
{
public:
	void OnGamePadChanged(const GamePadEventData *evt);
};

#define RPT_GAMEPAD_LEN	sizeof(GamePadEventData)/sizeof(uint8_t)

class JoystickReportParser : public HIDReportParser
{
	JoystickEvents		*joyEvents;

  uint8_t oldPad[RPT_GAMEPAD_LEN];

public:
	JoystickReportParser(JoystickEvents *evt);

	virtual void Parse(USBHID *hid, bool is_rpt_id, uint8_t len, uint8_t *buf);
};


#endif // __HIDJOYSTICKRPTPARSER_H__
