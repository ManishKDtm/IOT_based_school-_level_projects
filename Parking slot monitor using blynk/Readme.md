# 🅿️ IoT Smart Parking Slot Monitor (ESP32 + Ultrasonic + Blynk)

## 🔍 Overview
Detects whether a parking slot is free or occupied using an **ultrasonic sensor**. Sends real-time status to the **Blynk app** using ESP32 via WiFi.

---

## 🧰 Components
- ESP32 Dev Board  
- HC-SR04 Ultrasonic Sensor  
- Blynk IoT App (new)  
- Jumper Wires, Breadboard  
- (Optional) LED/Buzzer for local status

---

## 🧠 Logic
- If distance < 10cm → **Car Present**  
- If distance > 10cm → **Slot Empty**

---

## 🔧 Wiring

| HC-SR04 Pin | ESP32 Pin |
|-------------|-----------|
| VCC         | 5V        |
| GND         | GND       |
| TRIG        | GPIO 5    |
| ECHO        | GPIO 18   |

---

## 📱 Blynk Setup

1. Template Name: `ParkingSlotMonitor`  
2. Hardware: `ESP32`, Connection: `WiFi`  
3. Widgets:
   - **Label (V0)** → Slot Status (Occupied / Free)
   - **Notification** → "Slot Occupied" when detected
   - (Optional) Virtual LED (V1)

4. Add Event:  
   - ID: `slot_occupied`  
   - Message: "🚗 Slot is now occupied!"
