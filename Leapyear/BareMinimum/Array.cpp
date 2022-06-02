/* 1. ArrayDemo */
#include <Arduino.h>

void setup() 
{
	Serial.begin(115200);
	
	byte num_list[3] = {7, 9, 13};
	byte index;
	
	byte nameindex;
	
	char navn[5] =  {'r','e','n','e','\0'};

	for (index = 0; index < sizeof(num_list) + 1; index++)
	{
		Serial.println(num_list[index]);
	}
	
	for (nameindex = sizeof(navn) - 2; nameindex >= 0; nameindex--)
	{
		Serial.println(navn[nameindex]);
		
		if (nameindex == 0)
		{
			break;
		}
	}
	

}

void loop() 
{}