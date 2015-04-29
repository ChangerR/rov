#include "AConfig.h"
#if(HAS_STD_SWITCHFANLIGHT)
#include "Device.h"
#include "SwitchFanLight.h"

void SwitchFanLight::device_setup(){
	pinMode(FAN_PIN,OUTPUT);
	pinMode(LIGHT2_PIN,OUTPUT);
	
	digitalWrite(FAN_PIN,HIGH);
	digitalWrite(LIGHT2_PIN,HIGH);
}

void SwitchFanLight::device_loop(Command command){
    if( command.cmp("fan")){
		int value = command.args[1];
		digitalWrite(FAN_PIN,value?HIGH:LOW);
    } else if( command.cmp("light2")) {
		int value = command.args[1];
		digitalWrite(LIGHT2_PIN,value?HIGH:LOW);
	}
}

#endif
