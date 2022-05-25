#include <Arduino.h>
const int btn = 4;
int buttonState = HIGH;
int lastButtonState = HIGH;
int Counter = 0;


unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup() {
	// put your setup code here, to run once:
	pinMode(btn, INPUT_PULLUP);
	Serial.begin(9600);
}

void loop() 
{
	// put your main code here, to run repeatedly:
	int reading = digitalRead(btn);


	

	if (reading != lastButtonState) 
	{

		lastDebounceTime = millis();
	}

	if ((millis() - lastDebounceTime) > debounceDelay) 
	{

		if (reading != buttonState) 
		{
			buttonState = reading;

			
			if (buttonState == LOW)
			{
				Counter = Counter + 1;
				Serial.print(Counter);
			}
			
			
		}
	}
	lastButtonState = reading;
}
