#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";

const String IFTTT_URL = "https://maker.ifttt.com/trigger/health_data/with/key/YOUR_IFTTT_KEY";

#define TEMP_PIN A0
#define PULSE_PIN D1

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
}

void loop() {
  float tempC = analogRead(TEMP_PIN) * 0.488; // For LM35
  int pulseValue = analogRead(PULSE_PIN);

  // Send to IFTTT
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = IFTTT_URL + "?value1=" + String(tempC) + "&value2=" + String(pulseValue);
    http.begin(url);
    int httpCode = http.GET();
    http.end();
    Serial.println("Logged: Temp=" + String(tempC) + "  Pulse=" + String(pulseValue));
  }

  delay(10000); // Log every 10 seconds
}
