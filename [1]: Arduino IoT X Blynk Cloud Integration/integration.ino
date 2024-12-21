//_____________________________________________________________________________________________ - bl[Y]nk cl[O]ud -  
// Includes necessary libraries and defines credentials for the Blynk Cloud service
#define BLYNK_TEMPLATE_ID "YOUR_BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
                                      // Define Wi-Fi credentials for the Blynk Cloud connection
char ssid[] = "WiFi_SSID";             // yes, we have to reassign our WiFi SSID and password for blynk cloud
char pass[] = "WiFi_PASS";             // Apologies for the messy codes. I've moved on to other projects and haven’t had the chance to optimize it yet.
//_____________________________________________________________________________________________ - ard[U]ino cl[O]ud -  
// Includes necessary libraries for the Arduino Cloud service
#include "thingProperties.h"

void setup() 
{
  Serial.begin(115200);                                         // Don't forget to change it to whatever baud rate you need
  delay(1500);                                                  // Mandatory delay to avoid conflicts during startup
  
  // Initialize Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);                    // Blynk cloud will be connected first
  // Initialize Arduino IoT Cloud
  initProperties();                                             // After that Arduino IoT 's turn                 
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  // Debugging setup
  setDebugMessageLevel(2);                                      // Following lines are strictly for debugging
  ArduinoCloud.printDebugInfo();
}

void loop() 
{
  Blynk.run();                                                  // Sync with Blynk Cloud
  ArduinoCloud.update();                                        // Sync with Arduino Cloud
}