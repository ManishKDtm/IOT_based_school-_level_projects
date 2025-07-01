#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";

#define CURRENT_PIN 34

WebServer server(80);

float readCurrent() {
  int raw = analogRead(CURRENT_PIN);
  float voltage = (raw * 3.3) / 4095.0;
  float current = (voltage - 2.5) / 0.185; // For ACS712 5A version
  return current;
}

void handleRoot() {
  float current = readCurrent();
  float voltage = 230.0; // Assume fixed mains
  float power = current * voltage;

  String html = "<html><head><meta http-equiv='refresh' content='3'/><style>body{font-family:sans-serif;text-align:center;}</style></head><body>";
  html += "<h2>🔌 IoT Energy Monitor</h2>";
  html += "<p><b>Current:</b> " + String(current, 2) + " A</p>";
  html += "<p><b>Voltage:</b> 230 V (assumed)</p>";
  html += "<p><b>Power:</b> " + String(power, 2) + " W</p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(CURRENT_PIN, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi connected. IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();
}
