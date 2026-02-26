# 👶 Baby Monitor System

Arduino-based infant temperature monitoring system with automatic SMS alerts.  
Continuously monitors baby's body temperature using MAX6675 thermocouple sensor and sends instant SMS notification via SIM900A GSM module when temperature reaches or exceeds 38°C.

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

📄 [Download Circuit Diagram PDF](Documentation/Baby_Monitor_Circuit.pdf)

*(You can also view the diagram in the project documentation)*

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
4. Update phone number in code
5. Select board: **Arduino Mega 2560**
6. Upload code to your Arduino

---

## 📱 Usage

1. Power on the system
2. System starts monitoring automatically
3. If temperature ≥ 38°C:
   - SMS alert sent immediately
   - After 60 seconds, system attempts to call
   - Call ends after 60 seconds
4. When temperature returns to normal, system resets

---

## 📁 Code Structure

| File | Description |
|------|-------------|
| `Code/Baby_Monitor.ino` | Main program with temperature monitoring and GSM control |

---

## 🔮 Future Improvements

- Add LCD display for local temperature reading
- Integrate with IoT platforms for cloud monitoring
- Add multiple phone numbers for alerts
- Include humidity monitoring
- Battery backup option
- Mobile app integration

---

## 📄 License

This project is for educational purposes only.

   
