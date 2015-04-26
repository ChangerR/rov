#include "AConfig.h"

#ifdef USE_SOFTSERIAL
const int pinRX = 36;  // pin 7
const int pinTX = 37;
SoftwareSerial apc(pinRX, pinTX);

#endif
