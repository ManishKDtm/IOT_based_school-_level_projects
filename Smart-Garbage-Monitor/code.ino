#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Smart Bin"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char ssid[] = "YourWiFi";
char pass[] = "YourPassword";

#define TRIG D5
#define ECHO D6

BlynkTimer timer;

void measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.034 / 2;

  Blynk.virtualWrite(V1, distance);

  if (distance < 10) {
    Blynk.logEvent("bin_full", "⚠️ Dustbin is full! Please empty it.");
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(5000L, measureDistance);
}

void loop() {
  Blynk.run();
  timer.run();
}
