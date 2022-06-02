/* 1. ArrayDemo */
#include <Arduino.h>

void setup()
{
	Serial.begin(115200);
	
	String  hello = "hello";
	String  friends = "Friend";
	String hellofriend = String(hello + friends);


	Serial.println(hello); Serial.println(hello.length());
	Serial.println(friends); Serial.println(friends.length());
	Serial.println(hellofriend);
	Serial.println(friends.charAt(2));
}

void loop()
{}