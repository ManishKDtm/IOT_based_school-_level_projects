# 🛑 IoT Gas Leakage Detector (ESP32 + MQ2 + Blynk)

## 🔍 Overview
This system detects the presence of combustible gases (like LPG, methane, smoke) using an **MQ2 gas sensor**. When gas levels cross a threshold, it triggers a **buzzer alert** and sends a **notification via the Blynk app**.

---

## 🧰 Components Required
- ESP32 Dev Board  
- MQ2 Gas Sensor  
- Buzzer or Relay (for fan control)  
- Blynk IoT App  
- Jumper Wires, Breadboard

---

## 📱 Blynk Configuration

1. **Create Template**
   - Name: `GasAlertSystem`  
   - Hardware: ESP32  
   - Connection: WiFi

2. **Widgets**
   - `Gauge V0` → Gas Level (%)  
   - `Notification` → Gas Alert  
   - *(Optional)* LED indicator or chart

3. **Device Event**
   - Event ID: `gas_alert` → “⚠️ Gas Leakage Detected!”

---

## 🔧 Wiring

**MQ2 Gas Sensor**
- VCC → 5V  
- GND → GND  
- AO (Analog Out) → GPIO 34 *(for gas level)*  
- DO (Digital Out, optional) → GPIO 26 *(for binary alert)*

**Buzzer**
- IN → GPIO 25  
- VCC → 3.3V or 5V  
- GND → GND

---

## ⚠️ Safety & Calibration Notes

- Preheat MQ2 for ~20 seconds after power-on
- Do **not expose to flames or liquids**
- Place the sensor ~10–20 cm above the potential gas source
- Threshold value may need tuning (typically raw > 600)

---
