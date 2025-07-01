#include <Wire.h>
#include <Adafruit_APDS9960.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "GestureControl"
#define BLYNK_AUTH_TOKEN "Your_Token"

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

Adafruit_APDS9960 apds;
#define DEVICE_PIN 25

void setup() {
  Serial.begin(115200);
  pinMode(DEVICE_PIN, OUTPUT);
  digitalWrite(DEVICE_PIN, LOW);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Wire.begin();

  if (!apds.begin()) {
    Serial.println("APDS9960 not detected!");
    while (1);
  }

  apds.enableGesture(true);
}

void loop() {
  Blynk.run();

  if (apds.gestureAvailable()) {
    int gesture = apds.readGesture();

    switch (gesture) {
      case APDS9960_LEFT:
        digitalWrite(DEVICE_PIN, LOW);
        Blynk.virtualWrite(V0, "Device OFF");
        break;
      case APDS9960_RIGHT:
        digitalWrite(DEVICE_PIN, HIGH);
        Blynk.virtualWrite(V0, "Device ON");
        break;
    }
  }
}
