
int receiverCh8=3; // for fly sky
int ch8=0; // tracks receiver values as it is read

int R_en=7; // for hbridge
int L_en=8; // for hbridge
int RPWM=5; // for hbridge
int LPWM=6;// for hbridge

int Lswitch=2; // limit switch
int LS_state=0; // tracks limit switch state value: high/low as it is being read

//int8_t data = 0; //8 bit value, form of xbee message packets //LIMIT SWITCH
int numOfLoops = 0;

//easy button
int numOfZeros = 0;
int eButtonXBEE = 0;

void setup() 
{
  pinMode(receiverCh8,INPUT); 
 
  pinMode(R_en, OUTPUT);
  pinMode(L_en, OUTPUT);
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);

  pinMode(Lswitch,INPUT_PULLUP);
  //pinMode(pwm1, INPUT);
  
  Serial.begin(9600);
 }


void loop() {
    digitalWrite(R_en, HIGH);
    digitalWrite(L_en, HIGH);
    ch8=pulseIn(receiverCh8,HIGH,25000);
    //Serial.println(ch8);

    LS_state=digitalRead(Lswitch); //limit switch
    //Serial.println(LS_state);

    //LIMIT SWITCH FROM XBEE
    /*data=Serial.read(); //xbeeSerial.read()
    if (data>=1) {
        numOfLoops++;
    }*/

//100 loops == less than 1 sec
//500 loops == 10 secs
//1000 loops == 19 secs
//1500 loops == 25 secs


int LOOPS = 500; // how many loops we want to go through, corresponding to motor spin time

//EASY BUTTON XBEE
    eButtonXBEE=Serial.read(); //xbeeSerial.read()
    if (numOfZeros == 1 && eButtonXBEE != 0)
    {
      numOfZeros = 0;
    }
    else if (numOfZeros == 1 && eButtonXBEE == 0)
    {
      // two consecutive 0's, start motor
      numOfLoops++; // numOfLoops brings you to motor code
    }
    else if (numOfZeros == 0 && eButtonXBEE == 0)
    {
      numOfZeros++;
    }

// start motor for loop time
    if (numOfLoops == 1)
    {
        digitalWrite(RPWM, LOW); 
        digitalWrite(LPWM, HIGH);
        numOfLoops++;
    }

    if (numOfLoops > 1 && numOfLoops < LOOPS)
    {
        numOfLoops++;
    }

    if (numOfLoops == LOOPS)
    {
      numOfLoops = 0;
      digitalWrite(RPWM, LOW); 
      digitalWrite(LPWM, LOW);
    }
    
  //  FlySky controller transmitting data
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


 
