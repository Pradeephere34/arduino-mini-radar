# Arduino Mini Radar

A 360-degree radar system using an Arduino Uno, 28BYJ-48 stepper motor, HC-SR04 ultrasonic sensor, and SSD1306 OLED display.

## Demo

[Watch the radar working](videos/radar-demo.mp4)

## Project Description

The project scans an area by rotating an HC-SR04 ultrasonic sensor in 5-degree steps. At every position, the sensor measures distance and the OLED shows the angle, distance, and detection status.

Objects closer than 50 cm are shown as detected.

## Components

- Arduino Uno
- 28BYJ-48 stepper motor
- ULN2003 stepper motor driver
- HC-SR04 ultrasonic sensor
- 0.96 inch SSD1306 OLED display
- Jumper wires
- 5V power supply

## Wiring

See [docs/wiring.md](docs/wiring.md) for the pin connections.

## Libraries

Install these libraries from the Arduino IDE Library Manager:

- Adafruit GFX Library
- Adafruit SSD1306

Stepper and Wire are included with the Arduino IDE.

## How It Works

1. The stepper motor starts at 0 degrees.
2. The motor moves 5 degrees.
3. The HC-SR04 measures the distance.
4. The OLED displays the angle, distance, and object status.
5. The motor continues scanning until 360 degrees, then starts again.

## Possible Applications

- Short-range obstacle detection
- A distance-scanning demo for robotics projects
- A basic parking or proximity warning prototype
- Classroom demonstrations of sensors and motor control

## Possible Applications

- Short-range obstacle detection
- A distance-scanning demo for robotics projects
- A basic parking or proximity warning prototype
- Classroom demonstrations of sensors and motor control
- Practice project for Arduino and embedded systems

This is a small prototype for learning and demonstrations. It is not intended for accurate industrial measurement or safety-critical use.

## Notes

The code uses approximately 2048 steps for one motor revolution. The angle is approximate because the actual result depends on the motor, power supply, and mechanical mounting. This project is intended for learning and demonstrations, not industrial measurement or safety-critical use.

## Future Improvements

- Add a graphical radar display
- Add a buzzer when an object is detected
- Improve motor angle calibration
- Store detected object positions
