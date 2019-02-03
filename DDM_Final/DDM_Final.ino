
int receiverCh8=3; // for fly sky
int ch8=0; // tracks receiver values as it is read

int R_en=7; // for hbridge
int L_en=8; // for hbridge
int RPWM=5; // for hbridge
int LPWM=6;// for hbridge

int Lswitch=2; // limit switch
int LS_state=0; // tracks limit switch state value: high/low as it is being read

int8_t data = 0; //8 bit value, form of xbee message packets
int numOfLoops = 0;

void setup() 
{
  pinMode(receiverCh8,INPUT); 
 
  pinMode(R_en, OUTPUT);
  pinMode(L_en, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(Lswitch,INPUT_PULLUP);

  Serial.begin(9600);
 }


void loop() {
    digitalWrite(R_en, HIGH);
    digitalWrite(L_en, HIGH);
    ch8=pulseIn(receiverCh8,HIGH,25000);
    //Serial.println(ch8);
    LS_state=digitalRead(Lswitch); //limit switch
    //Serial.println(LS_state);
    
    data=Serial.read(); //xbeeSerial.read()
    if (data>=1) {
      
       //while (numOfLoops < 100)
        //{
          digitalWrite(RPWM, LOW); 
          digitalWrite(LPWM, HIGH);
          //delay(5000);
          //digitalWrite(RPWM, LOW); 
          //digitalWrite(LPWM, LOW);
          //numOfLoops++;
        //}
    }
       
    if (ch8 >= 900 && ch8 <=1100) //switch on transmitter is upward position= FORWARD
    { 
        digitalWrite(RPWM, LOW); 
        digitalWrite(LPWM, HIGH);    
    }
    if (ch8 >= 1400 && ch8 <=1500) //switch on transmitter is in middle position= STOP 
    { 
        digitalWrite(RPWM, LOW);
        digitalWrite(LPWM, LOW);
    }
    if (ch8 >=1900 && ch8 <= 2000) // switch on transmitter is in downward position= BACKWARDS
    { 
        digitalWrite(RPWM, HIGH);
        digitalWrite(LPWM, LOW);
        if (LS_state==1) // check the state of the limit switch while backward spinning, if depressed
        {
            digitalWrite(RPWM, LOW);
            digitalWrite(LPWM, LOW); // cuts power to motor
            if (ch8 >= 900 && ch8 <=1100) // if transmitter switch is switched up, spin in opposite direction (forward)
            { 
                digitalWrite(RPWM, LOW);
                digitalWrite(LPWM, HIGH);
            }
        }
    }

}


 
