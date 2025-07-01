#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

const int soilPin = A0;
const int relayPin = D1;

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Pump off

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi connected. IP: " + WiFi.localIP().toString());

  server.on("/", []() {
    int soil = analogRead(soilPin);
    String status = (soil < 400) ? "ON" : "OFF";
    String html = "<h2>🌿 Smart Irrigation System</h2>";
    html += "<p>Soil Moisture: " + String(soil) + "</p>";
    html += "<p>Pump Status: " + status + "</p>";
    server.send(200, "text/html", html);
  });

  server.begin();
}

void loop() {
  int moisture = analogRead(soilPin);
  if (moisture < 400) {
    digitalWrite(relayPin, LOW); // Pump ON
  } else {
    digitalWrite(relayPin, HIGH); // Pump OFF
  }
  server.handleClient();
  delay(1000);
}
