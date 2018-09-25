/* automated door open and close system */

#include <Servo.h>
Servo myservo;
int pos = 0;

int const trigPin = 10;
int const echoPin = 9;

int const ledPin = 2;

void setup() {
  myservo.attach(4);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  int pos;
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;

  if (distance <= 15 && distance >= 0){
    digitalWrite(ledPin, HIGH);
    for(pos = 0; pos <= 180; pos +=1){
        myservo.write(pos);
      }
    
  }

  else{
    digitalWrite(ledPin, LOW);
    for(pos = 180; pos >= 0; pos -=1){
        myservo.write(pos);
      }
  }

  delay(1000);

}
