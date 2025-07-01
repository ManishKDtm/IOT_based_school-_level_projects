# 💧 Smart Water Level Indicator (ESP32 + Ultrasonic + Blynk)

## 🔍 Overview
This system monitors the water level in a tank using an **HC-SR04 ultrasonic sensor** and shows the live percentage fill level on the **Blynk app**. You’ll get alerts when the tank is full or low, making it perfect for homes, schools, and rural areas.

---

## 🧰 Components Used
- ESP32 Dev Board  
- HC-SR04 Ultrasonic Sensor  
- Blynk IoT App (new platform)  
- Jumper wires, Breadboard  
- (Optional) Relay for pump automation

---

## 📱 Blynk Setup

1. **Create Template**  
   - Name: `WaterLevelMonitor`  
   - Hardware: ESP32  
   - Connection: WiFi

2. **Widgets**  
   - `Gauge V0` → Water Level (%)  
   - `Notification` → Water full or low  
   - *(Optional)* Button V1 → Pump ON/OFF

3. **Events**
   - `water_full` → “Water tank is full!”
   - `water_low` → “Water level is low!”

---

## 🔧 Wiring (HC-SR04)

| Sensor Pin | ESP32 Pin |
|------------|-----------|
| VCC        | 5V        |
| GND        | GND       |
| TRIG       | GPIO 5    |
| ECHO       | GPIO 18   |

---

## ⚠️ Calibration

- Define the **tank height** in cm (e.g., 40 cm)
- Mount the ultrasonic sensor at the top, pointing down
- Tune the mapping formula to suit your tank size
