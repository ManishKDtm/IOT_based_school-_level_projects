# 🔐 IoT Smart Door Lock with OTP via Blynk

## 🔍 Overview
This system allows users to control a solenoid door lock by entering an OTP (One-Time Password) sent to them via the Blynk IoT app. It uses a keypad, ESP8266 NodeMCU, and a relay module to drive the lock mechanism.

---

## 🧰 Components Required
- ESP8266 NodeMCU
- 4x4 or 4x3 Keypad
- Relay Module (for lock control)
- Solenoid Door Lock or DC Lock
- Blynk IoT App (New version, not Legacy)
- Jumper Wires, Breadboard
- 5V Power Source (for lock)

---

## 📱 Blynk IoT App Setup Guide (New Platform)

1. **Create an Account**
   - Visit [https://blynk.cloud](https://blynk.cloud) and sign up.
   - Or install the **Blynk IoT app** from Play Store / App Store.

2. **Create a New Template**
   - Go to **Templates → New Template**
   - Name: `Smart Door Lock`
   - Hardware: `ESP8266`
   - Connection Type: `WiFi`
   - Save the `Template ID`, `Device Name`, and `Auth Token`

3. **Add a Device**
   - Go to **Devices → New Device → From Template**
   - Select your newly created template
   - Give your device a name (e.g., "HomeDoor")

4. **Add Widgets to Dashboard**
   - **Button Widget (Virtual Pin V0)**  
     → Used to trigger OTP generation
   - **Notification Widget**  
     → Displays unlock success or failure
   - *(Optional)* **Terminal Widget** for debug logs

5. **Enable Events for Notifications**
   - Go to **Template → Events**
   - Add:
     - `otp_generated` → Message: `"Your OTP is: @val"`
     - `otp_success` → Message: `"✅ Door Unlocked Successfully"`
     - `otp_fail` → Message: `"❌ Wrong OTP Attempt"`

6. **Link the Auth Token**
   - Copy the `Auth Token` into the Arduino code

---

## 🔧 Wiring Diagram (Text Description)

**Keypad (4x4)**
- R1 → D2  
- R2 → D3  
- R3 → D4  
- R4 → D5  
- C1 → D6  
- C2 → D7  
- C3 → D8  
- C4 → D0  

**Relay Module**
- IN  → D1 (GPIO5)  
- VCC → VIN  
- GND → GND

**Solenoid Lock**
- Connect through relay (NO-COM)
- External 5V/12V power supply

---

## ⚠️ Hardware Notes & Safety Precautions

### 🧠 ESP8266 NodeMCU
- Use a stable 5V USB adapter (500mA+) for Wi-Fi stability
- Avoid exceeding GPIO voltage levels (use logic protection if needed)

### 🔢 Keypad
- Keep wiring short to avoid signal noise
- Mount it securely to avoid key bouncing issues

### 🔐 Relay & Lock
- Use **external power** for solenoid lock (not from ESP board)
- Add a **flyback diode** across lock terminals if powered directly
- Use an **optocoupler-based relay** for isolation

---

📱 *Once uploaded and connected, you can generate OTP from Blynk and enter it on the keypad to unlock the system securely.*
