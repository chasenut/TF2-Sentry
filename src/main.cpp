#include <Arduino.h>
#include <ESP32Servo.h>

Servo xServo;
Servo yServo;
int xServoPin = 27;
int yServoPin = 26;

int cycleTime = 3000;
int elapsedTime = 0;
int cycleCount = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Servo value: ");

  xServo.setPeriodHertz(50);
  xServo.attach(xServoPin, 500, 2500);

  yServo.setPeriodHertz(50);
  yServo.attach(yServoPin, 500, 2500);

  xServo.write(90);
  yServo.write(90);
  delay(2000);

  
}

void loop() {

  elapsedTime = millis();
  //Serial.println("millis: " + String(elapsedTime));
  cycleCount = floor(elapsedTime / cycleTime);
  //Serial.println("cycleCount: " + String(cycleCount));
  bool dir = cycleCount % 2 == 0 ? true : false;
  //Serial.println("dir: " + String(dir));
  double ratio = (double)(elapsedTime % cycleTime) / (double)cycleTime;
  double angle = dir ? ratio * 180 : 180 - ratio * 180;
  //Serial.println("angle: " + String(angle));
  //xServo.write(angle);


  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    double angle = input.toDouble();
    if (angle >= 85 && angle <= 105) {
      yServo.write(angle);
    }
    Serial.println("\nEnter Servo value: ");
  }
}

