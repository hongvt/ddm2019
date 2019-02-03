
int pwm1 = 6;
int pwm1_state = 0;
int numOfZeros = 0;
int led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(pwm1, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  pwm1_state = pulseIn(pwm1, HIGH);
  Serial.println(pwm1_state);
  if (numOfZeros == 1 && pwm1_state != 0)
  {
    numOfZeros = 0;
  }
  else if (numOfZeros == 1 && pwm1_state == 0)
  {
    //LED ON FOREVER
    //digitalWrite(led, HIGH);
    while (true)
    {
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(500);                       // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
      delay(500); 
    }
  }
  else if (numOfZeros == 0 && pwm1_state == 0)
  {
    numOfZeros++;
  }
}
