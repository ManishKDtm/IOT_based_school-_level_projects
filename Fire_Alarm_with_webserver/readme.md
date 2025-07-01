# 🔥 IoT Fire Detection & Web Alert System (ESP32)

## 🔍 Overview
This system detects fire or sudden heat using a **flame sensor or temperature sensor**, and alerts the user via a **local web interface**. It can trigger a **buzzer or relay** for alarms and is suitable for smart homes, labs, or school fire safety demos.

---

## 🧰 Components Used
- ESP32 Dev Board
- Flame Sensor (Digital Output) or LM35 (Analog Output)
- Buzzer or Relay Module
- Wi-Fi (Local or Mobile Hotspot)
- Jumper Wires & Breadboard

---

## 💡 How It Works
- ESP32 continuously monitors the flame or heat level
- If fire is detected, an **alarm is triggered**
- Simultaneously, the **ESP32 hosts a web page** showing real-time status

---

## 🔧 Wiring (for Flame Sensor + Buzzer)

**Flame Sensor**
- VCC → 3.3V
- GND → GND
- D0 → GPIO 34 *(Input only)*

**Buzzer or Relay**
- IN → GPIO 26
- VCC → VIN or 5V
- GND → GND

*(You can replace the flame sensor with LM35 on analog pin if needed)*

---

## 🌐 Web Interface
After uploading code:
- Find ESP32’s IP via Serial Monitor
- Open that IP in browser
- Interface shows:
  - 🔥 “FIRE DETECTED” (Red warning)
  - ✅ “Safe” (Green background)

---

## ⚠️ Hardware Safety Notes

- Keep **flame sensor at least 5–10 cm** from open flames during test
- Use a **current-limited supply (e.g., via USB)** to avoid damaging ESP32
- Use **transistor control** if buzzer draws more current than ESP GPIO can handle

---
