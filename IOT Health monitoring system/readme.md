# ❤️ IoT Health Monitor: Temperature & Pulse Logger to Google Sheets (via IFTTT)

## 🔍 Overview
This IoT system monitors a person’s body temperature and heart rate using sensors, then sends the readings to Google Sheets via IFTTT webhooks over Wi-Fi. Ideal for health camps, school demos, or personal health tracking.

---

## 🧰 Components Used
- ESP8266 NodeMCU
- LM35 (or DS18B20) Temperature Sensor
- Pulse Sensor (KY-039 or generic)
- Wi-Fi Connection
- Jumper Wires, Breadboard

---

## 📦 IFTTT Setup for Google Sheets Logging

1. **Create IFTTT Account**
   - Go to: [https://ifttt.com](https://ifttt.com)

2. **Create Applet**
   - Click **Create → If This → Webhooks**
   - Choose `Receive a web request`  
     → Event name: `health_data`

3. **Then That → Google Sheets**
   - Choose: `Add row to spreadsheet`
   - Set sheet name: `Health_Log`
   - Set format: `{{Value1}},{{Value2}},{{OccurredAt}}`

4. **Get Webhook URL**
   - Go to: [https://ifttt.com/maker_webhooks](https://ifttt.com/maker_webhooks)
   - Click **Documentation**
   - Your URL will look like:  
     ```
     https://maker.ifttt.com/trigger/health_data/with/key/YOUR_IFTTT_KEY
     ```

---

## 🧠 Sensor Logic
- **LM35**: Outputs 10mV/°C → Multiply analog value by 0.488 for °C
- **Pulse Sensor**: Analog signal peaks during heartbeat; read it every second

---

## 🔧 Wiring Description

**LM35**
- VCC → 3.3V
- GND → GND
- OUT → A0

**Pulse Sensor**
- VCC → 3.3V
- GND → GND
- Signal → D1 (GPIO5)

---

## ⚠️ Hardware Notes & Safety Precautions

### 🌡️ LM35
- Use smooth analog readings; filter spikes with averaging
- Don't touch directly with wet hands

### ❤️ Pulse Sensor
- Should be placed on finger/earlobe for best reading
- May need analog smoothing via code

### 🌐 IFTTT Notes
- Log only every 5–10 seconds to avoid Google rate limits
- Make your IFTTT key private — don’t expose it in public code

---
