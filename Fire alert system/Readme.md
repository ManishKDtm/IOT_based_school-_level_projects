# 🔥 IoT Fire Alert System using ESP32 + Flame Sensor + Buzzer + Blynk

A compact and efficient IoT-based fire detection system designed using the ESP32 microcontroller. It monitors fire presence via an infrared (IR) flame sensor and sends real-time alerts through the Blynk app while activating a local buzzer for immediate response.

---

## 🚀 Features

- 🔥 Real-time fire detection
- 📱 Mobile notifications via Blynk IoT platform
- 🔔 Local buzzer alert system
- ✅ Safe status monitoring with live updates
- 🧠 Can be extended with fans or relays

---

## 🧰 Hardware Components

| Component       | Quantity |
|----------------|----------|
| ESP32 Dev Board| 1        |
| IR Flame Sensor| 1        |
| Passive Buzzer | 1        |
| Jumper Wires   | As needed|
| Breadboard     | 1        |

---

## 🔌 Wiring Diagram

| Sensor/Buzzer | ESP32 Pin |
|---------------|-----------|
| Flame DO      | GPIO 34   |
| Buzzer IN     | GPIO 25   |
| VCC (Both)    | 3.3V or 5V|
| GND           | GND       |

---

## 📲 Blynk Setup

1. Create a new template:  
   - **Name**: FireAlertSystem  
   - **Hardware**: ESP32  
   - **Connection**: WiFi

2. Add Widgets:  
   - **Label (V0)** – Displays "Safe" or "Fire Detected"  
   - **Notification** – Push alerts  
   - **(Optional)**: LED (V1) for status light

3. Go to **Device Events** → Add `fire_alert`:  
   - Message: `🔥 Fire detected! Take immediate action!`

---

## 🛠️ Getting Started

1. Flash the `code.ino` file using Arduino IDE or PlatformIO.  
2. Connect the hardware as per the wiring table.  
3. Set your Blynk credentials and WiFi SSID/password.  
4. Open Serial Monitor and test with a flame source.

---

## ⚠️ Precautions

- Use a candle or lighter only for testing — ensure adult supervision  
- Do not expose components directly to high heat or prolonged flames  
- Provide airflow to prevent smoke accumulation near the flame sensor


---

## 🧠 Author

**Manish KD**  
[GitHub](https://github.com/ManishKDtm) | [LinkedIn](https://www.linkedin.com/in/manish-kd-23b91a254)

---

## 🏷️ Tags
`ESP32` `IoT` `Fire Detection` `Blynk` `Flame Sensor` `School Project`
