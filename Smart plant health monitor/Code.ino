#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "PlantMonitor"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define SOIL_PIN 34
#define DHTPIN 27
#define RELAY_PIN 26
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;

BLYNK_WRITE(V3) {
  int value = param.asInt();
  digitalWrite(RELAY_PIN, value);
}

void sendSensorData() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  int soilRaw = analogRead(SOIL_PIN);
  int soilPercent = map(soilRaw, 4095, 1200, 0, 100); // adjust range

  Blynk.virtualWrite(V0, soilPercent);
  Blynk.virtualWrite(V1, temp);
  Blynk.virtualWrite(V2, hum);

  // Auto watering
  if (soilPercent < 30) {
    digitalWrite(RELAY_PIN, HIGH);
    Blynk.virtualWrite(V3, 1);
    Blynk.logEvent("auto_watered", "Soil too dry. Auto-watering...");
    delay(5000);
    digitalWrite(RELAY_PIN, LOW);
    Blynk.virtualWrite(V3, 0);
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000L, sendSensorData);
}

void loop() {
  Blynk.run();
  timer.run();
}
