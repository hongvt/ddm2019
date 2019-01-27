
#include <XBee.h>

//#define XBee Serial1 //use mega hardware serial ports, no need to define them as software ports
#include <SoftwareSerial.h>
//#include <XBee.h>

int Lswitch=7;
int LS_state=0;

//XBEE PIN INITIALIZATION
//Xbee's DOUT (TX) is connected to pin 2 (Arduinos Software RX)
//Xbee's DIN (RX) is conected to pin 3 (Arduino's Software TX)

SoftwareSerial xbeeSerial(2,3); //RX, TX)

XBee xbeeT = XBee(); //TX3, RX2 defining more serial ports arduino??

void setup() {
  Serial.begin(115200);
  //XBee.begin(115200);
  xbeeT.setSerial(xbeeSerial);
  pinMode(Lswitch, INPUT_PULLUP);

}

void loop() {
LS_state=digitalRead(Lswitch);
uint8_t payload[] = {0,0};
Tx16Request tx = Tx16Request(0x7ABF, payload, sizeof(payload));
xbeeT.send(tx);

/*if (LS_state==0){
  XBee.write("z");
  Serial.println("z");
}
if (LS_state==1){
  XBee.write("a");
  Serial.println("a");
}*/
Serial.println(LS_state);
//XBee.write(LS_state);

}
