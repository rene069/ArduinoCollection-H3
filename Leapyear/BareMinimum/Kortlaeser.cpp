#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#include <Servo.h>

Servo myservo;

#define SS_PIN 53
#define RST_PIN 8


MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;
// Init array that will store new NUID
byte nuidPICC[3];
void printDec(byte *buffer, byte bufferSize);
void printHex(byte *buffer, byte bufferSize);
void setup() {
	for
	Serial.begin(9600);
	SPI.begin(); // Init SPI bus
	rfid.PCD_Init(); // Init MFRC522
	for (byte i = 0; i < 6; i++) {
		key.keyByte[i] = 0xFF;
	}
	myservo.attach(8);
}
void loop() {
	// Look for new cards
	if ( ! rfid.PICC_IsNewCardPresent())
	return;
	// Verify if the NUID has been readed
	if ( ! rfid.PICC_ReadCardSerial())
	return;
	
	if (rfid.uid.uidByte[0] != 48 || rfid.uid.uidByte[1] != 69 || rfid.uid.uidByte[2] != 102 || rfid.uid.uidByte[3] != 167 )
	{
		Serial.println("Access denied");
	}
	else
	{
		Serial.println("Access granted");
		for (int i = 0; i < 180; i++)
		{
			myservo.write(i);
			delay(20);
		}
		
		for (int e = 179; e >= 0; e--)
		{
			
			myservo.write(e);
			delay(20);
			
		}
	}
	// Halt PICC
	rfid.PICC_HaltA();
	// Stop encryption on PCD
	rfid.PCD_StopCrypto1();
}
void printHex(byte *buffer, byte bufferSize) {
	for (byte i = 0; i < bufferSize; i++) {
		Serial.print(buffer[i] < 0x10 ? " 0" : " ");
		Serial.print(buffer[i], HEX);
	}
}
void printDec(byte *buffer, byte bufferSize) {
	for (byte i = 0; i < bufferSize; i++) {
		Serial.print(buffer[i] < 0x10 ? " 0" : " ");
		Serial.print(buffer[i], DEC);
	}
}