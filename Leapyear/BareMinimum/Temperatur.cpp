#include <Arduino.h>
#include <LiquidCrystal.h>

  // initialize the library by associating any needed LCD interface pin
  // with the arduino pin number it is connected to
  const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
  LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

  // make some custom characters:
  char grad = 0xDF;
	  
	
  void setup() {

	lcd.begin(16,2);
	lcd.print("Temp ");
	lcd.setCursor(11,0);
	lcd.print(grad);
	Serial.begin(9600);
	  // create a new character
  }

  void loop() {
	  // read the potentiometer on A0:
	  float sensorReading = analogRead(A0);
	  float temp = log(10000.0 * (1024.0/sensorReading - 1));
	  float tempK = 1/(0.001129148+(0.000234125+(0.0000000876741*temp*temp))*temp); 
	  float tempC = tempK - 273.15;
	  //Serial.println(tempC);
	  
	 lcd.setCursor(6,0);
	 lcd.print(tempC);

  }