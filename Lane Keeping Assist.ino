// Definirea senzorilor de urmărire linie
int senzor_stanga = 6;
int senzor_dreapta = 2;
// Conexiuni motoraș tracțiune (A)
int enA = 9;
int in1 = 8;
int in2 = 7;
// Conexiuni motoraș direcție (B)
int enB = 3;
int in3 = 5;
int in4 = 4;
// Definirea vitezei de rulare și momentului de virare
int viteza_vehicul = 100; // [mV]
int viteza_viraj = 200; // [mV]
long int stop1;

void setup(){
  pinMode(senzor_stanga, INPUT);
  pinMode(senzor_dreapta, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
  stop1 = millis() + 11800; // timpul [s] până la oprire
}

void loop(){
  if (millis() < stop1) {
       Serial.println(digitalRead(senzor_stanga));
       Serial.println(digitalRead(senzor_dreapta));
            if (digitalRead(senzor_stanga) == 1 && digitalRead(senzor_dreapta) == 1) {
                 analogWrite(enA, viteza_vehicul);
                 digitalWrite(in1, HIGH);
                 digitalWrite(in2, LOW);
                 analogWrite(enB, 0);
                 digitalWrite(in3, LOW);
                 digitalWrite(in4, LOW);
                 // Mers înainte
            }
  
            else if (digitalRead(senzor_stanga) == 0 && digitalRead(senzor_dreapta) == 0) {
                 analogWrite(enA, 0);
                 digitalWrite(in1, LOW);
                 digitalWrite(in2, LOW);
                 analogWrite(enB, 0);
                 digitalWrite(in3, LOW);
                 digitalWrite(in4, LOW);  
                 // Stop 
            }

            else if (digitalRead(senzor_stanga) == 1 && digitalRead(senzor_dreapta) == 0) {
                 analogWrite(enA, viteza_vehicul);
                 digitalWrite(in1, HIGH);
                 digitalWrite(in2, LOW);
                 analogWrite(enB, viteza_viraj);
                 digitalWrite(in3, HIGH);
                 digitalWrite(in4, LOW);
                 // Viraj stânga
            }

            else if (digitalRead(senzor_stanga) == 0 && digitalRead(senzor_dreapta) == 1) {
                 analogWrite(enA, viteza_vehicul);
                 digitalWrite(in1, HIGH);
                 digitalWrite(in2, LOW);
                 analogWrite(enB, viteza_viraj);
                 digitalWrite(in3, LOW);
                 digitalWrite(in4, HIGH);
                 // Viraj dreapta
            }
  }

  else {
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
