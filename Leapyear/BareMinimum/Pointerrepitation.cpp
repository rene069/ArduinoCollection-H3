#include <Arduino.h>

//1. Hvordan kan man finde adressen på en variabel kaldet var1?: &var1

//2.

float floatvar = 47;

float *ptr = &floatvar;


void setup(){
	Serial.begin(115200);
	//Serial.print((unsigned int)*ptr);
	//*ptr = 47;
	
	//3. Hvad mangler der i dette program? Tilføj den manglende linje:
	
	//int var = 0;
	//int *pName;
	//*pName = &var;
	//*pName = 33;
	//return 0;

	
	//4. Hvad skal der skrives (i pointer-notation) for at ch bliver lig med n’et i tekststrengen?
	
	//char string[] = "Lene";
	////char *p = string + 2;
	//char ch = *(string + 2);
	//
	//Serial.print(ch);
	
	//5. Opret en streng, som indeholder dit navn.
	
	char navn[] = "Rene";

	//char *n = navn + 2;  //udskriver 3 karakter

	
	Serial.print(*n);
	
	char *n = navn + 3;
	int index;
	
	for (index = 0; index < 4; index++)
	{
		
		Serial.print(*n);
		n--;
		
	}

}

void loop(){
	
}