# 🎓 IoT Attendance System (ESP32 + RFID + Blynk)

## 🔍 Overview
This project scans RFID cards using ESP32 and logs student attendance to the **Blynk IoT app**. Admins can view names, timestamps, and real-time presence remotely. Ideal for classrooms, offices, or access-controlled labs.

---

## 🧰 Components Used
- ESP32 Dev Board
- MFRC522 RFID Reader Module
- RFID Cards/Tags
- Blynk IoT App (New Platform)
- Jumper Wires, Breadboard

---

## 📱 Blynk App Setup

1. **Create Template**  
   - Name: `RFID_Attendance`
   - Hardware: ESP32
   - Connection: WiFi

2. **Add Widgets**
   - Terminal Widget on V0 → Display scanned user info
   - Notification Widget → Sends check-in success
   - *(Optional)* Table widget or SuperChart for logs

3. **Device Events**
   - `rfid_logged`: “User: @val marked present”

---

## 🔧 RFID Reader Wiring (MFRC522 to ESP32)

| MFRC522 Pin | ESP32 Pin |
|-------------|-----------|
| SDA         | GPIO 21   |
| SCK         | GPIO 18   |
| MOSI        | GPIO 23   |
| MISO        | GPIO 19   |
| RST         | GPIO 22   |
| 3.3V        | 3.3V      |
| GND         | GND       |

---

## ⚠️ Notes

- Use **3.3V for MFRC522** (5V may damage it)
- Avoid touching antenna area while scanning
- You can expand this system by adding EEPROM or Firebase for full database
