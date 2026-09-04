# Arduino Mini Radar

A compact embedded scanning system that rotates an ultrasonic sensor through a 180-degree sweep, measures distance in 5-degree increments, and presents the scan output on an OLED display.

## Project Overview

This project combines a motor, an ultrasonic distance sensor, and an I2C OLED display into a single real-time embedded system. At each scan position, the controller records the measured distance and updates the display before moving to the next angle.

The project was built to practice **sensor integration, motor control, I2C communication, and embedded program structure**.

## Features

- Scans the surrounding area in 5-degree increments.
- Measures distance with an ultrasonic sensor.
- Displays scan information on an OLED screen.
- Demonstrates coordinated control of multiple hardware components.

## Hardware

| Component | Purpose |
| --- | --- |
| Arduino board | Runs the control and measurement logic |
| Ultrasonic sensor | Measures distance to nearby objects |
| Motor and driver | Rotates the sensor through the scan angles |
| I2C OLED display | Presents the scan output |
| Jumper wires and breadboard | Prototyping and connections |

## Technologies

- Embedded C / Arduino framework
- Ultrasonic sensing
- Motor control
- I2C communication
- OLED display interfacing

## How It Works

1. The controller positions the sensor at the beginning of the scan.
2. The motor rotates the sensor by 5 degrees.
3. The ultrasonic sensor measures the distance at that angle.
4. The controller updates the OLED display with the scan information.
5. The sequence repeats until the sweep is complete.

## Getting Started

### 1. Prepare the hardware

Connect the ultrasonic sensor, motor driver, and OLED display to the Arduino according to your circuit design. Record the exact pin mapping before uploading the program.

### 2. Open the sketch

Open the Arduino source file in the Arduino IDE or PlatformIO. Install the display and sensor libraries required by the sketch.

### 3. Verify configuration

Check the following before uploading:

- Arduino board and processor selection.
- Serial and I2C pin configuration.
- Ultrasonic trigger and echo pins.
- Motor control pins.
- OLED I2C address.

### 4. Upload and test

Upload the sketch, open the serial monitor if the project uses one, and test the scan with objects at different distances. Keep the motor and wiring clear during the first run.

## Future Improvements

- Add a wiring diagram and a system photograph.
- Add a live radar-style visualization through serial communication.
- Record scan measurements for later analysis.
- Improve handling of invalid or noisy sensor readings.
- Add a clear calibration procedure for the motor and sensor.

## Learning Outcomes

This project provided practical experience in integrating hardware modules, coordinating timed operations, reading sensor data, driving a display over I2C, and organizing an embedded prototype around a repeatable control loop.

## Author

**A. L. Pradeep Chowdhary**  
[GitHub](https://github.com/Pradeephere34) · [LinkedIn](https://www.linkedin.com/in/a-l-pradeep-chowdhary-800b76325/)
