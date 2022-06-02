#include <Arduino.h>

void add(float *ptrnum1, float *ptrnum2, float *ptrresult);

void setup()
{
	Serial.begin(115200);
	
	float tal1 = 3;
	float tal2 = 7;
	float result;
	
	float *ptr1 = &tal1;
	float *ptr2 = &tal2;
	
	float *ptrresult = &result;
	
	add(ptr1,ptr2,ptrresult);
	
	Serial.print(*ptr1); Serial.print(" + "); Serial.print(*ptr2); Serial.print(" = "); Serial.print(*ptrresult);
	
	
}

void loop(){
	
}

//tilføj moms
void add(float *ptrnum1, float *ptrnum2, float *ptrresult){
	
	*ptrnum1 *= 1.25;
	*ptrnum2 *= 1.25;
	*ptrresult = *ptrnum1 + *ptrnum2;
}