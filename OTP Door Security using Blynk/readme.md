# 🔐 OTP Door Security using Blynk

## 🔍 Overview
This project uses an ESP8266 to control a solenoid door lock, which can only be unlocked through a One-Time Password (OTP) generated and sent via the Blynk app. Ideal for smart home and school-level access control systems.

## 🧰 Components Used
- ESP8266 NodeMCU
- Keypad (4x4 or 4x3)
- Solenoid Lock or Relay with DC lock
- Blynk App (New Version)
- Jumper wires + Breadboard
- 5V external power supply for lock

## 🔐 How It Works
- The Blynk app sends a randomly generated 4-digit OTP to the user.
- User inputs the OTP on the keypad.
- If correct, the lock is activated for a short time and auto-locks again.

## 📱 Blynk App Setup
- Use Blynk IoT Cloud (https://blynk.cloud)
- Add widgets:
  - `Button` (send OTP) → Virtual Pin V0
  - `Notification` (wrong/correct OTP)
  - Optional `Terminal` for feedback

---

## 🔧 Wiring (Text Description)

**Keypad**
- Connect rows/columns to D2–D8 (adjust in code)

**Solenoid Lock or Relay Module**
- IN → D1 (GPIO5)
- VCC → VIN
- GND → GND

---

## ⚠️ Hardware Notes & Safety Precautions

### 🔐 Solenoid Lock / Relay
- Always use **external 5V–12V supply** for lock.
- Use **optocoupled relay** to prevent back-EMF affecting ESP.
- Add **flyback diode** across lock terminals if using direct drive.

### 🔢 Keypad
- Debounce logic may be required for fast keypresses.
- Keep wires short and tight; long wires may cause ghost inputs.

### 🧠 ESP8266
- Protect GPIO pins from 5V outputs.
- Add a **100 µF capacitor** to reduce reset issues on power surge.
