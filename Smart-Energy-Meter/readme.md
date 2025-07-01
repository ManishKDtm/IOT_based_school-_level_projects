# ⚡ IoT Energy Monitoring System (ESP32 + Web Dashboard)

## 🔍 Overview
This system uses ESP32 to measure energy parameters (like voltage, current, and power) using a sensor like **ACS712** or **ZMPT101B**, and displays them on a **real-time local web dashboard**. It’s perfect for educational labs and home automation.

---

## 🧰 Components Used
- ESP32 Dev Board
- ACS712 Current Sensor (5A or 20A)
- ZMPT101B Voltage Sensor (optional)
- Resistors/filters (optional)
- Load (bulb, fan, etc.)
- Jumper wires & breadboard

---

## ⚙️ Functionality
- Continuously reads analog current and voltage values
- Calculates **power = voltage × current**
- Displays real-time values on a **web interface hosted by ESP32**

---

## 🔧 Wiring (Example: ACS712 only)

**ACS712**
- VCC → 5V  
- GND → GND  
- OUT → GPIO 34 (analog input)

*(Optional) ZMPT101B*
- OUT → GPIO 35 (analog input)

---

## 🌐 Web Interface
- After uploading, ESP32 hosts a webpage at its local IP.
- Page refreshes every 3 seconds showing:
  - ⚡ Voltage (approximate)
  - 🔌 Current
  - 🔋 Power (watts)

---

## ⚠️ Notes & Safety
- Do not connect ACS712 directly to high-voltage lines without isolation.
- Use bulb or small motor for demo.
- ZMPT101B requires calibration (offset + scaling).
