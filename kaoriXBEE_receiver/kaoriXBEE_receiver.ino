
#include <SoftwareSerial.h> //for setting pins 2 and 3 on the arduino to act as TX and RX
//#include <XBee.h>
//#define XBee Serial
SoftwareSerial xbeeSerial(2,3);


//XBee xbee = XBee();
//XBeeResponse response = XBeeResponse();
// create reusable response objects for responses we expect to handle 
//Rx16Response rx16 = Rx16Response();
//Rx64Response rx64 = Rx64Response();

//uint8_t option = 0;
//uint8_t data = 0;

//int data=0;
int8_t data = 0;
int led=7;

void setup() {
  Serial.begin(115200); //this baud rate must match that of the configured xbee
  //xbee.setSerial(Serial);
  xbeeSerial.begin(115200);
  pinMode(led,OUTPUT);

}

void loop() {
  //Serial.println("cereal is yum");
  /*xbee.readPacket();

  if (xbee.getResponse().isAvailable()) {
  
    if (xbee.getResponse().getApiId() == RX_16_RESPONSE || xbee.getResponse().getApiId() == RX_64_RESPONSE) {
          // got a rx packet
          
          if (xbee.getResponse().getApiId() == RX_16_RESPONSE) {
            xbee.getResponse().getRx16Response(rx16);
            option = rx16.getOption();
            data = rx16.getData(0);
          } else {
            xbee.getResponse().getRx64Response(rx64);
            option = rx64.getOption();
            data = rx64.getData(0);
          }
    }
  }*/
  if(xbeeSerial.available()) { //check to see if XBee is receiving
    data=xbeeSerial.read();
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
    
    //Serial.println("whatsup");
  }
}
