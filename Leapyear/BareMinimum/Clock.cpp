#include <Wire.h>
#include <DS3231.h>	
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String addZero(int time);

String Datetime;

DS3231 clock;
RTCDateTime dt;

void setup()
{
	Serial.begin(9600);

	// Initialize DS3231
	Serial.println("Initialize DS3231");;
	clock.begin();

	// Set sketch compiling time
	clock.setDateTime(__DATE__, __TIME__);
	
	if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
	{ // Address for 128x64
		Serial.println(F("SSD1306 allocation failed"));
		for(;;); // Don't proceed, loop forever
	}
	
}

void loop()
{
	
	dt = clock.getDateTime();
	display.clearDisplay();
	// For leading zero look to DS3231_dateformat example

	Serial.print("Raw data: ");
	Serial.print(dt.year);   Serial.print("-");
	Serial.print(dt.month);  Serial.print("-");
	Serial.print(dt.day);    Serial.print(" ");
	Serial.print(dt.hour);   Serial.print(":");
	Serial.print(dt.minute); Serial.print(":");
	Serial.print(dt.second); Serial.println("");
	
	display.setTextSize(2);
	display.setTextColor(WHITE);
	display.setCursor(0,0);
	
	display.print(addZero(dt.hour));
	display.print(addZero(dt.minute));
	display.print(addZero(dt.second));
	
	
	

display.display();

	delay(1000);
}

String addZero(int time)
{
	String ZeroRet;
	if (time <= 9)
	{
		ZeroRet += '0' +  (String)time;
	}
	else
	{
	 	ZeroRet = (String)time;
	}
	
	return ZeroRet;
}