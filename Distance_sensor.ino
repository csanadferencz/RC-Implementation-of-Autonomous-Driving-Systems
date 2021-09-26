#define echoPin1 11
#define trigPin1 10
#define echoPin2 13
#define trigPin2 12

long duration;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode (echoPin1, INPUT);
  pinMode (trigPin1, OUTPUT);
  pinMode (echoPin2, INPUT);
  pinMode (trigPin2, OUTPUT);
}

void loop() {
 digitalWrite(trigPin1, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin1, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin1,LOW);
 duration = pulseIn (echoPin1, HIGH);
 distance = duration/58.2; //Distanța în [cm]
 Serial.println (distance);
 delay(500); //Întârziere în [ms]

 digitalWrite(trigPin2, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin2, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin2,LOW);
 duration = pulseIn (echoPin2, HIGH);
 distance = duration/58.2; //Distanța în [cm]
 Serial.println (distance);
 delay(500); //Întârziere în [ms] 
} 
