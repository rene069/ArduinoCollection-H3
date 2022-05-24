
const int btn = 2;
int buttonState;        
int lastButtonState = LOW;
int Counter = 0;


unsigned long lastDebounceTime = 0; 
unsigned long debounceDelay = 50;  


void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(btn);


  

if (reading != lastButtonState) {

    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;


      if (buttonState == HIGH) {
       if(!digitalRead(2)){
    Counter = Counter + 1;
     Serial.print(Counter);
  }
      }
    }
  }
 
}
