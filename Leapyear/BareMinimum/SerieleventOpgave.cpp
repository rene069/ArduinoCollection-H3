#include <Arduino.h>

String inputString = "";
bool stringcomplete = false;

void setup()
{
	Serial.begin(9600);
	inputString.reserve(200);
}

void loop()
{
	if(stringcomplete){
		Serial.println(inputString);
		inputString = "";
		stringcomplete = false;
	}
}

void serialEvent()
{
	while(Serial.available())
	{
		char inChar = (char)Serial.read();
		inputString += inChar;
		
		if (inChar == '\n')
		{
			stringcomplete = true;
		}
	}
}
