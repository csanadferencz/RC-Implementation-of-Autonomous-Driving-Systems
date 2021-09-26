void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(8));
  //Serial.println("senzorst");
  //Serial.println(digitalRead(2));
  //Serial.println("senzordr");
  delay(500);
}
