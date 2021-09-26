// Definirea senzorului de distanță
#define echoPin 13
#define trigPin 12
// Conexiuni motoraș tracțiune (A)
int enA = 9;
int in1 = 8;
int in2 = 7;
// Conexiuni motoraș direcție (B)
int enB = 3;
int in3 = 5;
int in4 = 4;
// Definirea vitezei de rulare și momentului de virare
int viteza_vehicul = 70; // [mV]
int viteza_viraj = 255; // [mV]
// Definirea distanței din față
long duration;
long distance;

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
}

void loop(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = duration/58.2;
  // Distanța în [cm]
  Serial.println (distance);
  
  analogWrite(enA, viteza_vehicul);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Mers înainte
  
  if (distance <= 27) {  
       analogWrite(enA, 0);
       digitalWrite(in1, LOW);
       digitalWrite(in2, LOW);
       analogWrite(enB, 0);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(1000000000);
       // Oprire bruscă în vederea evitării coliziunii față-spate 
  }
}
