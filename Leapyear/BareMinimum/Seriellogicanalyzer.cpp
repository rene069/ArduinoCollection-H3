/* 3. FormattedData.cpp
	Print values in various formats to the serial port
*/
#include <Arduino.h>



void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println("A");
	delay(2000);
}