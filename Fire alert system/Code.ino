#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "FireAlertSystem"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourWiFiSSID";
char pass[] = "YourWiFiPassword";

#define FLAME_SENSOR_PIN 34  // Digital output of flame sensor
#define BUZZER_PIN 25        // Buzzer pin

bool fireDetected = false;
bool alreadyNotified = false;

BlynkTimer timer;

void checkFire() {
  int flameValue = digitalRead(FLAME_SENSOR_PIN);
  fireDetected = (flameValue == LOW); // LOW means flame detected

  if (fireDetected) {
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.virtualWrite(V0, "🔥 Fire Detected!");
    Blynk.virtualWrite(V1, 255); // Virtual LED ON
    if (!alreadyNotified) {
      Blynk.logEvent("fire_alert", "🔥 Fire Detected!");
      alreadyNotified = true;
    }
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    Blynk.virtualWrite(V0, "✅ Safe");
    Blynk.virtualWrite(V1, 0); // Virtual LED OFF
    alreadyNotified = false;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, checkFire);
}

void loop() {
  Blynk.run();
  timer.run();
}
