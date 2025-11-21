# Arduino Temperature & Gas Monitoring System

This project is an Arduino-based multi-sensor monitoring system designed in **Tinkercad**.  
It measures **temperature** and **gas levels**, sends the data via **Bluetooth**, displays readings on a **16×2 LCD**, and controls a **servo motor** based on sensor conditions.

---

## 📌 Features

- 🌡️ **Temperature Monitoring (LM35 or similar sensor)**
- 🧪 **Gas Detection (MQ-series sensor)**
- 📟 **16×2 LCD Display** for real-time temperature output
- 📲 **Bluetooth Communication (HC-05)** for wireless data transmission
- 🔄 **Servo Motor Control** triggered by sensor values
- 🔧 Fully simulated using **Tinkercad**

---

## 📁 Project Contents

- `code.ino` — Arduino source code (downloaded from Tinkercad)
- Circuit design (Tinkercad build)
- README and documentation

---

## 🛠️ Hardware Components

- Arduino Uno (x2 if using master/slave setup)
- LM35 temperature sensor
- MQ gas sensor
- HC-05 Bluetooth module
- Servo motor (SG90 or similar)
- 16×2 LCD (with potentiometer)
- Breadboard + jumper wires
- USB cable or external power supply

---

## 🔌 Wiring Overview

### Temperature Sensor
- Signal → A0  
- VCC → 5V  
- GND → GND  

### Gas Sensor
- Signal → A1  
- VCC → 5V  
- GND → GND  

### Bluetooth (SoftwareSerial on pins 10 & 11)
- TX → Pin 10  
- RX → Pin 11  
- VCC → 5V  
- GND → GND  

### LCD (16×2)
- RS → Digital pin 12  
- EN → Digital pin 11  
- D4 → Pin 5  
- D5 → Pin 4  
- D6 → Pin 3  
- D7 → Pin 2  
- Potentiometer for contrast

### Servo Motor
- Signal → PWM pin (typically pin 9)
- VCC → 5V
- GND → GND

---

## 🧠 How It Works

1. The Arduino reads:
   - Analog temperature from A0  
   - Gas concentration from A1  
2. Converts sensor values into readable temperature (°C) and gas level.
3. Prints data to:
   - Bluetooth module  
   - Serial Monitor  
   - LCD display  
4. Servo motor can respond based on threshold values (optional behavior).

---

## 📡 Serial & Bluetooth Output Example


