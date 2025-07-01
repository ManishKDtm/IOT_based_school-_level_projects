#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "SmartStreetLight"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define LDR_PIN 34
#define PIR_PIN 14
#define LIGHT_PIN 25

BlynkTimer timer;

void controlLight() {
  int lightVal = analogRead(LDR_PIN);      // Lower = dark
  int motionVal = digitalRead(PIR_PIN);    // HIGH = motion

  bool isDark = lightVal < 2000;           // Tune threshold
  bool motionDetected = (motionVal == HIGH);

  if (isDark && motionDetected) {
    digitalWrite(LIGHT_PIN, HIGH);
    Blynk.virtualWrite(V0, "💡 Light ON");
    Blynk.virtualWrite(V1, 255);
  } else {
    digitalWrite(LIGHT_PIN, LOW);
    Blynk.virtualWrite(V0, "🌙 Light OFF");
    Blynk.virtualWrite(V1, 0);
  }

  Serial.printf("Light: %d | Motion: %d\n", lightVal, motionVal);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_PIN, OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, controlLight);
}

void loop() {
  Blynk.run();
  timer.run();
}
