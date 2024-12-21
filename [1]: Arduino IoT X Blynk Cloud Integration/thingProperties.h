#ifndef THINGPROPERTIES_H
#define THINGPROPERTIES_H 

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// These are all credentials from arduino part of the project         || You can literally copy everything from thingProperties.h, paste it here and configure the necessary informations
// You can either search individually or get it all at
// Things > [Your Device Name] > Sketch     with the same names

// These credentials are specific to the Arduino Cloud setup
const char DEVICE_LOGIN_NAME[]  = "YOUR_DEVICE_LOGIN_NAME";                 // You can find this one under a section from 
                                                                                          // Things > [Your Device Name] > Setup > Associated Device > ID (just copy it)

const char DEVICE_KEY[]         = "YOUR_DEVICE_KEY";                            // Secret device password (You can find it from pdf you downloaded)
const char SSID[]               = "WiFi_SSID";                                             // Network SSID (name)
const char PASS[]               = "WiFi_PASS";                                             // Network password (use for WPA, or use as key for WEP)

// Initialize Arduino Cloud properties
void initProperties()                                     // Function responsible for connecting our microcontroller to the cloud server               
{
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);    // Define connection handler for Arduino Cloud

// For simplicity, this tutorial focuses only on getting both cloud services working on the same microcontroller.
// You'll need to declare, define, and manage Arduino-related functions and variables separately.

#endif