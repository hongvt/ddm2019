
//#include <SoftwareSerial.h> //for setting pins 2 and 3 on the arduino to act as TX and RX
//#include <XBee.h>
#define XBee Serial
//SoftwareSerial XBee (2,3);

int data=0;
int led=7;

void setup() {
Serial.begin(115200); //this baud rate must match that of the configured xbee
XBee.begin(115200);
pinMode(led,OUTPUT);

}

void loop() {
while(XBee.available()) { //check to see if XBee is receiving
data=XBee.read();
Serial.print(data);
}

if (data==1) {
  digitalWrite(led,HIGH);
 }

if (data==0){
digitalWrite(led,LOW);
}

}
