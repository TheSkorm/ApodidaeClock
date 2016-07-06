/*
    Public Transport Victoria (PTV) Real-time API parsing library for Arduino (ESP platform)
    By Jackson Ming Hu @ RMIT University, July 2016.
*/

#ifndef ESPtv_h
#define ESPtv_h

#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* ******************************* *
    PTV API related definiation
* ******************************** */
#define PTV_API_BASIC_ADDR "http://timetableapi.ptv.vic.gov.au/v2"
#define PTV_FAKE_TIMESTAMP "2014-02-28T05:24:25Z" // For debugging only. Change this to a recent time before compiling.

/* ******************************* *
    ESPtv class definiation
* ******************************** */
class ESPtv
{
  public:
    ESPtv();
    bool HealthCheck(const HTTPClient& httpClient);
    enum TransportType
    {
      Train,
      Tram,
      Bus,
      Vline
    };

    int ArrivalQuery(String route, enum TransportType);

  private:
    String signatureGenerator(String url, String key);
    String getQueryAddr(void);
};

#endif
