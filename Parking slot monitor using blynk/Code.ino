#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "ParkingSlotMonitor"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define TRIG_PIN 5
#define ECHO_PIN 18

BlynkTimer timer;
bool lastStatus = false; // false = empty, true = occupied
bool notified = false;

long getDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2; // cm
}

void checkSlot() {
  long distance = getDistance();
  bool isOccupied = distance < 10;

  if (isOccupied != lastStatus) {
    lastStatus = isOccupied;
    if (isOccupied) {
      Blynk.virtualWrite(V0, "🚗 Slot Occupied");
      Blynk.virtualWrite(V1, 255);
      if (!notified) {
        Blynk.logEvent("slot_occupied", "🚗 Slot is now occupied!");
        notified = true;
      }
    } else {
      Blynk.virtualWrite(V0, "🅿️ Slot Free");
      Blynk.virtualWrite(V1, 0);
      notified = false;
    }
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(3000L, checkSlot);
}

void loop() {
  Blynk.run();
  timer.run();
}
