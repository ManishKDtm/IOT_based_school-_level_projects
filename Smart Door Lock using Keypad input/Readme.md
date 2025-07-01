# 🔐 Smart Door Lock using ESP32 + Keypad + Servo (Offline)

## 🔍 Overview
This project allows unlocking a door using a **4x4 or 4x3 keypad**. When the correct password is entered, the **servo motor unlocks the door**. No internet or app is needed — perfect for standalone smart locks.

---

## 🧰 Components Required
- ESP32 Dev Module  
- 4x4 Matrix Keypad  
- Servo Motor (SG90 recommended)  
- Jumper wires  
- (Optional) OLED Display for feedback

---

## 🔧 Wiring

**Keypad → ESP32 (example with 4x4)**
- R1 → GPIO 14  
- R2 → GPIO 27  
- R3 → GPIO 26  
- R4 → GPIO 25  
- C1 → GPIO 33  
- C2 → GPIO 32  
- C3 → GPIO 21  
- C4 → GPIO 22  

**Servo Motor**
- Signal → GPIO 18  
- VCC → 5V (external preferred)  
- GND → GND

---

## 🛠️ Functionality

- Enter 4-digit passcode (e.g., `1234`)
- Servo rotates to **unlock** position for 5 seconds
- Invalid input shows feedback via Serial or OLED
- System locks automatically after timeout

---

## ⚠️ Notes

- Use external power for servo to avoid ESP32 brownout
- You can add EEPROM to store password securely
- Reset pin via button can also be implemented
