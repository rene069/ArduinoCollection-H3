#include <Arduino.h>

void PrintCharArray(char str[]);
void PrintIntArray(long *ptr, int length);

void setup()
{
	Serial.begin(115200);
	
	char text[] = "Start pump\r\n";
	long samples[] = {115, 2000, 95, 9 };

	PrintCharArray(text);
	PrintIntArray(samples, sizeof(samples) / 4);
}

void loop()
{
}

void PrintCharArray(char str[])
{
	int i = 0;

	while (str[i] != 0)
	{
		Serial.print(str[i]);
		i++;
	}
	while (*str != 0)
	{
		Serial.print("Adress: ");
		Serial.print((unsigned long)str);
		Serial.print(" content: ");
		Serial.println(*str);
		str++;
	}
}

void PrintIntArray(long *ptr, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		Serial.println(ptr[i]);
	}
	for (i = 0; i < length; i++)
	{
		Serial.print("Adress: ");
		Serial.print((unsigned long)ptr);
		Serial.print(" Content: ");
		Serial.println(*ptr);
		ptr++;
	}
}