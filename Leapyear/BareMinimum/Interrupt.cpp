#include <Arduino.h>
#include <Servo.h>;

Servo myservo;

int valzero = 0;
int valmax = 180;


void blink();

const byte greenledpin = 13;
const byte blueledpin = 7;
const byte interruptpin = 19;

volatile byte bluestate = LOW;
volatile byte  greenstate = LOW;

void setup()
{
	myservo.attach(8);
	pinMode(greenledpin,OUTPUT);
	pinMode(blueledpin,OUTPUT);
	pinMode(interruptpin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptpin),blink,FALLING);
}

void loop()
{
	
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
	
	//greenstate = !greenstate;
	//digitalWrite(greenledpin,greenstate);
	//delay(250);
	//greenstate = !greenstate;
	//digitalWrite(greenledpin,greenstate);
	//delay(250);
}

void blink()
{
	bluestate = !bluestate;
	digitalWrite(blueledpin,bluestate);
}