#include "AConfig.h"
#if(HAS_STD_SWITCH)
#include "Device.h"
#include "Pin.h"
#include "Switch.h"
#include "Settings.h"

Pin fan("Fan", FAN_PIN, fan.digital, fan.out);
Pin light2("Light2",LIGHT2_PIN,light2.digital,light2.out);


void Switch::device_setup(){
    fan.write(0);
	light2.write(0);
}

void Switch::device_loop(Command command){
    if( command.cmp("fan")){
		int value = command.args[1];
		fan.write(value);
    } else if( command.cmp("light2")) {
		int value = command.args[1];
		light2.write(value);
	}
}

#endif
