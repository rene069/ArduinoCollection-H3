#include <Arduino.h>
#include <SPI.h>



void setup(void){
	SPI.begin();
	SPI.beginTransaction(SPISettings(400000,MSBFIRST,SPI_MODE1));
}

void loop(void){
	digitalWrite(SS,LOW);
	

	SPI.transfer('A');
	SPI.transfer('B');
	SPI.transfer('C');
	
	digitalWrite(SS,HIGH);
	delay(2000);
	
}