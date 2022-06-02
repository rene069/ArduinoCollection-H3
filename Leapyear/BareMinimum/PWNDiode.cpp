#include <Arduino.h>

const int LedPin = 8;



void setup(){
	pinMode(LedPin,OUTPUT);
	analogWrite(LedPin,255);
}

void loop(){
	//analogWrite(LedPin, 255); //100%
	//delay(2000);
	//analogWrite(LedPin,64); //25%
	//delay(2000);
	//analogWrite(LedPin,127);//50%
	//delay(2000);
	//analogWrite(LedPin,87); //34%
	
}