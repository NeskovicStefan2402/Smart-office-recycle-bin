#include <Servo.h>
Servo myservo;
int trigPin = 6;
int echoPin = 7;
int motorPin = 3;
int servoPin = 9;
long duration;
long cm;
int poz;
void setup() {

  Serial.begin (9600);
  myservo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {



  int j = 0;
  for (j = 0; j >= 0; j++) {
    if (j % 20 == 0) {
      analogWrite(motorPin, 1000);
      delay(5000);
      analogWrite(motorPin, 0);
    } else {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(5);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
      cm = (duration / 2) / 29.1;
      if (cm < 30) {
        for (poz = 15; poz <= 90; poz += 1) {
          myservo.write(poz);
          delay(15);
        }
        delay(1000);
        for (poz = 90; poz >= 15; poz -= 1) {
          myservo.write(poz);
          delay(15);
        }
      } else {
        Serial.print(cm);
        Serial.println("cm");
      }
    }

    delay(1000);
  }



  delay(250);
}
