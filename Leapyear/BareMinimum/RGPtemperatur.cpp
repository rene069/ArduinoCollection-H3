#include <Arduino.h>
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char grad = 0xDF;

const int red = 10;
const int green = 9;
const int blue = 8;
const int duty = 64;
const int off = 0;

const long interval = 500;
unsigned long previousMillis = 0;

void setup(){
	pinMode(red,OUTPUT);
	pinMode(green,OUTPUT);
	pinMode(blue,OUTPUT);
	Serial.begin(9600);
	lcd.begin(16,2);
	lcd.print("Temp ");
	lcd.setCursor(11,0);
	lcd.print(grad);
	lcd.setCursor(0,1);
	lcd.print("Farve:");
}

void loop(){
	float sensorReading = analogRead(A0);
	float temp = log(10000.0 * (1024.0/sensorReading - 1));
	float tempK = 1/(0.001129148+(0.000234125+(0.0000000876741*temp*temp))*temp);
	float tempC = tempK - 273.15;
	
	unsigned long currentMillis = millis();

	if (currentMillis - previousMillis >= interval){
		previousMillis = currentMillis;
		
		if (tempC > 26)
		{
			analogWrite(red,duty);
			analogWrite(green,off);
			analogWrite(blue,off);
			lcd.setCursor(7,1);
			lcd.print("Red");
			
		}
		else if (tempC < 25)
		{
			analogWrite(red,off);
			analogWrite(green,off);
			analogWrite(blue,duty);
			lcd.setCursor(7,1);
			lcd.print("blue");
		}
		else if (tempC >= 25 && tempC < 26)
		{
			analogWrite(red,off);
			analogWrite(green,duty);
			analogWrite(blue,off);
			lcd.setCursor(7,1);
			lcd.print("green");
		}
		Serial.println(tempC);
		lcd.setCursor(6,0);
		lcd.print(tempC);
	}
}