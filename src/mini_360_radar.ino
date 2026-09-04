#include <Stepper.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Stepper motor
#define stepsPerRevolution 2048

Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

// Ultrasonic sensor
int trig = 6;
int echo = 7;

int angle;
int distance;

long currentStep = 0;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  motor.setSpeed(10);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  display.setCursor(20, 10);
  display.println("MINI RADAR");

  display.setCursor(15, 30);
  display.println("360 DEGREE");

  display.display();

  delay(2000);

  display.clearDisplay();
  display.display();
}

void loop()
{
  for (angle = 0; angle <= 360; angle = angle + 5)
  {
    // Move motor to the required angle
    long targetStep = (long)(angle * 2048.0 / 360.0);

    long steps = targetStep - currentStep;

    motor.step(steps);

    currentStep = targetStep;

    delay(50);

    distance = getDistance();

    showDisplay();

    delay(100);
  }

  // 360 degrees is the same position as 0 degrees
  currentStep = 0;

  delay(200);
}

int getDistance()
{
  long duration;
  int dist;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 30000);

  if (duration == 0)
  {
    return 100;
  }

  dist = duration * 0.034 / 2;

  return dist;
}

void showDisplay()
{
  display.clearDisplay();

  // 50 cm or more means no object
  if (distance >= 50)
  {
    display.setCursor(0, 20);
    display.println("OBJECT : CLEAR");

    display.display();

    return;
  }

  // Less than 50 cm means object detected
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.println("360 RADAR");

  display.setCursor(0, 18);
  display.print("Angle: ");
  display.print(angle);
  display.println(" deg");

  display.setCursor(0, 32);
  display.print("Dist: ");
  display.print(distance);
  display.println(" cm");

  display.setCursor(0, 50);
  display.println("OBJECT: DETECTED");

  display.display();
}