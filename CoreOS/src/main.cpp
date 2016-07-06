#include <ESP8266WiFi.h>
#include <sha256.h>
#include "config.h"
#include <ESPtv.h>

void setup()
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    ESPtv corePtv;
    
    HTTPClient client;
    if(corePtv.HealthCheck(client) == true)
    {
       Serial.printf("All done!");
    }
}

void loop()
{
   // TBD
}
