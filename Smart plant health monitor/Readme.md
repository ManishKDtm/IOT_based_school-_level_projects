# 🌱 Smart Plant Monitoring System (ESP32 + Blynk)

## 🔍 Overview
This IoT system helps monitor the health of indoor/outdoor plants using a **soil moisture sensor**, **temperature**, and **humidity sensors**. It notifies users via Blynk and even activates irrigation when the plant is too dry.

---

## 🧰 Components Used
- ESP32 Dev Module
- Capacitive Soil Moisture Sensor
- DHT11 or DHT22 (Temp & Humidity)
- Relay Module + Mini Pump (optional)
- Blynk IoT App (new version)
- Jumper Wires, Breadboard, 5V Pump

---

## 📱 Blynk App Configuration (New Platform)

1. **Create Template**
   - Name: `PlantMonitor`
   - Hardware: ESP32
   - Connection: WiFi
   - Save Template ID & Auth Token

2. **Add Widgets**
   - `Gauge V0` → Soil Moisture (%)
   - `Gauge V1` → Temperature (°C)
   - `Gauge V2` → Humidity (%)
   - `Switch V3` → Manual Watering
   - *(Optional)* Event `auto_watered`

3. **Automation**
   - Add a rule: If soil moisture < 30%, trigger `V3 = 1` to turn on watering

---

## 🔧 Wiring Instructions

**Soil Moisture Sensor**
- VCC → 3.3V  
- GND → GND  
- OUT → GPIO 34 (Analog Input)

**DHT Sensor**
- VCC → 3.3V  
- GND → GND  
- Data → GPIO 27

**Relay + Pump**
- Relay IN → GPIO 26  
- Relay VCC → 5V  
- GND → GND  
- Connect pump in NO-COM terminals of relay

---

## ⚠️ Notes & Safety

- Use **capacitive soil sensor**, not resistive (for longer life)
- Power pump from **external 5V source**
- Avoid placing DHT sensor near water or soil
- Always test watering delay to avoid overwatering
