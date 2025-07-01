# 🗑️ IoT Smart Dustbin with Auto Lid & Fill Monitoring (ESP32 + Blynk)

## 🔍 Overview
This smart dustbin opens its lid automatically when a person approaches and monitors its fill level using an ultrasonic sensor. Fill level is updated live on the Blynk IoT app, making it useful for smart city waste management and hygiene awareness demos.

---

## 🧰 Components Used
- ESP32 Dev Board  
- HC-SR04 Ultrasonic Sensor  
- Servo Motor (SG90/MG995)  
- Blynk IoT App (new)  
- Jumper wires, 5V supply

---

## 📱 Blynk Setup

1. **Create Template**  
   - Name: `SmartDustbin`  
   - Hardware: ESP32  
   - Connection: WiFi

2. **Add Widgets**  
   - `Gauge V0` → Fill level (%)  
   - `Notification` → Trigger alert when full  
   - *(Optional)* `Label` or `Image` for status

3. **Event Setup**  
   - Event: `bin_full` → Message: “Dustbin is full! Please empty it.”

---

## 🔧 Wiring

**HC-SR04**  
- VCC → 5V  
- GND → GND  
- TRIG → GPIO 5  
- ECHO → GPIO 18  

**Servo Motor**  
- Signal → GPIO 19  
- VCC → 5V (external recommended)  
- GND → GND  

---

## ⚠️ Precautions

- Use a separate 5V source for servo (avoid drawing from ESP32 3.3V)
- Keep ultrasonic sensor vertical for better accuracy
- Fix dustbin height in code to calibrate fill level calculation

---
