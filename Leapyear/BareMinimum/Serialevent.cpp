/* SerialReadstring.cpp */

// Demo af Serial.available() Serial.print() og Serial.println(). Benyt Terminal Window MED LF og CR

#include <Arduino.h>

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;	 // whether the string is complete

void setup()
{
	Serial.begin(9600);
	
	inputString.reserve(200);		// reserve 200 bytes for the inputString
}

void loop()
{
	// print the string when a newline arrives:
	if (stringComplete)
	{
		Serial.println(inputString);
		// clear the string:
		inputString = "";
		stringComplete = false;
	}
}

/*
SerialEvent occurs whenever a new data comes in the hardware serial RX. This
routine is run in the end of the loop(), so using delay inside loop can
delay response. Multiple bytes of data may be available.
*/
void serialEvent()
{
	while (Serial.available())
	{
		// get the new byte:
		char inChar = (char)Serial.read();
		// add it to the inputString:
		inputString += inChar;
		// if the incoming character is a newline, set a flag so the main loop can do something about it:
		if (inChar == '\n')
		{
			stringComplete = true;
		}
	}
}