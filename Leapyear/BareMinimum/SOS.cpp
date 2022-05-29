#include <Arduino.h>

//Step 1: 3 Dots
//step 2: 3 Dashes
//Step 3 3 Dots
//step 4 Small Pause then repeat

const int yellowPin =  2;
const int redPin = 4;
int ledState = LOW;

unsigned long previousMillis = 0;
int DotCounter = 0;
int LineCounter = 0;
//unsigned long Dash = 1000;
//unsigned long Dot = 500;

const long Dotinterval = 500;
const long DashInterval = 1000;

void setup() {

	pinMode(yellowPin, OUTPUT);
	pinMode(redPin, OUTPUT);

}
void loop() {
	
	unsigned long currentMillis = millis();

	if (currentMillis - previousMillis >= Dotinterval && DotCounter < 6) {
		previousMillis = currentMillis;
		DotCounter = DotCounter + 1;
		
		if (ledState == LOW) {
			ledState = HIGH;
			} else {
			ledState = LOW;
		}
		digitalWrite(yellowPin, ledState);
	}
	else if(currentMillis - previousMillis >= DashInterval && LineCounter < 6){
		previousMillis = currentMillis;
		LineCounter = LineCounter + 1;
		
		if (ledState == LOW) {
			ledState = HIGH;
			} else {
			ledState = LOW;
		}

		if (LineCounter == 6)
		{
			DotCounter = 0;
			LineCounter = 0;
		}
		digitalWrite(redPin, ledState);
	}
}






//const int LedPin = 2;
//unsigned long Dash = 1000;
//unsigned long Dot = 500;
//unsigned long PreviousMillis = 0;
//int LedState = LOW;
//int DotCounter;
//
//
//void setup() {
//pinMode(LedPin,OUTPUT);
//digitalWrite(LedPin,LedState);
//}
//
//
//
//void loop()
//{
//unsigned long currentMillis = millis();
//
//if (currentMillis - PreviousMillis >= Dash || currentMillis - PreviousMillis >= Dot)
//{
//PreviousMillis = currentMillis;
//}
//
//if (PreviousMillis >= Dot){
//DotCounter = DotCounter + 1;
//if (LedState == LOW)
//{
//LedState = HIGH;
//}
//else{
//LedState = LOW;
//}
//}
//
//
//
//
//digitalWrite(LedPin,LedState);
//}
