#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your Wi-Fi credentials
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

// Your Blynk authentication token (from Blynk app)
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Relay pins (D1, D2 on NodeMCU)
#define RELAY1 D1  // Light
#define RELAY2 D2  // Fan

void setup() {
  // Debug serial
  Serial.begin(9600);
  
  // Set relay pins as output
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Relays OFF initially
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

// Virtual pin control (from app)
BLYNK_WRITE(V1) {
  int state = param.asInt(); // 0 or 1
  digitalWrite(RELAY1, state ? LOW : HIGH); // Active LOW relay
}

BLYNK_WRITE(V2) {
  int state = param.asInt();
  digitalWrite(RELAY2, state ? LOW : HIGH);
}
