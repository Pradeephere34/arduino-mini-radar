# Wiring

## Arduino Uno

### Stepper Motor

The 28BYJ-48 motor is connected to the ULN2003 driver.

```
ULN2003 IN1 → Arduino D8
ULN2003 IN2 → Arduino D9
ULN2003 IN3 → Arduino D10
ULN2003 IN4 → Arduino D11
```

### Ultrasonic Sensor

```
HC-SR04 TRIG → Arduino D6
HC-SR04 ECHO → Arduino D7
HC-SR04 VCC → 5V
HC-SR04 GND → GND
```

### OLED

```
OLED SDA → Arduino A4
OLED SCL → Arduino A5
OLED VCC → 5V
OLED GND → GND
```