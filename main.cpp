#include <ESP8266WiFi.h>
#include <iostream>
 
  const char* ap = "ssid";   //your wifi access point name
  const char* pass = "password"; //your wifi password
  int wifiStatus;
  int connectStatus = 0;
    
void setup() {
  pinMode(LED_BUILTIN, OUTPUT), pinMode(2, OUTPUT);
  WiFi.begin(ap, pass);
}
     
void loop() {
  wifiStatus = WiFi.status();
  if(connectStatus == 0) { 
    digitalWrite(LED_BUILTIN, 1), 
      digitalWrite(2, 0);
  } //for inverted change 0 to 1 & 1 to 0
  if(wifiStatus == WL_CONNECTED) { 
    digitalWrite(2, 1), 
      digitalWrite(LED_BUILTIN, 0), 
      connectStatus ++;
  } else if(connectStatus != 0) {
    digitalWrite(LED_BUILTIN, 1), 
      digitalWrite(2, 0); 
    }
  delay(1000);
}
