# 👋 IoT Gesture-Controlled Light/Fan System

## 🔍 Overview
Use hand gestures to control devices like lights or fans using the APDS-9960 gesture sensor and ESP32. Useful for touchless control in hygiene-sensitive areas.

---

## 🧰 Components
- ESP32  
- APDS-9960 Gesture Sensor (I2C)  
- Relay module or LED  
- Blynk app (optional)

---

## ⚙️ Wiring

| APDS-9960 Pin | ESP32 Pin |
|---------------|-----------|
| VCC           | 3.3V      |
| GND           | GND       |
| SDA           | GPIO 21   |
| SCL           | GPIO 22   |

LED/Relay → GPIO 25

---

## 🤚 Supported Gestures
- **LEFT**: Turn OFF  
- **RIGHT**: Turn ON  
- (Extendable to UP/DOWN, etc.)
