
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
int received;// received value will be stored in this variable
char receivedChar;// received value will be stored as CHAR in this variable

const char turn1ON ='a';
const char turn1OFF ='b';
const char turn2ON ='c';
const char turn2OFF ='d';
const char turn3ON ='e';
const char turn3OFF ='f';
const char turnallon ='g';
const char turnalloff ='h';

const int LEDpin1 = 21;
const int LEDpin2 = 22;
const int LEDpin3 = 23;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_AUTOMATION"); //Bluetooth device name
  Serial.println("You can pair it with bluetooth!");
  pinMode(LEDpin1, OUTPUT);
 pinMode(LEDpin2, OUTPUT);
 pinMode(LEDpin3, OUTPUT);
}

void loop() {
    receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    SerialBT.print("Received:");// write on BT app
    SerialBT.println(receivedChar);// write on BT app      
    Serial.print ("Received:");//print on serial monitor
    Serial.println(receivedChar);//print on serial monitor    
    //SerialBT.println(receivedChar);//print on the app    
    //SerialBT.write(receivedChar); //print on serial monitor
    if(receivedChar == turn1ON)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpin1, HIGH);// turn the LED ON
       
    }
    if(receivedChar == turn1OFF)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin1, LOW);// turn the LED off 
    }    
        if(receivedChar == turn2ON)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
      digitalWrite(LEDpin2, HIGH);// turn the LED off 
    } 
        if(receivedChar == turn2OFF)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin2, LOW);// turn the LED off 
    }       
         if(receivedChar == turn3ON)
    {
     SerialBT.println("LED ON:");// write on BT app
     Serial.println("LED ON:");//write on serial monitor
      digitalWrite(LEDpin3, HIGH);// turn the LED off 
    }  
        if(receivedChar == turn3OFF)
    {
     SerialBT.println("LED OFF:");// write on BT app
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin3, LOW);// turn the LED off 
    }  
        if(receivedChar == turnallon)
    {
     SerialBT.println("LED ON ALL:");// write on BT app
     Serial.println("LED ON ALL:");//write on serial monitor
      digitalWrite(LEDpin1,HIGH);
     digitalWrite(LEDpin2,HIGH);
    digitalWrite(LEDpin3,HIGH);
    }      
        if(receivedChar == turnalloff)
    {
     SerialBT.println("LED OFF ALL:");// write on BT app
     Serial.println("LED OFF ALL:");//write on serial monitor
      digitalWrite(LEDpin1,LOW);
     digitalWrite(LEDpin2,LOW);
    digitalWrite(LEDpin3,LOW);
    }      

  

  }
  delay(20);
}