#include <SoftwareSerial.h>

//int Lswitch=7; //limit switch
//int LS_state=0; //limit switch

int pwm1 = 6;
int pwm1_state = 0;

//XBEE PIN INITIALIZATION
//Xbee's DOUT (TX) is connected to pin 2 (Arduinos Software RX)
//Xbee's DIN (RX) is conected to pin 3 (Arduino's Software TX)

SoftwareSerial xbeeSerial(2,3); //RX, TX)

void setup() {
  Serial.begin(9600);
  xbeeSerial.begin(9600);
  //pinMode(Lswitch, INPUT_PULLUP); //limit switch stuff
  pinMode(pwm1, INPUT);
}

void loop() {
   //EASY BUTTON
  pwm1_state = pulseIn(pwm1, HIGH);
  Serial.println(pwm1_state);
  xbeeSerial.write(int8_t(pwm1_state)); 
   
  //LIMIT SWITCH 
  /*LS_state=digitalRead(Lswitch);
    if (LS_state==0 || LS_state ==1){
      xbeeSerial.write(int8_t(LS_state));
      Serial.println(LS_state);
    }*/
}
