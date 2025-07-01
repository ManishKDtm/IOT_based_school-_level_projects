# 🔦 IoT Intrusion Laser Tripwire System

## 🔍 Overview
A laser beam falls on an LDR. When someone breaks the beam (i.e., blocks light), an intrusion alert is sent to the Blynk app.

---

## 🧰 Components
- ESP32  
- Laser diode (pointing at LDR)  
- LDR + 10kΩ resistor voltage divider  
- Blynk app

---

## ⚙️ Wiring

| Component | ESP32 Pin |
|-----------|-----------|
| LDR       | GPIO 34 (Analog)  
| Laser     | Powered by 3.3V or USB module

Place the laser beam directly on the LDR in a fixed alignment.

---

## 📱 Blynk Setup
- Label (V0): Status  
- Notification: “⚠️ Intrusion Detected!”
