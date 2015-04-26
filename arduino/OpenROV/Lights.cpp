#include "AConfig.h"
#if(HAS_STD_LIGHTS)
#include "Device.h"
#include "Pin.h"
#include "Lights.h"
#include "Settings.h"
#include <Arduino.h>

Pin light("light", LIGHTS_PIN, light.analog, light.out);

void Lights::device_setup(){
  Settings::capability_bitarray |= (1 << LIGHTS_CAPABLE);
  light.reset();
  light.write(0);
}



void Lights::device_loop(Command command){

    if( command.cmp("ligt")){
      int value = command.args[1]; //0 - 255
      light.write(value);
      
      _SERIAL_PORT_.print(F("LIGT:"));
      _SERIAL_PORT_.print(value);
      _SERIAL_PORT_.print(';');
      _SERIAL_PORT_.print(F("LIGP:"));
      _SERIAL_PORT_.print(command.args[1]/255.0);
      _SERIAL_PORT_.println(';');       
    }  
}
#endif



