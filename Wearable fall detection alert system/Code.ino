#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "FallAlertSystem"
#define BLYNK_AUTH_TOKEN "Your_Token"

#include <Wire.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <MPU6050.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

MPU6050 mpu;
BlynkTimer timer;

bool fallDetected = false;
bool notified = false;

void detectFall() {
  mpu.update();
  float acc = sqrt(pow(mpu.getAccX(), 2) + pow(mpu.getAccY(), 2) + pow(mpu.getAccZ(), 2));

  if (acc > 2.5 && !notified) {  // Sudden spike in acceleration
    Blynk.logEvent("fall_alert", "⚠️ Fall Detected!");
    Blynk.virtualWrite(V0, "⚠️ Fall Detected!");
    Blynk.virtualWrite(V1, 255);
    notified = true;
  } else if (acc < 1.2) {
    Blynk.virtualWrite(V0, "✅ Normal");
    Blynk.virtualWrite(V1, 0);
    notified = false;
  }
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, detectFall);
}

void loop() {
  Blynk.run();
  timer.run();
}
