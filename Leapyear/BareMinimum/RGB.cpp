#include <Arduino.h>

const int red = 10;
const int green = 9;
const int blue = 8;
const int duty = 64;
const int off = 0;

void setup(){
	pinMode(red,OUTPUT);
	pinMode(green,OUTPUT);
	pinMode(blue,OUTPUT);
}

void loop(){
	analogWrite(green,duty);
	analogWrite(blue,duty);
	analogWrite(red,off);
	delay(1000);
	analogWrite(green,duty);
	analogWrite(blue,duty);
	analogWrite(red,duty);
	delay(1000);
	analogWrite(green, duty);
	analogWrite(red,duty);
	analogWrite(blue,off);
	delay(1000);
}
	