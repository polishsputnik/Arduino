#include <Arduino.h>

const int triggerPin=12;
const int echoPin=13;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(echoPin, INPUT);
  pinMode(triggerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  long duration, inches;
  
  pinMode (triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  
  inches = duration / 74 / 2;
  
  Serial.print(inches);
  Serial.println("in, ");
  
  delay(100);
}
