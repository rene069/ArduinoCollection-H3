#include <Arduino.h>



void setup() {
	
	pinMode(2,OUTPUT);
	pinMode(4,INPUT_PULLUP); 

}

void loop() {
	
	
	if (digitalRead(4))
	{
		digitalWrite(2,LOW);
	}
	else{
		digitalWrite(2,HIGH);
	}

}