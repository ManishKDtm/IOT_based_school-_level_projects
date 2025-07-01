#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "SmartDustbin"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Servo.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define TRIG_PIN 5
#define ECHO_PIN 18
#define SERVO_PIN 19

#define BIN_HEIGHT_CM 30  // Height of dustbin

Servo lidServo;
BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lidServo.attach(SERVO_PIN);
  lidServo.write(0);  // Lid closed

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, checkFillLevel);
}

void loop() {
  Blynk.run();
  timer.run();

  // Check for hand near lid (e.g., < 15cm)
  long dist = getDistance();
  if (dist < 15) {
    lidServo.write(90); // Open
    delay(3000);
    lidServo.write(0); // Close
  }
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = duration * 0.034 / 2;
  return distance;
}

void checkFillLevel() {
  long dist = getDistance();
  int fillPercent = map(dist, BIN_HEIGHT_CM, 5, 0, 100);
  fillPercent = constrain(fillPercent, 0, 100);
  Blynk.virtualWrite(V0, fillPercent);

  if (fillPercent > 85) {
    Blynk.logEvent("bin_full", "Dustbin is full!");
  }
}
