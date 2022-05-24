const int buttonPin = 2;   
const int ledPin = 13;      


int ledState = HIGH;        
int buttonState;            
int lastButtonState = HIGH;   


unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;   

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);


  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);

  lastButtonState = reading;
}
