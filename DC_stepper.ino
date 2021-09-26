// Conexiuni motoraș tracțiune (A)
int enA = 9;
int in1 = 8;
int in2 = 7;
// Conexiuni motoraș direcție (B)
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup()
{
  //controlul motorașelor
  
  // Setarea tuturor pinurilor de control al motarașelor ca și ieșiri 
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Oprirea motorașelor - Starea inițială
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  //senzorul de urmărie a liniilor
  Serial.begin(9600);
}

void loop()
{
  Serial.println(digitalRead(8));
  delay(50);
  directionControl();
}

// Această funcție permite controlul direcției de rotire al motorașelor
void directionControl()
{
  // Setarea motorașelor la viteză maximă
  // Pentru PWM valorile maxime posibile sunt 0-255
  analogWrite(enA, 100);//drive
  analogWrite(enB, 100);//directie
  
  // Pornire motor A și B
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  //HIGH și LOW = mers în față
  //LOW și HIGH = mers în spate
 
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  //HIGH și LOW = stânga
  //LOW și HIGH = dreapta
 
  delay(2000);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  //HIGH și LOW = stânga
  //LOW și HIGH = dreapta
  
  delay(2000);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  
  delay(5000);
    
  // Oprire motor A și B
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
