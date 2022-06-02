#include <Arduino.h>

void setup()
{
	Serial.begin(115200);
	
	int tal1 = 3;
	int tal2 = 7;
	int result;
	
	int *ptr1 = &tal1;
	int *ptr2 = &tal2;
	
	
	result = *ptr1 + *ptr2;
	
	int *ptrresult = &result;
	Serial.print((unsigned int)*ptr1); Serial.print(" + "); Serial.print((unsigned int)*ptr2); Serial.print(" = "); Serial.print((unsigned int)*ptrresult);
	
	
}

void loop(){
	
}