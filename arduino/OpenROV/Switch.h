
#ifndef __SWITCH_H_
#define __SWITCH_H
#include <Arduino.h>
#include "Device.h"
#include "Pin.h"
#include "AConfig.h"

//This must be defined with the right pin. It is set in the cape and controlboard header files.
//#define LIGHTS_PIN 5
#if(HAS_STD_CAPE)
  #include "Cape.h"
#endif

#if(HAS_OROV_CONTROLLERBOARD_25)
  #include "controllerboard25.h"
#endif


class Switch : public Device {
  public:
    Switch():Device(){};
    void device_setup();
    void device_loop(Command cmd);
};
#endif
