# 🧍‍♂️ Wearable Fall Detection Alert System

## 🔍 Overview
This wearable system uses an MPU6050 accelerometer to detect sudden falls based on high acceleration and angular motion. It alerts caregivers via the Blynk app with real-time notifications.

---

## 🧰 Components
- ESP32  
- MPU6050 Accelerometer (I2C)  
- Blynk App  
- Battery pack or USB

---

## ⚙️ Wiring

| MPU6050 Pin | ESP32 Pin |
|-------------|-----------|
| VCC         | 3.3V      |
| GND         | GND       |
| SDA         | GPIO 21   |
| SCL         | GPIO 22   |

---

## 📱 Blynk Setup
- **Template**: `FallAlertSystem`
- **Widgets**:
  - Label (V0): Fall Status
  - Notification
  - LED (V1): Status indicator

---

## ⚠️ Notes
- Thresholds must be calibrated based on sensitivity (tune based on testing)
- Ensure tight attachment to waist/chest for real-world use
