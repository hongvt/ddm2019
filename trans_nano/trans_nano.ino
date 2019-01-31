
////#include <SoftwareSerial.h> //for setting pins 2 and 3 on the arduino to act as TX and RX, need this library
////SoftwareSerial xbeeSerial(2,3); //creates object of SoftwareSerial that defines the TX and RX pins for the xbee

int8_t data = 0; //8 bit value, form of xbee message packets
int led=7;

void setup() {
  Serial.begin(9600); //this baud rate must match that of the configured xbee
////xbeeSerial.begin(9600); //start xbee communication
  pinMode(led,OUTPUT);

}

void loop() {
   if(Serial.available()) { //check to see if XBee is receiving, if redefining pins, would be xbeeSerial.available()
    data=Serial.read(); //xbeeSerial.read()
    if (data>=1) {
      digitalWrite(led,HIGH);
      Serial.println("high");
      //Serial.println(data);
     }
    
    if (data<=0){
      digitalWrite(led,LOW);
      Serial.println("low");
      //Serial.println(data);
    }
  }
}
