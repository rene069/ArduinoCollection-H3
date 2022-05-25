#include <Arduino.h>
#include <LiquidCrystal.h>

//Millis
int previousMillis = 0;


//Temperature's
float MaxTemp = 25.00;
float ResetPoint = 24.50;

//LED
int LEDState = LOW;
int led = LED_BUILTIN;

//LCD
char grad = 0xDF;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
	pinMode(LED_BUILTIN,OUTPUT);
	lcd.begin(16,2);
	lcd.print("Temp ");
	lcd.setCursor(11,0);
	lcd.print(grad);
}

void loop() {
	float sensorReading = analogRead(A0);
	float temp = log(10000.0 * (1024.0/sensorReading - 1));
	float tempK = 1/(0.001129148+(0.000234125+(0.0000000876741*temp*temp))*temp);
	float tempC = tempK - 273.15;
	
	lcd.setCursor(6,0);
	lcd.print(tempC);

	if(tempC >= MaxTemp){
		LEDState = HIGH; //Sets Ledstate to high when the temperature is higher than max temp
	}
	else if (tempC <= ResetPoint)
	{
		LEDState = LOW;//Sets Ledstate to LOW when the temperature is higher than max temp
	}


	if (LEDState == HIGH)
	{
		digitalWrite(LED_BUILTIN,LEDState);
		lcd.setCursor(0,1);
		lcd.print("High");
	}
	else if(LEDState == LOW){
		digitalWrite(LED_BUILTIN,LEDState);
		lcd.setCursor(0,1);
		lcd.print("Low");
	}

}