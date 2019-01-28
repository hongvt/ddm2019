
//#include <XBee.h> // comment out for now

//#define XBee Serial1 //use mega hardware serial ports, no need to define them as software ports
#include <SoftwareSerial.h>
//#include <XBee.h>

int Lswitch=7;
int LS_state=0;
int data=0;

//XBEE PIN INITIALIZATION
//Xbee's DOUT (TX) is connected to pin 2 (Arduinos Software RX)
//Xbee's DIN (RX) is conected to pin 3 (Arduino's Software TX)

SoftwareSerial xbeeSerial(2,3); //RX, TX)
//XBee xbeeT = XBee(); //TX3, RX2 defining more serial ports arduino??

void setup() {
  Serial.begin(115200);
  //XBee.begin(115200);
  //xbeeT.setSerial(xbeeSerial);
  xbeeSerial.begin(115200);
  pinMode(Lswitch, INPUT_PULLUP);

}

void loop() {
LS_state=digitalRead(Lswitch);
//uint8_t payload[] = {0,0};
//Tx16Request tx = Tx16Request(0x7ABF, payload, sizeof(payload));
//xbeeT.send(tx);

if (LS_state==0 || LS_state ==1){
  xbeeSerial.write(int8_t(LS_state));
  Serial.println(LS_state);
  //Serial.println("is the serial available");
   /*while(xbeeSerial.available()) { 
       
       
        data=xbeeSerial.read();
        Serial.println("reading");
        Serial.println(data);
   }*/
 
}

/*if (LS_state==0){
  
  xbeeSerial.write(LS_state);
  Serial.println(LS_state);
  data=xbeeSerial.read();
  Serial.println("reading");
  Serial.println(data);
}
if (LS_state==1){
  xbeeSerial.write("1");
 // Serial.println("1");
  data=xbeeSerial.read();
  Serial.println("reading:"+data);
}*/
//Serial.println(LS_state);
//xbeeSerial.write(LS_state);

}
