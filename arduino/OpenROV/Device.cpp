#include "Device.h"
#include "Settings.h"

Device::Device(){
  DeviceManager::registerDevice(this);
}

void Device::device_loop(Command cmd){
  
}

void Device::device_setup(){
  
}

void DeviceManager::registerDevice(Device *device){
  devices[device_count] = device;
  device_count++;
}

void DeviceManager::doDeviceLoops(Command cmd){
  for(int i=0;i<device_count;i++) {
    int stime = millis();
    devices[i]->device_loop(cmd);
    int delta = millis()-stime;
    if (delta > 0){
      DeviceManager:device_loop_ms[i]+=delta;
    }
  }
}

void DeviceManager::doDeviceSetups(){
  for(int i=0;i<device_count;i++) {
    devices[i]->device_setup();
  }
}

void OutputNavData(){
    _SERIAL_PORT_.print(F("hdgd:"));
    _SERIAL_PORT_.print(navdata::HDGD);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("deap:"));
    _SERIAL_PORT_.print(navdata::DEAP);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("pitc:"));
    _SERIAL_PORT_.print(navdata::PITC);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("roll:"));
    _SERIAL_PORT_.print(navdata::ROLL);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("yaw:"));
    _SERIAL_PORT_.print(navdata::YAW);
    _SERIAL_PORT_.print(';');    
    _SERIAL_PORT_.print(F("fthr:"));
    _SERIAL_PORT_.print(navdata::FTHR);
    _SERIAL_PORT_.println(';');
}

void OutputSharedData(){

    _SERIAL_PORT_.print(F("motorAttached:"));
    _SERIAL_PORT_.print(thrusterdata::MATC);
    _SERIAL_PORT_.println(';');
    
    _SERIAL_PORT_.print(F("servo:"));
    _SERIAL_PORT_.print(cameraMountdata::CMNT);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("starg:"));
    _SERIAL_PORT_.print(cameraMountdata::CMTG);
    _SERIAL_PORT_.println(';');
    
    _SERIAL_PORT_.print(F("fmem:"));
    _SERIAL_PORT_.print(capedata::FMEM);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("vout:"));
    _SERIAL_PORT_.print(capedata::VOUT);
    _SERIAL_PORT_.print(';');    
    _SERIAL_PORT_.print(F("iout:"));
    _SERIAL_PORT_.print(capedata::IOUT);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("atmp:"));
    _SERIAL_PORT_.print(capedata::ATMP);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("ver:"));
    _SERIAL_PORT_.print(F("CUSTOM_BUILD"));
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("cmpd:"));
    _SERIAL_PORT_.print( F(__DATE__));
    _SERIAL_PORT_.print( F(", "));
    _SERIAL_PORT_.print( F(__TIME__));
    _SERIAL_PORT_.print( F(", "));
    _SERIAL_PORT_.println( F(__VERSION__));  
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("time:"));
    _SERIAL_PORT_.print(capedata::UTIM);
    _SERIAL_PORT_.println(';'); 
    
    _SERIAL_PORT_.print(F("pres:"));
    _SERIAL_PORT_.print(envdata::PRES);
    _SERIAL_PORT_.print(';');
    _SERIAL_PORT_.print(F("temp:"));
    _SERIAL_PORT_.print(envdata::TEMP);
    _SERIAL_PORT_.println(';'); 
 
    _SERIAL_PORT_.print(F("dlms:")); //device loop time in ms
    for(int i=0;i<DeviceManager::device_count;i++){
      _SERIAL_PORT_.print(i);
      _SERIAL_PORT_.print('|');
      _SERIAL_PORT_.print(DeviceManager::device_loop_ms[i]);
    }
    _SERIAL_PORT_.println(';');   
    
}

int DeviceManager::device_count = 0;
Device *DeviceManager::devices[MAX_DEVICES];
unsigned DeviceManager::device_loop_ms[MAX_DEVICES];

// Initialize all of the shared data types
double navdata::HDGD = 0;
float navdata::DEAP = 0;
float navdata::PITC = 0;
float navdata::ROLL = 0;
float navdata::FTHR = 0;
float navdata::YAW = 0;

float envdata::PRES = 0;
float envdata::TEMP = 0;

double capedata::FMEM = 0;
double capedata::VOUT = 0;
double capedata::IOUT = 0;
double capedata::ATMP = 0;
String capedata::VER = "";
double capedata::UTIM = 0;

boolean thrusterdata::MATC = true;

int cameraMountdata::CMNT = MIDPOINT;
int cameraMountdata::CMTG = MIDPOINT;

