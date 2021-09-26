#define analogPin1;
#define analogPin2;

int analogPin1 = A0;
int analogPin2 = A1;

if (analogRead(analogPin1) == 0 && analogRead(analogPin2) == 0){

  // Rularea programului: 1. Modulul de asistență de menținere a benzii de rulare
  
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
  
}

if (analogRead(analogPin1) == 1 && analogRead(analogPin2) == 1){

  // Rularea programului: 2. Modulul de asistență de frânare autonomă de urgență
  
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
  int viteza_vehicul = 110; // [mV]
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
  
    if (distance <= 10) {  
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
  
}

if (analogRead(analogPin1) == 0 && analogRead(analogPin2) == 1){

  // Rularea programului: 3. Modulul de asistență de depășire autonomă
  
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
  int viteza_vehicul = 110; // [mV]
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
    distance = duration/58.2; //Distanța în [cm]
    Serial.println (distance);
    
    analogWrite(enA, viteza_vehicul);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Mers înainte

    if (distance <= 20) {
       analogWrite(enA, 130);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       // Mărirea vitezei pentru depășire
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       delay(250);
       // Viraj stânga

       analogWrite(enA, 130);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
       delay(100);
       // Viraj dreapta pentru corectare

       analogWrite(enA, 130);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enB, 0);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(300);
       // Mers înainte

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       // Mers mai departe cu viteză constantă
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, LOW);
       digitalWrite(in4, HIGH);
       delay(700);
       //Viraj dreapta

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enB, viteza_viraj);
       digitalWrite(in3, HIGH);
       digitalWrite(in4, LOW);
       delay(500);
       // Viraj stânga pentru corectare

       analogWrite(enA, viteza_vehicul);
       digitalWrite(in1, HIGH);
       digitalWrite(in2, LOW);
       analogWrite(enB, 0);
       digitalWrite(in3, LOW);
       digitalWrite(in4, LOW);
       delay(700);
       // Mers înainte

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
  
}

if (analogRead(analogPin1) == 1 && analogRead(analogPin2) == 0){

  // Rularea programului: 4. Modulul de asistență de parcare paralelă autonomă
  
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
  
}
