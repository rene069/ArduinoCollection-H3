#include <Arduino.h>
#include <Keypad.h>
#include <LiquidCrystal.h>
//https://www.teachmemicro.com/arduino-keypad-interfacing-4x4-matrix/

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

byte rowPins[ROWS] ={30,31,32,33}; //connect to the row pin outs of the keypad
byte colPins[COLS] =  {34,35,36,37}; //connect to the column pin outs of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
	Serial.begin(9600);
}

void loop(){
	char customKey = customKeypad.getKey();
	if (customKey){
		Serial.println(customKey);
	}
}