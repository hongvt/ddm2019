//#define XBee Serial1 //use mega hardware serial ports, no need to define them as software ports
#include <SoftwareSerial.h>
#include <XBee.h>

int Lswitch=7;
int LS_state=0;

//XBEE PIN INITIALIZATION
//Xbee's DOUT (TX) is connected to pin 2 (Arduinos Software RX)
//Xbee's DIN (RX) is conected to pin 3 (Arduino's Software TX)
SoftwareSerial XBee(2,3); //RX, TX)


void setup() {
Serial.begin(115200);
XBee.begin(115200);
pinMode(Lswitch, INPUT_PULLUP);

}

void loop() {
LS_state=digitalRead(Lswitch);
/*if (LS_state==0){
  XBee.write("z");
  Serial.println("z");
}
if (LS_state==1){
  XBee.write("a");
  Serial.println("a");
}*/
Serial.println(LS_state);
XBee.write(LS_state);

}
