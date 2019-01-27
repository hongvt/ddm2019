int Lswitch=13;
int LS_state=0;

void setup() {
  Serial.begin(9600);
  pinMode(Lswitch,INPUT_PULLUP);

}

void loop() {
 LS_state=digitalRead(Lswitch);
 Serial.println(LS_state);
}
