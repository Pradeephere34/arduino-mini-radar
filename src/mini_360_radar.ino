#include <Stepper.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define STEPS_PER_REVOLUTION 2048
#define DETECTION_DISTANCE 50
#define MOTOR_PIN_1 8
#define MOTOR_PIN_2 10
#define MOTOR_PIN_3 9
#define MOTOR_PIN_4 11

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Stepper motor
Stepper motor(STEPS_PER_REVOLUTION, MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4);

// Ultrasonic sensor
const int trigPin = 6;
const int echoPin = 7;

int angle = 0;
int distance = 0;

long currentStep = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  motor.setSpeed(10);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while (true)
    {
    }
  }

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
    long targetStep = (long)(angle * (float)STEPS_PER_REVOLUTION / 360.0);

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

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0)
  {
    return 100;
  }

  dist = duration / 58;

  return dist;
}

void showDisplay()
{
  display.clearDisplay();

  // 50 cm or more means no object
  if (distance >= DETECTION_DISTANCE)
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