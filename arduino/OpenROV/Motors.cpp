#include "Motors.h"

Motors::Motors(int p_pin, int v_pin, int s_pin,int v2_pin){
  port_pin = p_pin;
  vertical_pin = v_pin;
  starbord_pin = s_pin;
  vertical2_pin = v2_pin;
}

void Motors::reset(){
  port.attach(port_pin);
  vertical.attach(vertical_pin);
  starbord.attach(starbord_pin);
  vertical2.attach(vertical2_pin);
  delay(1500);
}

void Motors::go(int p, int v, int s){
// goport(p);
 govertical(v);
 //gostarbord(s);
goportAir(p);
gostarbordAir(s);
}

void Motors::goportAir(int p) {
	port.writeMicroseconds(p);
}
void Motors::goport(int p){
  int modifier = 1;
  if (p>MIDPOINT) modifier = motor_positive_modifer[port_motor];
  if (p<MIDPOINT) modifier = motor_negative_modifer[port_motor];
  int delta = p-MIDPOINT;
  port.writeMicroseconds(constrain(MIDPOINT+delta*modifier,1000,2000));

}

void Motors::govertical(int v){
	int delta = v-MIDPOINT;
  if(delta < 0) {
	int positive_s = MIDPOINT - delta;
	int negative_s = MIDPOINT + (delta * 5 / 3);

	vertical.writeMicroseconds(constrain(positive_s,1000,2000));
	vertical2.writeMicroseconds(constrain(negative_s,1000,2000));
  }else {
	  int positive_s = MIDPOINT - (delta * 5 / 3);
	  int negative_s = MIDPOINT + delta ;
	  
	  vertical.writeMicroseconds(constrain(positive_s,1000,2000));
	  vertical2.writeMicroseconds(constrain(negative_s,1000,2000));
  }
}

void Motors::gostarbord(int s){
  int modifier = 1;
  if (s>MIDPOINT) modifier = motor_positive_modifer[starbord_motor];
  if (s<MIDPOINT) modifier = motor_negative_modifer[starbord_motor];
  int delta = s-MIDPOINT;
  starbord.writeMicroseconds(constrain(MIDPOINT+delta*modifier,1000,2000));
}
void Motors::gostarbordAir(int s){
  starbord.writeMicroseconds(s);
}
void Motors::stop(){
  port.writeMicroseconds(MIDPOINT_AIR);
  vertical.writeMicroseconds(MIDPOINT);
  starbord.writeMicroseconds(MIDPOINT_AIR);
  vertical2.writeMicroseconds(MIDPOINT);
  port.detach();
  vertical.detach();
  starbord.detach();
  vertical2.detach();
}

bool Motors::attached(){
  return port.attached() || vertical.attached() || starbord.attached() ||vertical2.attached();
}

    //hard coded to reverse the starbord motor assuming we are using the reverse prop.
    //need to tunnel configuration down to this level, possibly store in eeprom.
    float Motors::motor_positive_modifer[3] = {-1.0,1.0,-1.0};
    float Motors::motor_negative_modifer[3] = {-2.0,2.0,-2.0};
