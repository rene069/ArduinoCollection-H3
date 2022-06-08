#include <Arduino.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DS3231.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET 4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String addZero(int time);

String Datetime;

DS3231 clock;
RTCDateTime dt;

#define DHTPIN 8
char grad = 0xF7;

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

bool switched = false;
const long tempinterval = 10000;
unsigned long previousMillis = 0;

void setup() {
	Serial.begin(9600);
	Serial.println(F("DHTxx test!"));

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
	dht.begin();
}

void loop() {
	display.clearDisplay();
	display.setTextSize(1); // Normal 1:1 pixel scale
	display.setTextColor(WHITE); // Draw white text
	display.setCursor(0,0); // Start at top-left corner
	
	unsigned long currentMillis = millis();
	// Wait a few seconds between measurements.
	if (currentMillis - previousMillis >= tempinterval){
		previousMillis = currentMillis;
		switched = !switched;
	}
	
	if (switched)
	{
		
		int h = dht.readHumidity();
		
		int t = dht.readTemperature();

		// Check if any reads failed and exit early (to try again).
		if (isnan(h) || isnan(t)) {
			Serial.println(F("Failed to read from DHT sensor!"));
			return;
		}

		// Compute heat index in Celsius (isFahreheit = false)
		int hic = dht.computeHeatIndex(t, h, false);

		display.print(F("Humidity: "));
		display.print(h);
		display.println("%");
		display.print(F("Temperature: "));
		display.print(t);
		display.write(grad);
		display.println();
		display.print(F("Heat index: "));
		display.print(hic);
		display.println(grad);
		
		display.display();
	}
	else
	{
		dt = clock.getDateTime();
		display.clearDisplay();
		// For leading zero look to DS3231_dateformat example
		
		display.setTextSize(2);
		display.setTextColor(WHITE);
		display.setCursor(0,0);
		
		display.print(addZero(dt.hour));display.print(":");
		display.print(addZero(dt.minute));display.print(":");
		display.println(addZero(dt.second));
		
		display.print(addZero(dt.day));display.print("/");
		display.print(addZero(dt.month));display.print("/");
		display.print(addZero(dt.year));

		display.display();
	}
	
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