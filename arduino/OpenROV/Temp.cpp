#include "AConfig.h"

#include "Device.h"
#include "Pin.h"
#include "Settings.h"
#include <Arduino.h>
#include "Timer.h"
#include "OneWire.h"
#include "Temp.h"
#include "DallasTemperature.h"

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 30

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

DeviceAddress insideThermometer;

Timer tempReadTimer;

bool isRunning = true;

void Temp::device_setup(){
	tempReadTimer.reset();
	
	if (!sensors.getAddress(insideThermometer, 0)) {
		isRunning = false;
		_SERIAL_PORT_.print(F("log: "));
        _SERIAL_PORT_.println("init temp failed");
		return;
	}
	sensors.setResolution(insideThermometer, 9);
	
}



void Temp::device_loop(Command command){
	
	if (tempReadTimer.elapsed(1000)){
	    if(isRunning ) {
    		sensors.requestTemperatures();
    		envdata::AIRTEMP = sensors.getTempC(insideThermometer);
	    }else {
	        isRunning = true;
	        if (!sensors.getAddress(insideThermometer, 0)) {
        		isRunning = false;
        		_SERIAL_PORT_.print(F("log: "));
                _SERIAL_PORT_.println("init temp failed");
        		return;
        	}
	        sensors.setResolution(insideThermometer, 9);
	    }
	}  
}




