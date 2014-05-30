#include <Arduino.h>


const int ENB=3; //motor b enable
const int IN4=2; //motor b -
const int IN3=4; //motor b +

const int IN2=5; //motor a -
const int IN1=7; //motor a +
const int ENA=6; //motor a enable


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  
  //Motor A setup
  pinMode (ENA, OUTPUT); //motor A enable
  pinMode (IN2, OUTPUT); //motor a wire1 polarity
  pinMode (IN1, OUTPUT); //motor a wire 2 polarity
  
  //motor b setup
  pinMode (ENB, OUTPUT); //motor b enable
  pinMode (IN4, OUTPUT); //motor b wire1 polarity
  pinMode (IN3, OUTPUT); //motor b wire 2 polarity
  
  pinMode (13, OUTPUT); //led for testing
  
  //set polarity for motor a
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  
  //set polarity for motor b
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
}


void motorRight(int speed) {
  analogWrite(ENA,speed);
}

void motorLeft(int speed) {
  analogWrite(ENB, speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  int motorSpeedLeft=80; //any pwm range form 0-255
  int minSpeedLeft=motorSpeedLeft;
  int maxSpeedLeft=82;
  
  int motorSpeedRight=86; //any pwm range form 0-255
  int minSpeedRight=motorSpeedRight;
  int maxSpeedRight=88;
  
  while (motorSpeedLeft < maxSpeedLeft) {
    motorRight(motorSpeedRight);
    motorLeft(motorSpeedLeft);
    Serial.println(motorSpeedLeft + " " + motorSpeedRight);
    motorSpeedLeft+=2;
    motorSpeedRight+=2;
    delay(1000);
  }
  
  while (motorSpeedLeft > minSpeedLeft) {
    motorRight(motorSpeedRight);
    motorLeft(motorSpeedLeft);
    Serial.println(motorSpeedLeft + " " + motorSpeedRight);
    motorSpeedLeft-=2;
    motorSpeedRight-=2;
    delay(1000);
  }
 
  
//  digitalWrite(13, HIGH); //turn on led
//  analogWrite(ENA, 255); //set motor a speed 100%
//  analogWrite(ENB, 255); //set motor b speed 100%
//  
//  delay(3000);
//  
//  digitalWrite(13, LOW); //turn off led
//  analogWrite(ENA, 0); //set motor a speed 0%
//  analogWrite(ENB, 0); //set motor b speed 0%
//  
//  delay(3000);
  
}
