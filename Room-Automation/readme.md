# 🏠 IoT Room Automation with ESP32 & Blynk App

## 🔍 Overview
This system allows users to control a **fan and light remotely** using the Blynk IoT app. It also includes **automatic fan control** based on room temperature, making it ideal for school demos and smart home projects.

---

## 🧰 Components Required
- ESP32 Dev Board
- DHT11 or DHT22 Sensor (Temperature & Humidity)
- Relay Module (2-Channel or Single)
- Bulb & Fan (or LED + Motor as low-voltage demo)
- Blynk IoT App (New Platform)
- Jumper Wires, Breadboard

---

## 📱 Blynk IoT Setup (Step-by-Step)

1. **Create Template**
   - Name: `RoomControl`
   - Hardware: ESP32
   - Connection: WiFi
   - Save Template ID & Auth Token

2. **Add Widgets**
   - `Switch Widget` on V0 → Light
   - `Switch Widget` on V1 → Manual Fan
   - `Gauge Widget` on V2 → Temperature
   - *(Optional)* `Automation Rule` → Auto fan ON above 30°C

3. **Create Events (optional)**
   - `fan_auto_on`: "Fan turned ON automatically due to high temp"

---

## 🔧 Wiring

**Relays:**
- Relay1 IN → GPIO 25 → Light
- Relay2 IN → GPIO 26 → Fan
- VCC → 5V, GND → GND

**DHT11 Sensor:**
- VCC → 3.3V
- GND → GND
- Data → GPIO 27

---

## ⚠️ Precautions

- Use **5V relay modules** with proper isolation for AC loads
- DHT11 gives slower updates; for better accuracy, use **DHT22**
- If using 220V appliances, ensure **relay wiring is insulated and safe**
- Add **diode across motors or fan** if using DC loads

---
