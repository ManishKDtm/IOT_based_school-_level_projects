#define BLYNK_TEMPLATE_ID "Your_Template_ID"
#define BLYNK_TEMPLATE_NAME "Smart Door Lock"
#define BLYNK_AUTH_TOKEN "Your_Auth_Token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Keypad.h>

char ssid[] = "YourSSID";
char pass[] = "YourPassword";

#define RELAY_PIN D1

char generatedOTP[5] = "1234";
char enteredOTP[5];
byte index = 0;

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {D2, D3, D4, D5};
byte colPins[COLS] = {D6, D7, D8, D0};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
BlynkTimer timer;

BLYNK_WRITE(V0) {
  int otp = random(1000, 9999);
  snprintf(generatedOTP, 5, "%d", otp);
  Blynk.logEvent("otp_generated", "Your OTP: " + String(generatedOTP));
}

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Locked

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(500L, checkKeypad);
}

void checkKeypad() {
  char key = keypad.getKey();
  if (key) {
    Serial.print(key);
    if (key == '#') {
      enteredOTP[index] = '\0';
      if (strcmp(enteredOTP, generatedOTP) == 0) {
        Blynk.logEvent("otp_success", "✅ Door Unlocked");
        digitalWrite(RELAY_PIN, LOW);
        delay(5000);
        digitalWrite(RELAY_PIN, HIGH);
      } else {
        Blynk.logEvent("otp_fail", "❌ Wrong OTP");
      }
      index = 0;
    } else if (key >= '0' && key <= '9' && index < 4) {
      enteredOTP[index++] = key;
    }
  }
}

void loop() {
  Blynk.run();
  timer.run();
}
