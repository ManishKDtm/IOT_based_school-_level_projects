#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YourWiFi";
const char* password = "YourPassword";

#define FLAME_SENSOR_PIN 34  // Digital input
#define BUZZER_PIN 26

WebServer server(80);

void handleRoot() {
  int flameDetected = digitalRead(FLAME_SENSOR_PIN);
  String html = "<html><head><meta http-equiv='refresh' content='3'/>";
  html += "<style>body{font-family:Arial;text-align:center;padding-top:40px;}</style></head><body>";

  if (flameDetected == LOW) {
    html += "<h1 style='color:red;'>🔥 FIRE DETECTED!</h1>";
  } else {
    html += "<h1 style='color:green;'>✅ Safe</h1>";
  }

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi Connected. IP: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
}

void loop() {
  server.handleClient();

  if (digitalRead(FLAME_SENSOR_PIN) == LOW) {
    digitalWrite(BUZZER_PIN, HIGH); // Fire detected
  } else {
    digitalWrite(BUZZER_PIN, LOW);  // Safe
  }

  delay(100);
}
