#include <Arduino.h>

//  Let's Code Blacksburg
//  IR sensor test code
//       (version .2 -tweeks )
//  
//  This code reads the three IR line follower sensors 
//  (Left, Middle and Right) on pins analog pins A0, A1 
//   and A2,  and outputs L for black line or _ for 
//   light surface (no line) on the serial monitor.

int sensorLeft=0;
int sensorMiddle=0;
int sensorRight=0;

const int LEFT=1;
const int RIGHT=2;
int last_turn=0;

int speed=90;
 

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

void goStraight() {
  motorRight(speed);
  motorLeft(speed);
}

void goRight() {
  motorRight(0);
  motorLeft(speed+40);
  last_turn=LEFT;
  
}

void goLeft() {
  motorRight(speed+40);
  motorLeft(0);
  last_turn=RIGHT;
}

void loop()
{
  // Sensor readings give you a 1 if it sees the black line
  // and a 0 if it sees white.
  
  sensorLeft=digitalRead(A0);    // Left uses analog A0
  sensorMiddle=0; //not working digitalRead(A1);  // Middle uses analog A1
  sensorRight=digitalRead(A2);   // Right uses analog A2
  
  int sensorBinary=(sensorLeft*4) + (sensorMiddle*2) + sensorRight;
  
  Serial.println(sensorBinary);
  
  switch (sensorBinary) {
    case 0:
      if (last_turn==LEFT) { 
        goLeft();
      }
      else if (last_turn==RIGHT) {
        goRight();
      }
      else {
        goStraight();
      }
      break;
    case 2:
    case 5:
    case 7:
      goStraight();
      break;
    case 1:
    case 3:
      goLeft();
      break;
    case 4:
    case 6:
      goRight();
      break;
  }
                               
//  if (sensorLeft==1) {        
//    Serial.print(" L ");
//  }
//  else {
//    Serial.print(" _ ");
//  }
// 
//  if (sensorMiddle==1) {        
//    Serial.print(" L ");
//  }
//  else {
//    Serial.print(" _ ");   
//  }
//  
//  if (sensorRight==1) {        
//    Serial.println(" L ");
//  }
//  else {
//    Serial.println(" _ ");   
//  }
  
}
