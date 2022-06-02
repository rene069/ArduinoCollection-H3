#include <Arduino.h>;
#include <Servo.h>;

Servo myservo;

int valzero = 0;
int valmax = 180;
int val;

void setup()
{
	myservo.attach(8);
	
	//delay(1000);
	//myservo.write(valmax);
	//delay(500);
	//myservo.write(valzero);
}

void loop()
{
	val = analogRead(A0);
	
	val = map(val,0,1023,valzero,valmax);
	
	myservo.write(val);
	delay(15);
	
	//for (int i = 0; i < 180; i++)
	//{
		//myservo.write(i);
		//delay(20);
	//}
	//
	//for (int e = 179; e >= 0; e--)
	//{
		//
		//myservo.write(e);
		//delay(20);
		//
	//}

	
}