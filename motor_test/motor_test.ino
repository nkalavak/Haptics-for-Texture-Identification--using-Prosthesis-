void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //FORWARD MOTION
  //LEFT WHEEL - PINS 10 AND 11
  /*digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  //RIGHT WHEEL - PINS 6 AND 5
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);*/
  
  analogWrite(10,0);
  analogWrite(11,180);
  analogWrite(5,0);
  analogWrite(6,180);
  


}
