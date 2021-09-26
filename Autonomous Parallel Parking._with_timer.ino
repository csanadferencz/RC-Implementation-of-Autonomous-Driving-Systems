// Definirea senzorului de distanță
#define echoPin 11
#define trigPin 10
// Conexiuni motoraș tracțiune (A)
int enA = 9;
int in1 = 8;
int in2 = 7;
// Conexiuni motoraș direcție (B)
int enB = 3;
int in3 = 5;
int in4 = 4;
// Definirea vitezei de rulare și momentului de virare
int viteza_vehicul = 50; // [mV]
int viteza_viraj = 200; // [mV]
// Definirea distanței laterale
long duration;
long distance;
// Definirea spațiului desemnat pentru parcare
long int parcare;

void setup(){
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  parcare = millis() + 2000;
}

void loop(){
  while (millis() < parcare && distance < 20){
       digitalWrite(trigPin, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin,LOW);
       duration = pulseIn (echoPin, HIGH);
       distance = duration/58.2; //Distanța în [cm]
       Serial.println (distance);

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       // Mers înainte
  }

  analogWrite(enA, 0);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  // Stop
  delay(1000);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = duration/58.2; //Distanța în [cm]
  Serial.println (distance);

  if (distance > 20) {
       analogWrite(enA, 0);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       delay(2500);

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
       delay(1250);
       //Mers înapoi cu viraj dreapta

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, LOW);
       digitalWrite(in2, HIGH);
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       delay(950);
       // Mers înapoi cu viraj stânga

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enB, 0);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(450);
       // Mers înainte pentru corectare

       analogWrite(enA, 0);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       analogWrite(enB, 0);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(1000000000);
       // Stop
  }
}
