/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

//Step 1: Get current year
//Step 2: Check if year is divisible by 4 but not 100, turn on Diode
//Step 3: check if year is divisible by 400 turn on Diode
//step 4 Otherwise don't turn on diode
//STOP

const int LedPin = 2;
int year = 2024;


void setup() {
	pinMode(2,OUTPUT);
	digitalWrite(2,LOW);
}

void loop()
{
	//IF year%4 = 0 AND year%100 != 0 OR Year%400 = 0
	if (year % 4 == 0 && year%100 !=0 || year%400 == 0)
	{
		//turn on diode
		digitalWrite(2, HIGH);
	}
}
