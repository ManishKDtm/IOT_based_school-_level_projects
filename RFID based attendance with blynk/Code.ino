#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "RFID_Attendance"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <SPI.h>
#include <MFRC522.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define SS_PIN 21
#define RST_PIN 22

MFRC522 rfid(SS_PIN, RST_PIN);
BlynkTimer timer;

// Example UID database
String knownUIDs[] = {"DE 1A 42 87", "43 B2 11 4F"};
String names[] = {"Manish", "Anita"};

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  SPI.begin();
  rfid.PCD_Init();
  Serial.println("RFID system ready");
}

void loop() {
  Blynk.run();
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  String uidStr = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uidStr += String(rfid.uid.uidByte[i], HEX);
    if (i < rfid.uid.size - 1) uidStr += " ";
  }
  uidStr.toUpperCase();

  int index = -1;
  for (int i = 0; i < sizeof(knownUIDs) / sizeof(knownUIDs[0]); i++) {
    if (uidStr == knownUIDs[i]) {
      index = i;
      break;
    }
  }

  if (index >= 0) {
    String message = names[index] + " ✔️ Checked In";
    Blynk.virtualWrite(V0, message);
    Blynk.logEvent("rfid_logged", names[index]);
    Serial.println(message);
  } else {
    Serial.println("Unknown Card");
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  delay(2000);
}
