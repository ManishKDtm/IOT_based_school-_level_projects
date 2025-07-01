#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "LaserTripwire"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define LDR_PIN 34
int threshold = 1500; // Tune based on light conditions

BlynkTimer timer;
bool triggered = false;

void checkIntrusion() {
  int lightValue = analogRead(LDR_PIN);
  Serial.print("LDR: "); Serial.println(lightValue);

  if (lightValue < threshold && !triggered) {
    Blynk.virtualWrite(V0, "⚠️ Intrusion Detected");
    Blynk.logEvent("intrusion", "⚠️ Laser Tripwire Broken!");
    triggered = true;
  } else if (lightValue >= threshold) {
    Blynk.virtualWrite(V0, "✅ Beam Aligned");
    triggered = false;
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, checkIntrusion);
}

void loop() {
  Blynk.run();
  timer.run();
}
