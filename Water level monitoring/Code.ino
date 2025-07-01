#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "WaterLevelMonitor"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define TRIG_PIN 5
#define ECHO_PIN 18
#define TANK_HEIGHT_CM 40

BlynkTimer timer;

long getDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void checkWaterLevel() {
  long dist = getDistance();
  int level = map(dist, TANK_HEIGHT_CM, 5, 0, 100);
  level = constrain(level, 0, 100);

  Blynk.virtualWrite(V0, level);

  if (level > 90) {
    Blynk.logEvent("water_full", "💧 Tank is full!");
  } else if (level < 15) {
    Blynk.logEvent("water_low", "⚠️ Tank is low!");
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000L, checkWaterLevel);
}

void loop() {
  Blynk.run();
  timer.run();
}
