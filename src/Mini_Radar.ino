#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

Servo motor;   // 360 continuous motor

int trig = 9;
int echo = 10;
int motorPin = 6;

int distance;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  motor.attach(motorPin);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Mini Radar 360");
  display.display();
  delay(1000);

  // start rotating
  motor.write(0);   // full speed one direction
}

void loop() {
  distance = calculateDistance();
  showOnOLED(distance);
  delay(100);
}

int calculateDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH);
  int dist = duration * 0.034 / 2;

  if (dist > 200 || dist <= 0) {
    dist = 200;
  }

  return dist;
}

void showOnOLED(int dist) {
  display.clearDisplay();

  display.setCursor(0, 0);
  display.println("360 Radar");

  display.setCursor(0, 20);
  display.print("Dist: ");
  display.print(dist);
  display.println(" cm");

  display.setCursor(0, 45);
  if (dist < 20) {
    display.println("OBJECT DETECTED");
  } else {
    display.println("Scanning...");
  }

  display.display();
}
