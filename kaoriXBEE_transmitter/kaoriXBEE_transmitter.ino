//#include <SoftwareSerial.h> //for setting pins 2 and 3 on the arduino to act as TX and RX
//#include <XBee.h>
#define XBee Serial1

const int buttonPin = 7;
const int ledPin = 13;      // the number of the LED pin

//Variables will change
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

//XBEE PIN INITIALIZATION
//Xbee's DOUT (TX) is connected to pin 2 (Arduinos Software RX)
//Xbee's DIN (RX) is conected to pin 3 (Arduino's Software TX)
//SoftwareSerial XBee(2,3); //RX, TX)


void setup() {
pinMode(buttonPin, INPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
XBee.begin(115200);

  // set initial LED state
 digitalWrite(ledPin, ledState);

}

void loop() {
// read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
digitalWrite(ledPin, ledState);
  
XBee.write(ledState);
Serial.println(ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}
