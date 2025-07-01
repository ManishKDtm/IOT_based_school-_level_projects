#include <Keypad.h>
#include <Servo.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {14, 27, 26, 25};
byte colPins[COLS] = {33, 32, 21, 22};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

Servo lockServo;
const int servoPin = 18;
String inputPassword = "";
String correctPassword = "1234";

void setup() {
  Serial.begin(115200);
  lockServo.attach(servoPin);
  lockServo.write(0); // locked position
  Serial.println("Smart Lock Ready. Enter 4-digit code:");
}

void loop() {
  char key = keypad.getKey();

  if (key != NO_KEY) {
    Serial.print(key);
    inputPassword += key;

    if (inputPassword.length() == 4) {
      if (inputPassword == correctPassword) {
        Serial.println("\n✅ Access Granted");
        lockServo.write(90); // Unlock
        delay(5000);
        lockServo.write(0); // Lock back
        Serial.println("🔒 Locked");
      } else {
        Serial.println("\n❌ Access Denied");
      }
      inputPassword = "";
    }
  }
}
