#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "XXXXXXXXXXXXX"
#define BLYNK_TEMPLATE_NAME "AIR QUALITY"
#define BLYNK_AUTH_TOKEN "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" //your auth key
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid[] = "WIFI_1";
char pass[] = "22012004";
BlynkTimer timer;
int mq135 = A0; 
int data = 0; 
int thres = 400;
int buzz = 5;
void setup() {
Serial.begin (115200);
Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
timer.setInterval(1000L, getSendData);
}
void loop() {
timer.run(); 
Blynk.run();
Serial.println(data);
if(data > thres)       
{
Serial.println("gas content HIGH");     
digitalWrite(5,HIGH);
Blynk.logEvent("instant_email");
}
else
{
digitalWrite(5,LOW);  
Serial.println("gas content LOW");
}  
delay(500);
}
void getSendData()
{
data = analogRead(mq135); 
data = map(data, 500, 1523, 0, 1000);
Blynk.virtualWrite(V2, data); 
}
