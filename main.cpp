#include <WiFi.h>
#include <SPI.h>

// WiFi credential constants  
const char* wifiSSID = "nameWifi";      //yr wifi   
const char* wifiPassword = "password";  //yr psw

// Alphabet and digits 
const char* alphabet = "abcdefghijklmnopqrstuvwxyz";
const char* capsLock = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char* digits = "0123456789";

// Pin constants
const int wifiPin = 2;  

// WiFi status
int status = WL_IDLE_STATUS;  

void setup() {
  // Set pin mode
  pinMode(wifiPin, OUTPUT);
  // Connect to WiFi
  connectToWifi();  
}

void loop() {
  // Check WiFi connection status
  if(WiFi.status() != WL_CONNECTED) 
    digitalWrite(wifiPin, LOW); 
  else {
    digitalWrite(wifiPin, HIGH);
    // Search for password
    if(WiFi.status() == WL_CONNECTED) 
      search();
  }
  delay(1000);  
}

// Connect to WiFi function  
void connectToWifi(const char* psw) {
  WiFi.disconnect();
  WiFi.begin(wifiSSID, psw);
  
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifiPin, LOW);
    delay(150);
    digitalWrite(wifiPin, HIGH);
    delay(150);
  }
}

void search() {
  char key[100] = ""; 
  int i = 0;
  
  for (;;) {
    while (strcmp(key, wifiPassword) != 0) {
      key[i] = alphabet[i];
      if (key[i] == wifiPassword[i]) 
        key[i] += alphabet[i];
      else if (key[i] == digits[i] && key[i] == wifiPassword[i]) 
        key[i] += digits[i];  
      else if (key[i] == capsLock[i]) 
        key[i] += capsLock[i];
      else {
        alphabet[i]++;
        digits[i]++;
      }  
      if(key[i] == wifiPassword[i] 
        || key[i] == capsLock[i] 
        || key[i] == digits[i] && key[i] == wifiPassword[i]) {
        i++;
      }
      if (strcmp(key, wifiPassword) == 0) 
        return;
        // break;
    }
    
    if (strcmp(key, wifiPassword) == 0) { 
      WiFi.disconnect();  
      if(WiFi.status() == WL_CONNECTED) 
        status = WiFi.begin(wifiSSID, key);
      else 
        connectToWifi(key);  
    }
  }
}
