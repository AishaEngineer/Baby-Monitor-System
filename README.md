# 👶 Baby Monitor System

Arduino-based infant temperature monitoring system with automatic SMS alerts. Continuously monitors baby's body temperature using MAX6675 thermocouple sensor and sends instant SMS notification via SIM900A GSM module when temperature reaches or exceeds 38°C.

---

## 📋 Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Components](#hardware-components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [Code Structure](#code-structure)
- [Future Improvements](#future-improvements)
- [License](#license)

---

## 🎯 Overview

This Baby Monitor System is designed to help parents monitor their infant's body temperature remotely. When the temperature rises above the safe threshold (38°C), the system automatically sends an SMS alert and optionally makes a phone call to notify parents immediately.

---

## ✨ Features

- **Real-time temperature monitoring** using MAX6675 thermocouple sensor
- **SMS alert** when temperature ≥ 38°C
- **Automatic phone call** option after SMS
- **GSM-based communication** (no WiFi needed)
- **Low power consumption** design
- **Easy to use** and setup

---

## 🔧 Hardware Components

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Mega 2560 | 1 | Main controller |
| MAX6675 Thermocouple Sensor | 1 | Temperature measurement |
| SIM900A GSM Module | 1 | SMS and call alerts |
| Breadboard | 1 | Prototyping |
| Jumper Wires | As needed | Connections |
| 12V Power Supply | 1 | Power for GSM module |

---

## 🔌 Circuit Diagram

---

## 🚀 Installation

### Prerequisites
- Arduino IDE (latest version)
- MAX6675 library (install via Library Manager)

### Steps
1. Clone this repository

2. Open `Code/Baby_Monitor.ino` in Arduino IDE
3. Install required library:
   - Go to **Sketch** → **Include Library** → **Manage Libraries**
   - Search for "MAX6675" and install
4. Update phone number in code:
   ```cpp
   // Replace with your phone number
   GSM_SERIAL.println("AT+CMGS=\"+967XXXXXXXXX\"");

   
