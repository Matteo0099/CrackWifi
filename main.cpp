// WiFi credential constants 
const char* wifiSSID = "ssid";  
const char* wifiPassword = "password";

// Pin constants
const int ledPin = LED_BUILTIN;
const int wifiPin = 2;

// Pin state constants
const int ledOn = HIGH;
const int ledOff = LOW;
const int wifiConnected = HIGH; 
const int wifiDisconnected = LOW;

// WiFi connection status variable 
int wifiConnectionStatus = 0;

void setup() {
  // Set pin modes
  pinMode(ledPin, OUTPUT);
  pinMode(wifiPin, OUTPUT);
  
  // Connect to WiFi
  connectToWifi(); 
}

void loop() {
  // Check WiFi connection status
  if(wifiConnectionStatus == 0) {
    digitalWrite(ledPin, ledOn);
    digitalWrite(wifiPin, wifiDisconnected); 
  } 
  
  else if(wifiConnectionStatus != 0) {
    digitalWrite(ledPin, ledOff);
    digitalWrite(wifiPin, wifiConnected);
  }
  
  delay(1000);  
}

// Connect to WiFi function 
void connectToWifi() {
  WiFi.begin(wifiSSID, wifiPassword);
  
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledPin, ledOn);
    digitalWrite(wifiPin, wifiDisconnected);
    delay(1000);
  }
  
  digitalWrite(ledPin, ledOff);
  digitalWrite(wifiPin, wifiConnected);
  wifiConnectionStatus++;
}
