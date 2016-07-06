#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
//#include <ArduinoJson.h>
#include "sha1.h"
#include "ESPtv.h"
#include "PtvApiKey.h"



ESPtv::ESPtv()
{

}

String ESPtv::signatureGenerator(String url, String key)
{
    String hashStr = "";
    String fullStr = "";
    uint8_t *hash;
    Sha1.initHmac(PTV_API_KEY, 36);
    Sha1.print(url);
    hash = Sha1.resultHmac();

    for(int i = 0; i < sizeof(hash); i++)
    {
        hashStr.concat(String(hash[i], HEX));
    }

    hashStr.toUpperCase();
    fullStr = "&signature=" + hashStr;
    return fullStr;
}

bool ESPtv::HealthCheck(const HTTPClient& httpClient)
{
    String httpAddr = PTV_API_BASIC_ADDR + "/healthcheck?timestamp=" + PTV_FAKE_TIMESTAMP + "&devid=" + PTV_API_UID;
    String signInfo = signatureGenerator(httpAddr, PTV_API_KEY);
    httpClient.begin(httpAddr+signInfo);
    int httpStatus = httpClient.GET();
    if( == HTTP_CODE_OK)
    {
        printf("[HTTP] GET OK\n");
        printf("\n\nResult:\n"); printf(httpClient.getString());
    }
    else
    {
        printf("[HTTP] GET Failed: " + httpStatus);
    }

}
