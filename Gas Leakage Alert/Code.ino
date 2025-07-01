#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "GasAlertSystem"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define GAS_SENSOR_PIN 34  // Analog pin (AO of MQ2)
#define BUZZER_PIN 25

BlynkTimer timer;

void checkGas() {
  int gasValue = analogRead(GAS_SENSOR_PIN);
  int gasPercent = map(gasValue, 200, 1000, 0, 100);
  gasPercent = constrain(gasPercent, 0, 100);

  Blynk.virtualWrite(V0, gasPercent);

  if (gasPercent > 60) {
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.logEvent("gas_alert", "⚠️ Gas Leakage Detected!");
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(GAS_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, checkGas);
}

void loop() {
  Blynk.run();
  timer.run();
}
