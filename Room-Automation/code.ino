#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "RoomControl"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define DHTPIN 27
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define LIGHT_RELAY 25
#define FAN_RELAY 26

BlynkTimer timer;

BLYNK_WRITE(V0) {
  digitalWrite(LIGHT_RELAY, param.asInt());
}

BLYNK_WRITE(V1) {
  digitalWrite(FAN_RELAY, param.asInt());
}

void sendSensorData() {
  float t = dht.readTemperature();
  if (isnan(t)) return;

  Blynk.virtualWrite(V2, t);

  // Auto fan if temp > 30
  if (t > 30) {
    digitalWrite(FAN_RELAY, HIGH);
    Blynk.logEvent("fan_auto_on", "Auto Fan ON: Temp = " + String(t));
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LIGHT_RELAY, OUTPUT);
  pinMode(FAN_RELAY, OUTPUT);
  digitalWrite(LIGHT_RELAY, LOW);
  digitalWrite(FAN_RELAY, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
