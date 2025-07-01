# 💡 IoT Smart Street Light System (ESP32 + LDR + PIR + Blynk)

## 🔍 Overview
An energy-efficient smart street light system that:
- Automatically turns **ON** the light when it's **dark**
- Activates **only when motion is detected** using PIR sensor
- Shows real-time status on Blynk

---

## 🧰 Components
- ESP32 Dev Board  
- LDR + 10kΩ resistor  
- PIR Motion Sensor (HC-SR501)  
- LED (or relay module for real light)  
- Blynk IoT App  
- Jumper wires

---

## 📱 Blynk Setup

1. **Template**: `SmartStreetLight`  
2. **Widgets**:  
   - Label V0 – Light Status (ON/OFF)  
   - LED V1 – Indicator  
   - Notification (optional)

---

## 🔧 Wiring

| Component     | ESP32 Pin |
|---------------|-----------|
| LDR Voltage Divider | GPIO 34 |
| PIR Sensor OUT      | GPIO 14 |
| LED / Relay Signal  | GPIO 25 |
