# 🗑️ IoT Garbage Level Monitor (Blynk App)

## 🔍 Overview
This project detects the fill level of a dustbin using an ultrasonic sensor and notifies the user through the Blynk app when the garbage reaches a critical height. It promotes smart city cleanliness and waste management awareness.

## 🧰 Components Used
- ESP8266 NodeMCU
- Ultrasonic Sensor (HC-SR04)
- Blynk IoT App (New version)
- Jumper Wires + Breadboard
- Micro USB Cable for Power

## 📱 Blynk App Configuration
1. Go to [https://blynk.cloud](https://blynk.cloud)
2. Create a new **template** (Name: SmartBin)
3. Add a device under the template
4. Add Widgets:
   - `Gauge` (linked to Virtual Pin V1) → Shows Distance
   - `Notification` (Optional) → For alerts

## 🔧 Working Principle
The HC-SR04 sensor continuously measures the distance to the garbage top. When the distance drops below a set threshold (e.g., 10 cm), the system triggers a Blynk notification indicating that the bin is nearly full.

---

## ⚙️ Wiring Diagram (Text Description)

**Ultrasonic Sensor (HC-SR04) → ESP8266 NodeMCU**
- VCC → 5V (or VIN)
- GND → GND
- TRIG → D5 (GPIO 14)
- ECHO → D6 (GPIO 12) — *Use voltage divider: 2kΩ + 1kΩ*

---

## ⚠️ Hardware Notes & Safety Precautions

### 🧠 Microcontroller (ESP8266)
- Use only **3.3V logic** — protect input pins using resistors.
- Avoid powering multiple components from **ESP8266’s 3.3V pin**; use VIN or external supply.
- Add a **100–470µF capacitor** across 3.3V and GND to stabilize Wi-Fi resets.

### 🔊 Ultrasonic Sensor (HC-SR04)
- HC-SR04 **outputs 5V on ECHO**, while ESP8266 accepts **3.3V**. Always use a **voltage divider** to step it down.
- Keep sensor steady and mounted vertically to avoid false readings.

### 🔧 General
- Use solid jumper wires or screw terminals to ensure tight connections.
- If placing outdoors or near metal bins, use weatherproof casing.
