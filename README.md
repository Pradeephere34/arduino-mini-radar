# Arduino Mini Radar

Arduino Uno project that rotates an HC-SR04 ultrasonic sensor and shows distance readings on an SSD1306 OLED display.

## Demo

[Watch the radar working](videos/radar-demo.mp4)

## What it does

The 28BYJ-48 motor moves the sensor in 5-degree steps. At each position, the Arduino measures the distance and updates the OLED with the angle, distance, and detection status. Objects closer than 50 cm are marked as detected.

```
0° → 5° → 10° → 15° → ... → 355° → 360°
```

## Hardware

- Arduino Uno
- 28BYJ-48 Stepper Motor
- ULN2003 Stepper Motor Driver
- HC-SR04 Ultrasonic Sensor
- 0.96 inch SSD1306 OLED Display
- Jumper wires
- 5V power supply

## Wiring

See [docs/wiring.md](docs/wiring.md) for the pin connections.

## Libraries

Install these libraries using the Arduino IDE Library Manager:

- Adafruit GFX Library
- Adafruit SSD1306

`Stepper` and `Wire` are included with the Arduino IDE.

## Possible Applications

- Short-range obstacle detection
- A distance-scanning demo for robotics projects
- A basic parking or proximity warning prototype
- Classroom demonstrations of sensors and motor control
- Practice project for Arduino and embedded systems

This is a small prototype for learning and demonstrations. It is not intended for accurate industrial measurement or safety-critical use.

## Notes

The code uses 2048 steps for one motor revolution. The angle is approximate because the actual result depends on the motor, power supply, and mechanical mounting.
